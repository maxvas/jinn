#include "jinnservice.h"
#include <QDir>
#include <QCoreApplication>
#include "qwebserver.h"

int main(int argc, char *argv[])
{
#ifdef QT_DEBUG
    QCoreApplication a(argc, argv);
    QString exePath = a.applicationDirPath();
    QDir dir(exePath);
    QString settingsPath = dir.filePath("../config/jinn-global.jsn");
    QWebServer server(settingsPath);
    server.start();
    a.exec();
#endif
#ifdef QT_NO_DEBUG
    JinnService service(argc, argv);
    service.exec();
#endif
}
