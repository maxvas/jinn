#ifndef PROXYMODULE_H
#define PROXYMODULE_H

#include <QObject>
#include <jinnmodule.h>
#include <qhttpresponseparser.h>
//#include "global.h"

class ProxyModule : public JinnModule
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "pro.jinn.api.JinnModule")
    Q_INTERFACES(JinnModule)
public:
    explicit ProxyModule(QObject *parent = 0);

private:

signals:

public slots:

};

#endif // PROXYMODULE_H
