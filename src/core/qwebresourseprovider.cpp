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
    QJS &modules = global->settings().modules();
    modules.disableSignals();
    loadModules();
    connect(&modules, SIGNAL(dataChanged(QByteArray,QString,QByteArray,QByteArray)), this, SLOT(onModulesListChanged(QByteArray,QString,QByteArray,QByteArray)));
    modules.enableSignals();
}

QWebResourseProvider::~QWebResourseProvider()
{
    foreach (JinnModule* m, modules) {
        delete m;
    }
    modules.clear();
    foreach (QPluginLoader* l, loaders) {
        delete l;
    }
    loaders.clear();
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
    QJS &prjModules = project->get("modules");
    for (QJS::iterator it = prjModules.begin(); it!=prjModules.end(); ++it)
    {
        QJS &modulePrjEntry = *it;
        QString moduleName = modulePrjEntry.key();
        if (!modules.contains(moduleName))
        {
            qDebug()<<project->name()+" references to unloaded module: "+modulePrjEntry.key();
            continue;
        }
        JinnModule *m = modules[modulePrjEntry.key()];
        foreach (RequestProcessor *cp, m->contentProcessors) {
            if (cp->checkUrl(url, modulePrjEntry, *project)){
                this->cp = cp;
                this->cpSettings = &modulePrjEntry;
                return true;
            }
        }
    }


    return false;
}

void QWebResourseProvider::loadModules()
{
    QJS &modules = global->settings().modules();
    QDir configDir = global->settings().dir();
    QDir dir(configDir);
    QString modulesDir = dir.absoluteFilePath(global->settings().modulesDir());
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
            if(fileName.contains(moduleName+libExtansion)){
                QPluginLoader *loader = new QPluginLoader(dir.absoluteFilePath(fileName));
                if (!loader->load())
                {
                    qDebug()<<loader->errorString();
                    continue;
                }
                loaders[moduleName] = loader;
                JinnModule *m = (JinnModule*)loader->instance();
                if(!configDir.exists(moduleName)){
                    configDir.mkdir(moduleName);
                }
                m->init(global);
                qDebug()<<moduleName;
                this->modules[moduleName] = m;
                break;
            }
        }
    }
}

bool QWebResourseProvider::loadModule(QString name)
{
    QString modulesDir = global->settings().modulesDir();
    QDir dir(modulesDir);
    QStringList filters;
    #ifdef _WIN32
    filters << "*.dll";
    #endif
    //#endif
    #ifdef __unix
    filters << "*"+name+".so";
    #endif
    QStringList moduleList=dir.entryList(filters,QDir::Files);
    if(moduleList.empty()){
        return false;
    }
    QString fileName = moduleList[0];
    QPluginLoader *loader = new QPluginLoader(dir.absoluteFilePath(fileName));
    if (!loader->load())
    {
        qDebug()<<loader->errorString();
        return false;
    }
    loaders[name] = loader;
    JinnModule *m = (JinnModule*)loader->instance();
    QDir configDir(global->settings().dir());
    if(!configDir.exists(name)){
        configDir.mkdir(name);
    }
    m->init(global);
    this->modules[name] = m;
}

bool QWebResourseProvider::unloadModule(QString name)
{
    if (!modules.contains(name))
    {
        return false;
    }
    JinnModule *m = modules[name];
    modules.remove(name);
    delete m;
    if (!loaders.contains(name))
    {
        return false;
    }
    QPluginLoader *loader = loaders[name];
    loaders.remove(name);
    delete loader;
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
        http->echo("404 Page not found");
        http->finish();
        return;
    }
    if (cp)
    {
        cp->headerRecieved(http, *cpSettings);
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

void QWebResourseProvider::onModulesListChanged(QByteArray addressData, QString operation, QByteArray newDataData, QByteArray oldDataData)
{
    QJS change;
    QDataStream addressStream(addressData);
    QJS address = QJS::fromDataStream(addressStream);
    QDataStream newDataStream(newDataData);
    QJS newData = QJS::fromDataStream(newDataStream);
    QDataStream oldDataStream(oldDataData);
    QJS oldData = QJS::fromDataStream(oldDataStream);
    if (operation=="assign")
    {
        QString name = newData.toString();
        loadModule(name);
        //TODO: Обработать true и false
    }
    if (operation=="remove")
    {
        QString name = oldData.toString();
        unloadModule(name);
        //TODO: Обработать true и false
    }
    qDebug()<<change.toJson();
}
