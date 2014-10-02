#ifndef JINNSERVICE_H
#define JINNSERVICE_H
#include "qtservice.h"

class QWebServer;

class JinnService : public QtService<QCoreApplication>
{
public:
    explicit JinnService(int argc, char **argv);
private:
    void start();
    void stop();
    void pause();
    void resume();

    bool isDeveloperBuild();
    QWebServer *server;
};

#endif // JINNSERVICE_H
