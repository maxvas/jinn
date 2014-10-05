#include "jinnservice.h"
#include "qwebserver.h"
#include <QCoreApplication>
#include <QDir>
#include <QStringList>
#include <QFileInfo>

JinnService::JinnService(int argc, char **argv) :
    QtService(argc, argv, "Jinnd")
{
    setServiceDescription("Jinn web server");
    setServiceFlags(QtServiceBase::CanBeSuspended);

}

void JinnService::start()
{
    server = new QWebServer();
    server->start();
}

void JinnService::stop()
{
    delete server;
    application()->exit();
}

void JinnService::pause()
{

}

void JinnService::resume()
{

}

bool JinnService::isDeveloperBuild()
{
    QStringList args = application()->arguments();
    if (args.length()>1)
    {
        if (args[1].startsWith("-e"))
        {
            return true;
        }
    }
    return false;
}
