#include "qwebercontentprocessor.h"
#include <QTime>

bool QWeberContentProcessor::checkUrl(QString url, QJS &settings, QWebProject &project)
{
    (void)settings;
    (void)project;
    QStringList urls;
    urls.append("/qweber");
    return urls.contains(url);
}

void QWeberContentProcessor::headerRecieved(QHttpManipulator *http, QJS &settings)
{
    (void)settings;
    if (http->request()->path()=="/qweber")
        http->echo("Здесь будет QWeber");
}
