#include "jinnservice.h"
#include <QDir>
#include <QCoreApplication>
#include "qwebserver.h"

int main(int argc, char *argv[])
{
#ifdef QT_DEBUG
    QCoreApplication a(argc, argv);
    QWebServer server;
    server.start();
    a.exec();
#endif
#ifdef QT_NO_DEBUG
    JinnService service(argc, argv);
    service.exec();
#endif
}
