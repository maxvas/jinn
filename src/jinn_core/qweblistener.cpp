#include "qweblistener.h"
#include <QHash>

QWebListener::QWebListener(QObject *parent, QWebGlobalData *global) :
    QObject(parent)
{
    QJS &projects = global->settings().projects();
    QHash<qint16, qint16> ports;
    for(QJS::iterator i = projects.begin(); i!=projects.end(); ++i)
    {
        QWebProject &project = (QWebProject&)(*i);
        QJS &hosts = project.hosts();
        for(QJS::iterator j = hosts.begin(); j!=hosts.end(); ++j)
        {
            QWebHost &host = (QWebHost&)(*j);
            ports[host.port()] = host.port();
        }
    }
    foreach (qint16 port, ports) {
        QTcpPortListener *portListener = new QTcpPortListener(this);
        connect(portListener, SIGNAL(newConnection(qint16,qintptr)), this, SIGNAL(newConnection(qint16,qintptr)));
        portListener->listen(QHostAddress::Any, port);
    }
}
