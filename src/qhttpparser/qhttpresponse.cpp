#include "qhttpresponse.h"
#include <QStringList>

QHttpResponse::QHttpResponse(QObject *parent) :
    QObject(parent), m_headersSent(false)
{
    m_headers = new QHttpHeadersList();
    #define STATUS_CODE(code, message, naame) m_statusCodes.insert(code, message);
    #include "statuses.h"
    #undef STATUS_CODE
}

QHttpResponse::~QHttpResponse()
{
    delete m_headers;
}

QHttpHeadersList *QHttpResponse::headers()
{
    return m_headers;
}

bool QHttpResponse::headersSent()
{
    return m_headersSent;
}

void QHttpResponse::setStatusCode(int code)
{
    QString message;
    if (m_statusCodes.contains(code))
        message = m_statusCodes[code];
    else
        message = "No message";
    firstLine = QString("HTTP/1.1 %1 %2").arg(code).arg(message);
}

void QHttpResponse::echo(QByteArray data)
{
    if (!m_headersSent)
        sendHeaders();
    emit sendData(data);
}

void QHttpResponse::echo(QString string)
{
    echo(string.toUtf8());
}

void QHttpResponse::sendRawData(QByteArray data)
{
    emit sendData(data.append("/r/n"));
}

QString QHttpResponse::protocol()
{
    return m_protocol;
}

int QHttpResponse::statusCode()
{
    return m_statusCode;
}

QString QHttpResponse::statusMessage()
{
    return m_statusMessage;
}

void QHttpResponse::finishAndSendHeaders()
{
    if (!m_headersSent)
    {
        sendHeaders();
    }
    emit finished();
}

void QHttpResponse::finish()
{
    m_headersSent = true;
    emit finished();
}

void QHttpResponse::parseHeader()
{
    QString headerText = m_headerData;
    QStringList headerLines = headerText.split("\r\n");
    if (headerLines.size()==0)
        return;
    for (int i=0; i<headerLines.size(); i++)
    {
        if (i==0)
        {
            QStringList firstLine = headerLines[i].split(" ");
            if (firstLine.size()<3)
                return;
            m_protocol = firstLine[0];
            m_statusCode = firstLine[1].toInt();
            m_statusMessage = firstLine[2];
        } else
        {
            QString str = headerLines[i];
            int pos = str.indexOf(":");
            if (pos>0)
            {
                QString name = str.left(pos);
                name = name.toLower().trimmed();
                QString value = str.right(str.length()-pos-1);
                value = value.trimmed();
                m_headers->set(name, value);
            }
        }
    }
    if (m_headers->contains("content-length"))
    {
        m_contentLen = m_headers->get("content-length").toInt();
    } else
    {
        m_contentLen = 0;
    }
}

void QHttpResponse::free()
{
    firstLine = "";
    m_headers->clear();
    m_headersSent = false;
}

void QHttpResponse::sendHeaders()
{
    emit beforeSendHeaders();
    if (firstLine.length()==0)
        setStatusCode(QHttpStatusCodes::OK);
    QByteArray data;
    data.append(firstLine+"\r\n");
    for (QHttpHeadersList::iterator i = m_headers->begin(); i!=m_headers->end(); ++i)
    {
        QHttpHeader *header = &(*i);
        data.append(header->name()+": "+header->value()+"\r\n");
    }
    data.append("\r\n");
    emit sendData(data);
    m_headersSent = true;
}
