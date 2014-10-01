#include "qhttpmanipulator.h"

QHttpManipulator::QHttpManipulator()
{
}

QHttpRequest *QHttpManipulator::request()
{
    return m_request;
}

QHttpResponse *QHttpManipulator::response()
{
    return m_response;
}

void QHttpManipulator::responseCode(int code)
{
    m_response->setStatusCode(code);
}

void QHttpManipulator::header(QString header)
{
    if (header.startsWith("HTTP"))
    {
        m_response->firstLine = header;
        return;
    }
    QStringList ls = header.split(":");
    if (ls.count()!=2)
    {
        //TODO: вывод ошибки (или предупреждения)
        return;
    }
    QString key = ls.first().trimmed();
    QString value = ls.last().trimmed();
    m_response->headers()->set(key, value);
}


void QHttpManipulator::echo(QString string)
{
    m_response->echo(string);
}

void QHttpManipulator::setRequestResponse(QHttpRequest *request, QHttpResponse *response)
{
    this->m_request = request;
    this->m_response = response;
}

void QHttpManipulator::finish()
{
    this->m_response->finishAndSendHeaders();
}

void QHttpManipulator::finishWithoutSendingHeaders()
{
    this->m_response->finish();
}

void QHttpManipulator::free()
{

}
