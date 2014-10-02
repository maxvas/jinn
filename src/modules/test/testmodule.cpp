#include "testmodule.h"
#include "testprocessor.h"

TestModule::TestModule(QObject *parent)
    :JinnModule(parent)
{
    this->contentProcessors.append(new TestProcessor());
}
