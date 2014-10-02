#include "staticprocessor.h"
#include <QTime>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QFileInfo>

StaticProcessor::StaticProcessor()
{
}

bool StaticProcessor::init(QWebGlobalData *global)
{
    suffixes.append("");
    suffixes.append("index.html");
    suffixes.append("index.htm");
    suffixes.append(".html");
    suffixes.append(".htm");
    suffixes.append(".php");
    suffixes.append("/index.html");
    suffixes.append("/index.htm");
    suffixes.append("/index.php");
    //read MimeTypes
    QString settingsDir = global->dir();
    QString mimeConfig = settingsDir+"/"+StaticProcessor::settingsName()+"/mime.types";
    if (!QFile::exists(mimeConfig))
    {
        qDebug()<<"mime.types expected";
        return false;
    }
    loadMimeTypes(mimeConfig);
    return true;
}

bool StaticProcessor::checkUrl(QString url, QJS &settings, QWebProject &project)
{
    (void)project;
    if (url.indexOf("?")>0)
        url = url.section("?", 0, 0);
    if (!url.startsWith("/"))
        url = "/" + url;
    for(int i=0;i<settings["folders"].size();i++){
        foreach (QString suf, suffixes)
        {
            QString path=project.dir().absolutePath()+"/"+settings["folders"][i].toString()+url+suf;

            if(QFile::exists(path))
            {
                QFileInfo info(path);
                if (!info.isDir())
                {
                    filePath = path;
                    return true;
                }

            }
        }
    }
    return false;
}

QString StaticProcessor::settingsName()
{
    return "static";
}

void StaticProcessor::headerRecieved(QHttpManipulator *http, QJS &settings)
{
    (void)settings;
    sendFile(http);
}

void StaticProcessor::loadMimeTypes(QString path)
{
    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!file.atEnd())
        {
            QString line = file.readLine();
            if (line.startsWith("#"))
                continue;
            QStringList ls = line.split(QRegExp("[ \t]"));
            if (ls.length()>1)
            {
                for (int i=1; i<ls.length(); i++)
                {
                    QString key = ls[i];
                    QString value = ls[0];
                    key = key.trimmed();
                    value = value.trimmed();
                    if (key!="")
                        mimeTypes[key] = value;
                }
            }
        }
        file.close();
    }else
    {
        QString error = "Can't read mime-types file:'"+path+"'";
        qDebug()<<error.toStdString().c_str();
    }
}

QString getExt(QString path)
{
    if (path.indexOf(".")<=0)
        return "";
    return path.right(path.length()-path.lastIndexOf(".")-1);
}

void StaticProcessor::sendFile(QHttpManipulator *http)
{
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly))
    {
        QString ext = getExt(filePath);
        if (mimeTypes.contains(ext))
            http->response()->headers()->set("Content-Type", mimeTypes[ext]);
        QByteArray arr;
        arr = file.readAll();
        http->responseCode(QHttpStatusCodes::OK);

        http->response()->echo(arr);
        return;
    }
    //Если файлов таких нет, то говорим что страница не найдена:
    http->responseCode(QHttpStatusCodes::NotFound);
}
