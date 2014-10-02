#include "managerprocessor.h"
#include <QTime>

bool ManagerProcessor::checkUrl(QString url, QJS &settings, QWebProject &project)
{
    (void)settings;
    (void)project;
    QStringList urls;
    urls.append("/");
    return true;
    return urls.contains(url);
}

void ManagerProcessor::bodyRecieved(QHttpManipulator *http, QJS &settings)
{
    (void)settings;
    QByteArray data =http->request()->bodyData();
    http->echo("сам ты "+QString(data));
}
