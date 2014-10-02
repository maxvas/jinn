#ifndef QHTTPREQUESTPARSER_H
#define QHTTPREQUESTPARSER_H

#include <QObject>
#include <QStringList>
#include "qhttprequest.h"
#include "qhttpresponse.h"
#include "qhttpparser_global.h"

class QHttpRequest;
class QHttpResponse;
class QHTTPPARSERSHARED_EXPORT QHttpRequestParser : public QObject
{
    Q_OBJECT
public:
    explicit QHttpRequestParser(QObject *parent = 0);
    QHttpRequest *request();
    QHttpResponse *response();
    ~QHttpRequestParser();
    friend class QHttpRequest;
    void putData(QByteArray newData);
//    void finish();
    void free();

private:
    QHttpRequest* m_req;
    QHttpResponse* m_resp;
    QByteArray m_data;
    bool isHeaderRecived;
    bool isBodyRecived;
    bool isFinished;

signals:
    void headerRecieved();
    void bodyRecieved();
    void bodyDataBlockRecieved(QByteArray data);
    void beforeSendHeaders();
    void sendData(QByteArray data);
    void finished();

public slots:

private slots:
    void onParserFinished();

};

#endif // QHTTPREQUESTPARSER_H
