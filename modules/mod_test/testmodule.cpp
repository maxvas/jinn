#include "testmodule.h"
#include "testcontentprocessor.h"

TestModule::TestModule(QObject *parent)
    :JinnModule(parent)
{
    this->contentProcessors.append(new TestContentProcessor());
}

QString TestModule::name()
{
    return "mod_test";
}
