#include <QCoreApplication>
#include <QDir>
#include "qwebserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString exePath = a.applicationDirPath();
    QDir dir(exePath);
    QString settingsPath = dir.filePath("../config/jinn-global.jsn");
//    QString settingsPath = dir.filePath("../tests/data/test1/test1.jsn");
    QWebServer server(settingsPath);
    server.start();
    a.exec();
}
