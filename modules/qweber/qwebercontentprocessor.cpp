#include "qwebercontentprocessor.h"
#include <QTime>

bool QWeberContentProcessor::checkUrl(QString url, QJS &settings)
{
    QStringList urls;
    urls.append("/");
    urls.append("/time");
    return urls.contains(url);
}

void QWeberContentProcessor::headerRecieved(QHttpManipulator *http, QJS &settings)
{
    if (http->request()->path()=="/")
        http->echo("Тестовый модуль");
    if (http->request()->path()=="/time")
        http->echo(QTime::currentTime().toString());
}
