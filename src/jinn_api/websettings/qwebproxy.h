#ifndef QWEBPROXY_H
#define QWEBPROXY_H

#include <QJSMapping>

class QWebProxy : public QJSMapping
{
    Q_OBJECT
public:
    QJS_MAPPING_QSTRING("url", url, setUrl)
    QJS_MAPPING_QSTRING("remoteHost", remoteHost, setRemoteHost)
    QJS_MAPPING_INT("remotePort", remotePort, setRemotePort)
    QJS_MAPPING_QSTRING("remotePath", remotePath, setRemotePath)

signals:

public slots:

};

#endif // QWEBPROXY_H
