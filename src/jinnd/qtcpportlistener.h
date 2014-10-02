#ifndef QTCPPORTLISTENER_H
#define QTCPPORTLISTENER_H

#include <QObject>
#include <QTcpServer>

class QTcpPortListener : public QTcpServer
{
    Q_OBJECT
public:
    explicit QTcpPortListener(QObject *parent = 0);
    void incomingConnection(qintptr socketDescriptor);

signals:
    void newConnection(qint16 port, qintptr socketDescriptor);

public slots:

};

#endif // QTCPPORTLISTENER_H
