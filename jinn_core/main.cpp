#include <QCoreApplication>
#include <QDir>
#include "qwebserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString exePath = a.applicationDirPath();
    QDir dir(exePath);
    printf("test");
    QString settingsPath = dir.filePath("../config/jinn-global.jsn");
    QWebServer server(settingsPath);
    server.start();
    a.exec();
}
