#include "qhttpheader.h"

QHttpHeader::QHttpHeader(QString name, QString value):
    m_name(name), m_value(value)
{
}

QString QHttpHeader::name()
{
    return m_name;
}

QString QHttpHeader::value()
{
    return m_value;
}
