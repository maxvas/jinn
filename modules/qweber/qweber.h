#ifndef TESTMODULE_H
#define TESTMODULE_H

#include "mod_test_global.h"
#include <jinnmodule.h>

class MOD_TESTSHARED_EXPORT TestModule: public JinnModule
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "pro.jinn.api.JinnModule")
    Q_INTERFACES(JinnModule)
public:
    TestModule(QObject *parent=0);
    QString name();
};

#endif // JINNTESTMODULE_H
