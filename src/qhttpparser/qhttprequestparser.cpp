#include "qhttprequestparser.h"

QHttpRequestParser::QHttpRequestParser(QObject *parent) :
    QObject(parent),
    isHeaderRecived(false), isBodyRecived(false), isFinished(true)
{
    m_req = new QHttpRequest(this);
    m_resp = new QHttpResponse(this);
    connect(m_resp, SIGNAL(beforeSendHeaders()), this, SIGNAL(beforeSendHeaders()));
    connect(m_resp, SIGNAL(sendData(QByteArray)), this, SIGNAL(sendData(QByteArray)));
    connect(m_resp, SIGNAL(finished()), this, SLOT(onParserFinished()));
    connect(m_resp, SIGNAL(finished()), this, SIGNAL(finished()));
}

QHttpRequest *QHttpRequestParser::request()
{
    return m_req;
}

QHttpResponse *QHttpRequestParser::response()
{
    return m_resp;
}

QHttpRequestParser::~QHttpRequestParser()
{
}

void QHttpRequestParser::putData(QByteArray newData)
{
    //Если мы еще читаем заголовок
    if (!isHeaderRecived)
    {
        isFinished = false;
        int oldPos = qMax(m_data.length()-4, 0);
        m_data.append(newData);
        qint64 pos = m_data.indexOf("\r\n\r\n", oldPos);
        if (pos>-1)
        {
            m_req->m_headerData = m_data.left(pos);
            QByteArray bodyBlock = m_data.right(m_data.length()-pos-4);
            m_req->parseHeader();
            isHeaderRecived = true;
            newData = bodyBlock;
            emit headerRecieved();//TODO: do this async!
            if (isFinished)
            {
                return;
            }
            if (m_req->m_contentLen==0)
            {
                emit finished();
            }
            if (bodyBlock.length()==0)
                return;
        }
    }
    //Если мы уже прочитали заголовок и сейчас читаем тело
    if (isHeaderRecived && !isBodyRecived)
    {
        m_req->m_bodyData.append(newData);
        emit bodyDataBlockRecieved(newData);
        if (m_req->m_bodyData.length()>=m_req->m_contentLen)
        {
            isBodyRecived = true;
            emit bodyRecieved();
            emit finished();
        }
    }
}

//void QHttpRequestParser::finish()
//{
//    emit finished();
//}

void QHttpRequestParser::free()
{
    m_req->free();
    m_resp->free();
    m_data.clear();
    isHeaderRecived = false;
    isBodyRecived = false;
}

void QHttpRequestParser::onParserFinished()
{
    isFinished = true;
}
