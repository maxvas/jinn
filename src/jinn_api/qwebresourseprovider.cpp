#include "qwebresourseprovider.h"
#include <QDateTime>
#include "websettings/qwebproxy.h"
#include <QPluginLoader>
#include <iostream>
#include <QDebug>

using namespace std;

QWebResourseProvider::QWebResourseProvider(QObject *parent, QWebGlobalData *global) :
    QObject(parent), global(global), cp(0)
{
    http = new QHttpManipulator();
    QJS modules = global->settings().modules();
    QDir configDir = global->settings().dir();
    QDir dir(configDir);
    QString modulesDir = dir.absoluteFilePath(global->settings().modulesFolder());
    if(!dir.cd(modulesDir)){
        qDebug()<<"директория с модулями не найдена";
        return;
    }
    QStringList filters;
    QString libExtansion;
    #ifdef _WIN32
    filters << "*.dll";
    libExtansion=".dll";
    #endif
    //#endif
    #ifdef __unix
    filters << "*.so";
    libExtansion=".so";
    #endif

    dir.setNameFilters(filters);
    QStringList moduleList=dir.entryList(filters,QDir::Files);
    qDebug()<<"Modules:";
    foreach (QString fileName, moduleList) {
        for (QJS::iterator i=modules.begin(); i!=modules.end(); ++i){
            QString moduleName = (*i).toString();
            QString bla="lib"+moduleName+libExtansion;
            if(fileName.contains(moduleName+libExtansion)){
                qDebug()<<moduleName;
                QPluginLoader loader(dir.absoluteFilePath(fileName));
                if (!loader.load())
                {
                    qDebug()<<loader.errorString();
                    continue;
                }
                JinnModule *m = (JinnModule*)loader.instance();
                m->init(global);
                this->modules[m->name()] = m;
                if(!configDir.exists(moduleName)){
                    configDir.mkdir(moduleName);
                }
                break;
            }
        }
    }
}

bool QWebResourseProvider::findProject(QString host, qint16 port)
{
    QJS &projects = global->settings().projects();
    for (QJS::iterator i = projects.begin(); i != projects.end(); ++i)
    {
        QWebProject &project = (QWebProject&)(*i);
        QJS &hosts = project.hosts();
        for (QJS::iterator j = hosts.begin(); j != hosts.end(); ++j)
        {
            QWebHost &prjHost = (QWebHost&)(*j);
            if (prjHost.host()==host)
                if (prjHost.port()==port)
                {
                    this->project = &(project);
                    return true;
                }
        }
    }
    return false;
}

bool QWebResourseProvider::findContentProcessor(QString url)
{
    foreach (JinnModule *m, modules)
    {
        QString name = m->name();
        foreach (RequestProcessor *cp, m->contentProcessors) {
            QJS &cpSettings = this->project->get(cp->settingsName());
            if (cp->checkUrl(url, this->project)){
                this->cp = cp;
                this->cpSettings = &cpSettings;
                return true;
            }
        }
    }
    return false;
}

void QWebResourseProvider::headerRecieved(qint16 port, QHttpRequest *request, QHttpResponse *response)
{
    qDebug()<<request->path();
    http->setRequestResponse(request, response);
    QString host = request->host();
    if (!findProject(host, port))
    {
        http->responseCode(QHttpStatusCodes::BadGateway);
        http->finish();
        return;
    }
    if (!findContentProcessor(http->request()->path()))
    {
        http->responseCode(QHttpStatusCodes::NotFound);
        http->finish();
        return;
    }
    if (cp)
    {
        cp->headerRecieved(http, *cpSettings);
        http->finish();
    }
}

void QWebResourseProvider::dataBlockRecieved(QByteArray data)
{
    if (cp)
    {
        cp->bodyDataBlockRecieved(data, *cpSettings);
    }
}

void QWebResourseProvider::bodyRecieved()
{
    if (cp)
    {
        cp->bodyRecieved(http, *cpSettings);
    }
}

void QWebResourseProvider::beforeSendHeaders()
{
    QHttpHeadersList *headers = http->response()->headers();
    //headers->setIfAbsent("Connection", "keep-alive");
    headers->setIfAbsent("Content-Type", "text/html; charset=utf-8");
    //TODO: Добавить заголовок с датой
    //TODO: Добавить заголовок с именем и версией сервера
    //TODO: Сделать чтение параметров заголовка из настроек сервера
    //TODO: Сделать функцию чтения настроек сервера так, чтобы она могла принимать деаолтное значение
    //(на случай, если такое значение не задано в настройках)
    if (cp)
    {
        cp->beforeSendHeaders(http, *cpSettings);
    }
}

void QWebResourseProvider::free()
{
    if (cp)
    {
        cp->clear();
    }
    http->free();
    cp = 0;
}
