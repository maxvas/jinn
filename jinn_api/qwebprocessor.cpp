#include "qwebprocessor.h"
#include <QTcpSocket>
#include <QTime>

QWebProcessor::QWebProcessor(QObject *parent, QWebGlobalData* global) :
    QObject(parent), socket(0)
{
    parser = new QHttpRequestParser();
    rp = new QWebResourseProvider(this, global);
    connect(parser, SIGNAL(headerRecieved()), this, SLOT(onParserHeaderRecieved()));
    connect(parser, SIGNAL(bodyDataBlockRecieved(QByteArray)), rp, SLOT(dataBlockRecieved(QByteArray)));
    connect(parser, SIGNAL(beforeSendHeaders()), rp, SLOT(beforeSendHeaders()));
    connect(parser, SIGNAL(bodyRecieved()), rp, SLOT(bodyRecieved()));
    connect(parser, SIGNAL(sendData(QByteArray)), this, SLOT(socketWrite(QByteArray)));
    connect(parser, SIGNAL(finished()), this, SLOT(onParserFinished()));
}

bool QWebProcessor::newConnection(qint16 port, qintptr socketDescriptor)
{
    qDebug()<<"QWebProcessor->newConnection()"<<socketDescriptor<<QTime::currentTime().toString();
    if (socket)
    {
        QTcpSocket *sock = new QTcpSocket();
        sock->setSocketDescriptor(socketDescriptor);
        sock->close();
        sock->deleteLater();
        return true;
    }else
    {
        this->port = port;
        socket = new QTcpSocket();
        connect(socket, SIGNAL(readyRead()), this, SLOT(socketRead()));
        connect(socket, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));
        socket->setSocketDescriptor(socketDescriptor);
        return true;
    }
}

void QWebProcessor::socketRead()
{
    if (!socket)
    {
        qDebug()<<"Как это могло случиться??? Сработал socketRead(), а сокета нет!";
        return;
    }
    qint64 bufsize = 1024*4;
    while (socket)
    {
        if (!socket->bytesAvailable())
        {
            return;
        }
        QByteArray data;
        data = socket->read(bufsize);
        parser->putData(data);
    }
}

void QWebProcessor::socketWrite(QByteArray data)
{
    qDebug()<<"socketWriteStarted"<<QTime::currentTime().toString();
    if (!socket)
    {
        qDebug()<<"Как это могло случиться??? Сработал socketWrite(), а сокета нет!";
        return;
    }
    if (socket->isWritable())
    {
        if (!socket->write(data))
        {
            disconnectNetworkConnection();
        }
        //socket->waitForBytesWritten();
    }
    qDebug()<<"socketWriteFinished"<<QTime::currentTime().toString();
}

void QWebProcessor::onParserFinished()
{
    if (socket)
    {
        qDebug()<<"QWebProcessor->onParserFinished()"<<socket->socketDescriptor();
        disconnectNetworkConnection();
    }
}

void QWebProcessor::disconnectNetworkConnection()
{
    if (socket->isOpen()){
        socket->flush();
        socket->disconnectFromHost();
    }
}

void QWebProcessor::onParserHeaderRecieved()
{
    rp->headerRecieved(port, parser->request(), parser->response());
}

void QWebProcessor::onSocketDisconnected()
{
    qDebug()<<"QWebProcessor->socketDisconnected"<<socket->socketDescriptor()<<QTime::currentTime().toString();
    if (!socket)
    {
        qDebug()<<"Как это могло случиться??? Сработал onSocketDisconnected(), а сокета уже нет!";
        return;
    }
    parser->free();
    rp->free();
    //socket->close();
    socket->deleteLater();
    socket = 0;
    emit finished();
}
