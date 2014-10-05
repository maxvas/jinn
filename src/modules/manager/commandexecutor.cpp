#include "commandexecutor.h"
#include <QDebug>
#include <QPluginLoader>
#include <QFile>
#include <QDir>
#include <jinnmodule.h>

CommandExecutor::CommandExecutor(QWebServerSettings *serverSettings)
    :m_serverSettings(serverSettings)
{
    QDir dir = serverSettings->dir();
    m_moduleFolder = dir.absoluteFilePath(serverSettings->modulesDir());
}

bool CommandExecutor::listModule(bool showAll)
{
    m_log.append("\nlist of modules:\n");

    QDir dir;
    if(!dir.cd(m_moduleFolder)){
        m_log.append("\nmodule directory is not found");
        return false;
    }
    QStringList filters;
    #ifdef _WIN32
    filters << "*.dll";
    #endif
    //#endif
    #ifdef __unix
    filters << "*.so";
    #endif

    dir.setNameFilters(filters);
    QStringList moduleList=dir.entryList(filters,QDir::Files);
    foreach (QString fileName, moduleList)
    {
        QString moduleName=fileName.split('.')[0];
        if(moduleName.startsWith("lib"))
            moduleName.remove(0,3);
        if (!checkModule(dir.absoluteFilePath(fileName)))
        {
            m_log.append("\nmodule file"+fileName+" is invalid");
            removeModule(moduleName);
            continue;
        }
        bool isActive = false;
        QStringList activeList = activeModules();
        isActive = activeList.contains(moduleName);
        if(showAll||isActive)
            m_log.append("\n"+moduleName);

    }

    return true;
}

bool CommandExecutor::installModule(QString libPath, bool moduleOff)
{
    if(!checkModule(libPath)){
        m_log.append("\nfile "+libPath+" is invalid or not exist");
        return false;
    }
    QFileInfo info(libPath);
    QString fileName = info.fileName();
    QDir dir(m_moduleFolder);
    if(dir.exists(fileName)){
        m_log.append("\nmodule "+libPath+" is already exists");
        return false;
    }

    QString newPath = dir.absoluteFilePath(fileName);
    if(!QFile::copy(libPath,newPath)){
        m_log.append("\ncan't copy file "+libPath+" to "+dir.absolutePath());
        return false;
    }
    QString moduleName=fileName.split('.')[0];
    if(moduleName.startsWith("lib"))
        moduleName.remove(0,3);
    m_log.append("\nmodule "+moduleName+" was installed");
    if(!moduleOff)
        turnModuleOn(moduleName);
    return true;
}

bool CommandExecutor::removeModule(QString name)
{
    QDir dir(m_moduleFolder);
    QStringList filters;
    QString libExtansion;
    #ifdef _WIN32
    filters << "*.dll";
    libExtansion=".dll";
    #endif
    //#endif
    #ifdef __unix
    filters << "*"+name+".so"<<"*"+name+".so.*";
    libExtansion=".so";
    #endif
    QStringList moduleList=dir.entryList(filters,QDir::Files);
    foreach (QString fileName, moduleList){
        turnModuleOff(name);
        if(!dir.remove(fileName)){
            m_log.append("\ncant't delete file "+fileName);
            return false;
        }
    }
    m_log.append("\nmodule "+name+" was removed");
    return true;
}

bool CommandExecutor::turnModuleOn(QString name)
{
    QDir dir(m_moduleFolder);
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
        m_log.append("\nmodule "+name+" is not exist");
        return false;
    }
    QString fileName = moduleList.at(0);
    if (!checkModule(dir.absoluteFilePath(fileName)))
    {
        m_log.append("\nmodule file"+fileName+" is invalid");
        removeModule(name);
        return false;
    }
    if(m_serverSettings->moduleIndex(name)<0)
        m_serverSettings->addModule(name);
    return true;
}

bool CommandExecutor::turnModuleOff(QString name)
{
    QDir dir(m_moduleFolder);
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
        m_log.append("\nmodule "+name+" is not exist");
        return false;
    }
    QString fileName = moduleList.at(0);
    if (!checkModule(dir.absoluteFilePath(fileName)))
    {
        m_log.append("\nmodule file"+fileName+" is invalid");
        removeModule(name);
        return false;
    }
    m_serverSettings->removeModule(name);
    return true;
}

bool CommandExecutor::reloadProject()
{
    m_serverSettings->unloadProjects();
    m_serverSettings->loadProjects();
    return true;
}


QByteArray CommandExecutor::log()
{
    return m_log;
}

bool CommandExecutor::checkModule(QString libPath)
{
    bool check = false;
    if(!QFile::exists(libPath))
        return false;

    QPluginLoader loader(libPath);
    if(loader.load()){
        JinnModule *m = (JinnModule*)loader.instance();
        if(m)check = true;
        loader.unload();
    }
    else
        m_log.append("\n" + loader.errorString());
    return check;
}

QStringList CommandExecutor::activeModules()
{
    QJS modules = m_serverSettings->modules();
    QStringList list;
    for (QJS::iterator i=modules.begin(); i!=modules.end(); ++i){
        list.append((*i).toString());
    }
    return list;
}

