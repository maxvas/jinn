#include "qhttprequest.h"

QHttpRequest::QHttpRequest(QObject *parent) :
    QObject(parent)
{
    m_headers = new QHttpHeadersList();
}

QString QHttpRequest::method()
{
    return m_method;
}

QString QHttpRequest::path()
{
    return m_path;
}

QString QHttpRequest::host()
{
    if (m_headers->contains("host"))
        return m_headers->get("host");
    return "";
}

qint64 QHttpRequest::contentLength()
{
    return m_contentLen;
}

QByteArray QHttpRequest::headerData()
{
    return m_headerData;
}

QByteArray QHttpRequest::bodyData()
{
    return m_bodyData;
}

void QHttpRequest::free()
{
    m_headers->clear();
    m_method.clear();
    m_path.clear();
    m_headerData.clear();
    m_bodyData.clear();
    m_contentLen = 0;
}

void QHttpRequest::parseHeader()
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
            if (firstLine.size()<2)
                return;
            m_method = firstLine[0];
            QByteArray pathArr;
            pathArr.append(firstLine[1]);
            m_path = QString::fromUtf8(pathArr.fromPercentEncoding(pathArr));
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
