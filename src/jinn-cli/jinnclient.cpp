#include "jinnclient.h"
#include <iostream>

JinnClient::JinnClient(int port,QObject *parent) :
    QObject(parent), port(port),mgr(new QNetworkAccessManager(this)),app(app)
{
    url = "http://localhost:"+QString::number(port)+"/";
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(response(QNetworkReply*)));
}

void JinnClient::requestPOST(QByteArray data)
{
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "text/xml");
    mgr->post(request,data);
}

void JinnClient::response(QNetworkReply *reply)
{
    using namespace std;
    QNetworkReply::NetworkError error = reply->error();
    if(error!=QNetworkReply::NoError){
        cout<<"can't connect to jinn on port "+ QString::number(port).toStdString() + ":\n";
        cout<<reply->errorString().toStdString()<<endl;
    }
    QByteArray data = reply->readAll();
    cout<<QString(data).toStdString()<<endl;
    cout.flush();
    QCoreApplication::exit();
}
