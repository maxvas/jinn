#ifndef PROXYMODULE_H
#define PROXYMODULE_H

#include <QObject>
#include <jinnmodule.h>
#include <qhttpresponseparser.h>
//#include "global.h"

class Module : public JinnModule
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "pro.jinn.api.JinnModule")
    Q_INTERFACES(JinnModule)
public:
    explicit Module(QObject *parent = 0);
    QString name();

private:

signals:

public slots:

};

#endif // PROXYMODULE_H
