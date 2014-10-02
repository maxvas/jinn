#include "managermodule.h"
#include "managerprocessor.h"

ManagerModule::ManagerModule(QObject *parent)
    :JinnModule(parent)
{
    this->contentProcessors.append(new ManagerProcessor());
}
