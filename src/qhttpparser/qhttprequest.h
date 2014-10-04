#ifndef QHTTPREQUEST_H
#define QHTTPREQUEST_H

//#include <QObject>
#include <QHash>
#include "qhttprequestparser.h"
#include "qhttpheaderslist.h"
#include "qhttpparser_global.h"

class QHttpRequestParser;
class QHTTPPARSERSHARED_EXPORT QHttpRequest : public QObject
{
    Q_OBJECT
    friend class QHttpRequestParser;
public:
    explicit QHttpRequest(QObject *parent = 0);
    QString method();
    QString path();
    QString host();
    qint64 contentLength();
    QByteArray headerData();
    QByteArray bodyData();
    QHttpHeadersList *headers();

private:
    QString m_method;
    QString m_path;
    QHttpHeadersList *m_headers;
    QByteArray m_headerData;
    QByteArray m_bodyData;
    qint64 m_contentLen;
    void parseHeader();
    void free();

signals:

public slots:


};

#endif // QHTTPREQUEST_H
