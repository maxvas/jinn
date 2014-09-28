#include "qhttpworker.h"

QHttpWorker::QHttpWorker(QByteArray initData):
    QObject(0)
{
    global = new QWebGlobalData(initData);
    busyProcessors = new QVector<QWebProcessor* >();
    freeProcessors = new QVector<QWebProcessor* >();
    connectionsQueue = new QQueue< Connection >();
    QWebServerSettings &settings = (QWebServerSettings&)global->settings();
    int processorsCount = settings.connectionsPerWorker();
    for(int i=0; i<processorsCount; i++)
    {
        QWebProcessor *processor = new QWebProcessor(0, global);
        freeProcessors->push_back(processor);
        connect(processor, SIGNAL(finished()), this, SLOT(onProcessorFinished()));
    }
}

void QHttpWorker::newConnection(qint16 port, qintptr socketDescriptor)
{
    connectionsQueue->enqueue(Connection(port, socketDescriptor));
    getConnectionFromQueueAndStartIt();
}

void QHttpWorker::getConnectionFromQueueAndStartIt()
{
    if (connectionsQueue->isEmpty())
        return;
    if (freeProcessors->isEmpty())
        return;
    Connection connection = connectionsQueue->dequeue();
    QWebProcessor* processor = freeProcessors->first();
    freeProcessors->removeFirst();
    busyProcessors->push_back(processor);
    processor->newConnection(connection.first, connection.second);
}

void QHttpWorker::onProcessorFinished()
{
    QWebProcessor* processor = qobject_cast<QWebProcessor* >(QObject::sender());
    int pos = busyProcessors->indexOf(processor);
    if (pos==-1)
    {
        return;
    }
    busyProcessors->removeAt(pos);
    freeProcessors->push_back(processor);
    getConnectionFromQueueAndStartIt();
}
