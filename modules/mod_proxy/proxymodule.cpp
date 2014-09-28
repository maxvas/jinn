#include "proxymodule.h"
#include "proxyprocessor.h"

ProxyModule::ProxyModule(QObject *parent) :
    AnutaModule(parent)
{
    this->contentProcessors.append(new ProxyProcessor());
}

QString ProxyModule::name()
{
    return "proxy";
}
