#ifndef PROXYPROCESSOR_H
#define PROXYPROCESSOR_H

#include <requestprocessor.h>
#include <qhttpresponseparser.h>
#include <QJS>
#include <QTcpSocket>

class ContentProcessor : public RequestProcessor
{
public:
    explicit ContentProcessor();
    QString settingsName();
    bool checkUrl(QString url, QJS &settings);
    void headerRecieved(QHttpManipulator *http, QJS &settings);
//    void bodyDataBlockRecieved(QByteArray data, QJS &settings);
//    void bodyRecieved(QHttpManipulator *http, QJS &settings);
//    void clear();
private:
    QHttpResponseParser *responseParser;
    QTcpSocket *socket;
    QString urlPath;
};

#endif // PROXYPROCESSOR_H
