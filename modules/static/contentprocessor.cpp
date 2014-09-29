#include "contentprocessor.h"
#include <QTime>
#include <QFile>

bool ContentProcessor::checkUrl(QString url, QJS &settings)
{
    for(int i=0;i<settings["folders"].size();i++){
        QString path=settings["folders"][i].toString()+url;
        if(QFile::exists(path))
            return true;
    }
    return false;
}

QString ContentProcessor::settingsName()
{
    return "static";
}

void ContentProcessor::headerRecieved(QHttpManipulator *http, QJS &settings)
{

    QString url = http->request()->path();
    for(int i=0;i<settings["folders"].size();i++){
        QString path=settings["folders"][i].toString()+url;
        if(QFile::exists(path)){
            return;
        }
    }
}
