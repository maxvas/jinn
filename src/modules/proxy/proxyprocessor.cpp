#include "proxyprocessor.h"

ProxyProcessor::ProxyProcessor() :
    RequestProcessor()
{
    responseParser = new QHttpResponseParser();
}

QString ProxyProcessor::settingsName()
{
    return "proxy";
}

bool ProxyProcessor::checkUrl(QString url, QJS &settings, QWebProject &project)
{
    (void)project;
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

void ProxyProcessor::headerRecieved(QHttpManipulator *http, QJS &settings)
{
    (void)settings;
    http->echo("Здесь будет прокси");
    //http->echo(urlPath);
}
