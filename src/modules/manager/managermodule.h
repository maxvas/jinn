#ifndef TESTMODULE_H
#define TESTMODULE_H

//#include "global.h"
#include <jinnmodule.h>

class ManagerModule: public JinnModule
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "pro.jinn.api.JinnModule")
    Q_INTERFACES(JinnModule)
public:
    ManagerModule(QObject *parent=0);
    QString name();
};

#endif // JINNTESTMODULE_H
