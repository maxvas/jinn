#ifndef QHTTPWORKER_H
#define QHTTPWORKER_H

#include <QObject>
#include <QThread>
#include <QHash>
#include <QQueue>
#include <qwebprocessor.h>

typedef QPair<qint16, qintptr> Connection;
class QHttpWorker : public QObject
{
    Q_OBJECT
public:
    QHttpWorker(QByteArray initData);

private:
    QWebGlobalData *global;
    QVector<QWebProcessor* > *busyProcessors;
    QVector<QWebProcessor* > *freeProcessors;
    QQueue<Connection> *connectionsQueue;

public slots:
    void newConnection(qint16 port, qintptr socketDescriptor);

private slots:
    void onProcessorFinished();
    void getConnectionFromQueueAndStartIt();

};

class QHttpWorkerThread: public QThread
{
    Q_OBJECT
public:
    QHttpWorkerThread(QByteArray initData):
        initData(initData)
    {

    }
    void run(){
        m_worker = new QHttpWorker(initData);
        emit started();
        exec();
    }
    QHttpWorker *worker(){
        return m_worker;
    }

private:
    QByteArray initData;
    QHttpWorker *m_worker;

signals:
    void started();

};

#endif // QHTTPWORKER_H
