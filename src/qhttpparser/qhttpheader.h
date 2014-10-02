#ifndef QHTTPHEADER_H
#define QHTTPHEADER_H

#include <QString>
#include "qhttpparser_global.h"

class QHTTPPARSERSHARED_EXPORT QHttpHeader
{
public:
    QHttpHeader(QString name, QString value);
    QString name();
    QString value();
private:
    QString m_name;
    QString m_value;
};

#endif // QHTTPHEADER_H
