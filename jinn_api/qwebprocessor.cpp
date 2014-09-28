#include "qwebprocessor.h"

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
    if (socket)
        return false;
    this->port = port;
    socket = new QTcpSocket();
    connect(socket, SIGNAL(readyRead()), this, SLOT(socketRead()));
    socket->setSocketDescriptor(socketDescriptor);
    return true;
}

void QWebProcessor::socketRead()
{
    if (!socket)
    {
        qDebug()<<"Как это могло случиться??? Сработал socketRead(), а сокета нет!";
        return;
    }
    qint64 bufsize = 1024*4;
    QByteArray data;
    while (socket->bytesAvailable())
    {
        data += socket->read(bufsize);

    }
    parser->putData(data);
}

void QWebProcessor::socketWrite(QByteArray data)
{
    if (!socket)
    {
        qDebug()<<"Как это могло случиться??? Сработал socketWrite(), а сокета нет!";
        return;
    }
    if (socket->isWritable())
    {
        socket->write(data);
        socket->waitForBytesWritten();
    }
}

void QWebProcessor::onParserFinished()
{
    parser->free();
    rp->free();
    if (socket)
    {
        if (socket->isOpen())
        {
            socket->flush();
            socket->disconnectFromHost();
        }
        socket->deleteLater();
    }
    socket = 0;
    emit finished();
}

void QWebProcessor::onParserHeaderRecieved()
{
    rp->headerRecieved(port, parser->request(), parser->response());
}
