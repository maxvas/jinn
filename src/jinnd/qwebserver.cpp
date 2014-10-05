#include "qwebserver.h"
#include <QCoreApplication>

QWebServer::QWebServer() :
    QObject(0)
{
    qRegisterMetaType<qintptr>("qintptr");
    //Определяем режим (developer или нет)
    bool developer = false;
    QString exePath = QCoreApplication::instance()->applicationDirPath();
    developer = QFile::exists(exePath+"/../config");
    QString settingsFile = "/etc/jinn/jinn-global.jsn";//default value is path in develop
    QDir dir(exePath);
    if (developer)
    {
        qDebug()<<"Server started in 'developer' mode";
        settingsFile = dir.filePath("../config/jinn-global.jsn");
    }else
    {
        qDebug()<<"Server started in 'enterprise' mode";
#ifndef __unix
        settingsPath = dir.filePath("../config/jinn-global.jsn");
#endif
    }
    qDebug()<<"Configs will be loaded from "<<settingsFile;
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
        workers.append(workerThread);
    }
}

void QWebServer::stop()
{
    foreach (QHttpWorkerThread *workerThread, workers) {
        workerThread->terminate();
        delete workerThread;
    }
    delete listener;
    listener = 0;
}

void QWebServer::connectWorkerSignals()
{
    QHttpWorkerThread *workerThread = qobject_cast<QHttpWorkerThread* >(QObject::sender());
    QHttpWorker *worker = workerThread->worker();
    connect(listener, SIGNAL(newConnection(qint16,qintptr)), worker, SLOT(newConnection(qint16,qintptr)));
}
