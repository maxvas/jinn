#include "testprocessor.h"
#include <QTime>

bool TestProcessor::checkUrl(QString url, QWebProject *settings)
{
    QStringList urls;
    urls.append("/");
    urls.append("/time");
    return urls.contains(url);
}

void TestProcessor::headerRecieved(QHttpManipulator *http, QJS &settings)
{
    if (http->request()->path()=="/")
        http->echo("Тестовый модуль");
    if (http->request()->path()=="/time")
        http->echo(QTime::currentTime().toString());
}