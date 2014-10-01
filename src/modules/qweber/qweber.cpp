#include "qweber.h"
#include "qwebercontentprocessor.h"

QWeber::QWeber(QObject *parent)
    :JinnModule(parent)
{
    this->contentProcessors.append(new QWeberContentProcessor());
}

QString QWeber::name()
{
    return "qweber";
}
