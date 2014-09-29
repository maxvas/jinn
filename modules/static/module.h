#ifndef TESTMODULE_H
#define TESTMODULE_H

#include <jinnmodule.h>

class Module: public JinnModule
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "pro.jinn.api.JinnModule")
    Q_INTERFACES(JinnModule)
public:
    Module(QObject *parent=0);
    QString name();
};

#endif // JINNTESTMODULE_H
