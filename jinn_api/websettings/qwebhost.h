#ifndef QWEBHOST_H
#define QWEBHOST_H

#include <QJSMapping>
#include "jinn_api_global.h"

class JINN_APISHARED_EXPORT QWebHost : public QJSMapping
{
    Q_OBJECT
public:
    QJS_MAPPING_QSTRING("host", host, setHost)
    QJS_MAPPING_INT("port", port, setPort)

signals:

public slots:

};

#endif // QWEBHOST_H
