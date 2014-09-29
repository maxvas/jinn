#include "contentprocessor.h"

ContentProcessor::ContentProcessor() :
    RequestProcessor()
{
    responseParser = new QHttpResponseParser();
}

QString ContentProcessor::settingsName()
{
    return "proxy";
}

bool ContentProcessor::checkUrl(QString url, QJS &settings)
{
    if (settings.size()==0)
        return false;
    for (QJS::iterator i=settings.begin(); i!=settings.end(); ++i)
    {
        QJS &proxy = *i;
        QString proxyUrl = proxy["url"].toString();
        if (proxyUrl=="")
            continue;
        if (url.startsWith(proxyUrl))
        {
            urlPath = url.mid(proxyUrl.length());
            if (!urlPath.startsWith('/'))
                urlPath = "/"+urlPath;
            return true;
        }
    }
    return false;
}

void ContentProcessor::headerRecieved(QHttpManipulator *http, QJS &settings)
{
    http->echo("Здесь будет прокси<br>");
    http->echo(urlPath);
}
