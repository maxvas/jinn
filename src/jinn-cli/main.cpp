#include "jinnclient.h"
#include "QCoreApplication"
#include <iostream>
#include <QDebug>

void help(){
    using namespace std;
    cout<<"the help will be here"<<endl;
    cout.flush();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc,argv);
    int port =3444; //default port
    QStringList argList=a.arguments();
    argList.removeFirst();
    if(argList.size()>0){
        if(argList[0]=="-p"){
            argList.removeFirst();
            if(argList.size()>0){
                port=argList[0].toInt();
            }
            argList.removeFirst();
        }
    }
    if(argList.size()>0){
        JinnClient *client = new JinnClient(&a);
        QByteArray data;
        foreach (QString arg, argList) {
            data.append(arg);
            data.append("\n");
        }
        client->requestPOST(port,data);
    }
    return a.exec();
}
