#ifndef QWEBER_H
#define QWEBER_H

#include "global.h"
#include <jinnmodule.h>

class SHARED_EXPORT QWeber: public JinnModule
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "pro.jinn.api.JinnModule")
    Q_INTERFACES(JinnModule)
public:
    QWeber(QObject *parent=0);
    QString name();
};

#endif // QWEBER_H
