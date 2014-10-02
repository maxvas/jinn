#ifndef QWEBHOST_H
#define QWEBHOST_H

#include <QJSMapping>
#include "../core_global.h"

class JINN_CORESHARED_EXPORT QWebHost : public QJSMapping
{
    Q_OBJECT
public:
    QJS_MAPPING_QSTRING("host", host, setHost)
    QJS_MAPPING_INT("port", port, setPort)

signals:

public slots:

};

#endif // QWEBHOST_H
