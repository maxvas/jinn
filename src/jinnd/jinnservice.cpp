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
    QString exePath = application()->applicationDirPath();
    QDir dir(exePath);
    QString settingsPath = dir.absoluteFilePath("../config/jinn-global.jsn");
    bool developerBuild = isDeveloperBuild();
    if (developerBuild)
        qDebug()<<"DEVELOPER BUILD";
#ifdef __unix
    if (!developerBuild)
    {
            settingsPath = "/etc/jinn/jinn-global.jsn";
    }
#endif
//    if (!QFile::exists(settingsPath))
//    {
//        qDebug()<<"Global config not found";
//    }
//    QFileInfo settingsFileInfo()
    server = new QWebServer(settingsPath);
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
