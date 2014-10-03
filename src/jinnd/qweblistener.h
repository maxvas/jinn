#ifndef QWEBLISTENER_H
#define QWEBLISTENER_H

#include <QObject>
#include <QWebGlobalData>
#include "qtcpportlistener.h"

class QWebListener : public QObject
{
    Q_OBJECT
public:
    explicit QWebListener(QObject *parent, QWebGlobalData *global);
    ~QWebListener();

private:
    QList<QTcpPortListener* > listeners;

signals:
    void newConnection(qint16 port, qintptr socketDescriptor);

public slots:

};

#endif // QWEBLISTENER_H
