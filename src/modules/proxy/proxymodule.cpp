#include "proxymodule.h"
#include "proxyprocessor.h"

ProxyModule::ProxyModule(QObject *parent) :
    JinnModule(parent)
{
    this->contentProcessors.append(new ProxyProcessor());
}
