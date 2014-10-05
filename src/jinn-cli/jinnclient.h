#ifndef JINNCLIENT_H
#define JINNCLIENT_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QCoreApplication>

class JinnClient : public QObject
{
    Q_OBJECT
public:
    explicit JinnClient(int port, QObject *parent = 0);
    void requestPOST(QByteArray data);

private slots:
    void response(QNetworkReply* reply);
private:
    int port;
    QString url;
    QNetworkAccessManager*  mgr;
    QCoreApplication* app;

};

#endif // JINNCLIENT_H
