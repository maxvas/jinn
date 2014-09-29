#ifndef QWEBPROCESSOR_H
#define QWEBPROCESSOR_H

#include <QObject>
#include <QWebGlobalData>
#include <QTcpSocket>
#include <QHttpRequestParser>
#include <qwebresourseprovider.h>
#include "jinn_api_global.h"

class JINN_APISHARED_EXPORT QWebProcessor : public QObject
{
    Q_OBJECT
public:
    explicit QWebProcessor(QObject *parent, QWebGlobalData *global);
    bool newConnection(qint16 port, qintptr socketDescriptor);

private:
    QTcpSocket* socket;
    QHttpRequestParser* parser;
    QWebResourseProvider* rp;
    qint16 port;

signals:
    void finished();

private slots:
    void socketRead();
    void socketWrite(QByteArray data);
    void onParserFinished();
    void onParserHeaderRecieved();
    void onSocketDisconnected();

public slots:

};

#endif // QWEBPROCESSOR_H
