#include "managerprocessor.h"
#include <QTime>

bool ManagerProcessor::checkUrl(QString url, QWebProject *settings, QWebProject &project)
{
    (void)settings;
    (void)project;
    QStringList urls;
    urls.append("/");
    urls.append("/time");
    return urls.contains(url);
}

void ManagerProcessor::headerRecieved(QHttpManipulator *http, QJS &settings)
{
    (void)settings;
    if (http->request()->path()=="/")
        http->echo("Тестовый модуль\n");
    if (http->request()->path()=="/time")
        http->echo(QTime::currentTime().toString());
}

void ManagerProcessor::bodyRecieved(QHttpManipulator *http, QJS &settings)
{
    (void)settings;
    QByteArray data =http->request()->bodyData();
    http->echo("сам ты "+QString(data));
}
