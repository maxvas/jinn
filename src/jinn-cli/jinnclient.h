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
    explicit JinnClient(QCoreApplication* app,QObject *parent = 0);
    void requestPOST(int port, QByteArray data);
    void requestGET(int port, QString paramString);

private slots:
    void response(QNetworkReply* reply);
private:
    QNetworkAccessManager*  mgr;
    QCoreApplication* app;

};

#endif // JINNCLIENT_H
