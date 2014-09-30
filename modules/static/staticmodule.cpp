#include "staticmodule.h"
#include "staticprocessor.h"

StaticModule::StaticModule(QObject *parent)
    :JinnModule(parent)
{
    this->contentProcessors.append(new StaticProcessor());
}

QString StaticModule::name()
{
    return "static";
}
