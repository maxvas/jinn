#ifndef TESTMODULE_H
#define TESTMODULE_H

#include <jinnmodule.h>

class StaticModule: public JinnModule
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "pro.jinn.api.JinnModule")
    Q_INTERFACES(JinnModule)
public:
    StaticModule(QObject *parent=0);
    QString name();
};

#endif // JINNTESTMODULE_H
