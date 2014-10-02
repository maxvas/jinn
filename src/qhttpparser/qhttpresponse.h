#ifndef QHTTPRESPONSE_H
#define QHTTPRESPONSE_H

#include <QObject>
#include <QVector>
#include <QHash>
#include <QPair>
#include "QHttpStatusCodes"
#include "QHttpRequestParser"
#include "QHttpHeadersList"
#include "qhttpparser_global.h"
#include "qhttpresponseparser.h"

class QHTTPPARSERSHARED_EXPORT QHttpResponse : public QObject
{
    Q_OBJECT
    friend class QHttpRequestParser;
    friend class QHttpManipulator;
public:
    explicit QHttpResponse(QObject *parent = 0);
    ~QHttpResponse();
    friend class QHttpResponseParser;
    QHttpHeadersList *headers();
    bool headersSent();
    void setStatusCode(int code);
    void echo(QByteArray data);
    void echo(QString string);
    void sendRawData(QByteArray data);
    QString protocol();
    int statusCode();
    QString statusMessage();

private:
    QHttpHeadersList *m_headers;
    QString firstLine;
    QHash<qint32, QString> m_statusCodes;
    bool m_headersSent;
    void sendHeaders();
    void finishAndSendHeaders();
    void finish();
    QByteArray m_headerData;
    QByteArray m_bodyData;
    qint64 m_contentLen;
    void parseHeader();
    void free();
    QString m_protocol;
    int m_statusCode;
    QString m_statusMessage;

signals:
    void beforeSendHeaders();
    void sendData(QByteArray data);
    void finished();


public slots:

};

#endif // QHTTPRESPONSE_H
