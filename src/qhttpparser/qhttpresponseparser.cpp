#include "qhttpresponseparser.h"

void QHttpResponseParser::putData(QByteArray newData)
{
    //Если мы еще читаем заголовок
    if (!isHeaderRecived)
    {
        m_data.append(newData);
        int oldPos = qMax(m_data.length()-4, 0);
        qint64 pos = m_data.indexOf("\r\n\r\n", oldPos);
        if (pos>-1)
        {
            m_resp->m_headerData = m_data.left(pos);
            QByteArray bodyBlock = m_data.right(m_data.length()-pos-4);
            if (bodyBlock.length()>0)
            {
                m_resp->m_bodyData.append(bodyBlock);
            }
            m_resp->parseHeader();
            isHeaderRecived = true;
            emit headerRecieved();
            if (bodyBlock.length()>0)
                emit bodyDataBlockRecieved(bodyBlock);
        }
    }
    //Если мы уже прочитали заголовок и сейчас читаем тело
    if (isHeaderRecived && !isBodyRecived)
    {
        m_resp->m_bodyData.append(newData);
        emit bodyDataBlockRecieved(newData);
        if (m_resp->m_bodyData.length()>=m_resp->m_contentLen)
        {
            isBodyRecived = true;
            emit bodyRecieved();
        }
    }
}
