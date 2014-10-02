#ifndef QHTTPRESPONSEPARSER_H
#define QHTTPRESPONSEPARSER_H

#include <QObject>
#include "QHttpRequest"
#include "QHttpResponse"
#include "qhttpparser_global.h"

class QHttpRequest;
class QHttpResponse;

class QHTTPPARSERSHARED_EXPORT QHttpResponseParser : public QObject
{
    Q_OBJECT
public:
    void putData(QByteArray newData);
    void finish();
    void free();

private:
    QHttpRequest* m_req;
    QHttpResponse* m_resp;
    QByteArray m_data;
    bool isHeaderRecived;
    bool isBodyRecived;

signals:
    void headerRecieved();
    void bodyRecieved();
    void bodyDataBlockRecieved(QByteArray data);
    void beforeSendHeaders();
    void sendData(QByteArray data);
    void finished();

signals:

public slots:

};

#endif // QHTTPRESPONSEPARSER_H
