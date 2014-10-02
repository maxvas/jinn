#include "jinnmodule.h"


JinnModule::JinnModule(QObject *parent):
    QObject(parent)
{
}

bool JinnModule::init(QWebGlobalData *global)
{
    foreach(RequestProcessor* rp, contentProcessors)
    {
        if(!rp->init(global))
            return false;
    }
    return true;
}
