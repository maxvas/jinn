#include "qwebserver.h"

QWebServer::QWebServer(QString settingsFile) :
    QObject(0)
{
    qRegisterMetaType<qintptr>("qintptr");
    this->settingsFileName = settingsFile;
}

void QWebServer::start()
{
    QWebGlobalData *listenerGlobalData = new QWebGlobalData(settingsFileName);
    if (listenerGlobalData->hasParsingError())
    {
        qDebug()<<listenerGlobalData->parsingErrorString();
    }
    listener = new QWebListener(this, listenerGlobalData);
    int workersCount = listenerGlobalData->settings().workersCount();
    for(int i=0; i<workersCount; i++)
    {
        QHttpWorkerThread *workerThread = new QHttpWorkerThread(listenerGlobalData->initData());
        connect(workerThread, SIGNAL(started()), this, SLOT(connectWorkerSignals()));
        workerThread->start();
    }
}

void QWebServer::connectWorkerSignals()
{
    QHttpWorkerThread *workerThread = qobject_cast<QHttpWorkerThread* >(QObject::sender());
    QHttpWorker *worker = workerThread->worker();
    connect(listener, SIGNAL(newConnection(qint16,qintptr)), worker, SLOT(newConnection(qint16,qintptr)));
}
