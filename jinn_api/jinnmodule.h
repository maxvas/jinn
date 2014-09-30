#ifndef JINN_MODULE_H
#define JINN_MODULE_H

#include "jinn_api_global.h"
#include "requestprocessor.h"
#include <QObject>

class JINN_APISHARED_EXPORT JinnModule: public QObject
{
    Q_OBJECT
public:
    JinnModule(QObject *parent = 0);
    bool init(QWebGlobalData *global);
    virtual QString name() = 0;
    QList<RequestProcessor* > contentProcessors;
};

QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(JinnModule, "pro.jinn.api.JinnModule")
QT_END_NAMESPACE

#endif // JINN_MODULE_H
