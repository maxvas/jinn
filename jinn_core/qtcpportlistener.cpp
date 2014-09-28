#include "qtcpportlistener.h"

QTcpPortListener::QTcpPortListener(QObject *parent) :
    QTcpServer(parent)
{
}

void QTcpPortListener::incomingConnection(qintptr socketDescriptor)
{
    emit newConnection(this->serverPort(), socketDescriptor);
}
