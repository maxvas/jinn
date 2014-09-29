#include "contentprocessor.h"
#include <QTime>
#include <QFile>

bool ContentProcessor::checkUrl(QString url, QJS &settings)
{
    for(int i=0;i<settings["folders"].size();i++){
        QString path=settings["foolders"][i].toString()+url;
        int ad=3;
        QFile::exists()
    }

    QStringList urls;
    urls.append("/");
    urls.append("/time");
    return urls.contains(url);
}

QString ContentProcessor::settingsName()
{
    return "static";
}

void ContentProcessor::headerRecieved(QHttpManipulator *http, QJS &settings)
{
    if (http->request()->path()=="/")
        http->echo("Тестовый модуль");
    if (http->request()->path()=="/time")
        http->echo(QTime::currentTime().toString());
}
