#ifndef QWEBSERVER_H
#define QWEBSERVER_H

#include <QObject>
#include "qweblistener.h"
#include "qhttpworker.h"

class QWebServer : public QObject
{
    Q_OBJECT
public:
    QWebServer();
    void start();
    void stop();

private:
    QWebListener *listener;
    QList<QHttpWorkerThread* > workers;
    QString settingsFileName;

signals:

private slots:
    void connectWorkerSignals();

public slots:

};

#endif // QWEBSERVER_H
