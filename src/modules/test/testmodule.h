#ifndef TESTMODULE_H
#define TESTMODULE_H

//#include "global.h"
#include <jinnmodule.h>

class TestModule: public JinnModule
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "pro.jinn.api.JinnModule")
    Q_INTERFACES(JinnModule)
public:
    TestModule(QObject *parent=0);
};

#endif // JINNTESTMODULE_H
