#include "managerprocessor.h"
#include <QTime>
#include "command.h"

bool ManagerProcessor::checkUrl(QString url, QJS &settings, QWebProject &project)
{
    (void)settings;
    (void)project;
    QStringList urls;
    urls.append("/");
    return true;
    return urls.contains(url);
}

void ManagerProcessor::bodyRecieved(QHttpManipulator *http, QJS &settings)
{
    (void)settings;
    QByteArray data =http->request()->bodyData();
    CommandExecutor cmdExecutor(serverSettings);
    Command cmd(&cmdExecutor);
    cmd.parse(data);
    cmd.exec();
    http->echo(cmd.response());

}

bool ManagerProcessor::init(QWebGlobalData *global)
{
    serverSettings = &global->settings();
    return true;
}
