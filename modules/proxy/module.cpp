#include "module.h"
#include "contentprocessor.h"

Module::Module(QObject *parent) :
    JinnModule(parent)
{
    this->contentProcessors.append(new ContentProcessor());
}

QString Module::name()
{
    return "proxy";
}
