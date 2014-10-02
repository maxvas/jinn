#include "jinnclient.h"
#include <iostream>

JinnClient::JinnClient(QObject *parent) :
    QObject(parent), mgr(new QNetworkAccessManager(this))
{
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(response(QNetworkReply*)));
}

void JinnClient::requestPOST(int port, QByteArray data)
{
    QString url = "http://localhost:"+QString::number(port)+"/";
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "text/xml");
    mgr->post(request,data);
}

void JinnClient::requestGET(int port, QString paramString="")
{
    QString url = "http://localhost:"+QString::number(port)+"/?"+paramString;
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "text/xml");
    mgr->get(request);
}

void JinnClient::response(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    using namespace std;
    cout<<QString(data).toStdString()<<endl;
    cout.flush();
}
