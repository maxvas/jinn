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

bool CommandExecutor::listModule()
{
    m_log.append("\nlist of modules:\n");

    QDir dir;
    if(!dir.cd(m_moduleFolder)){
        m_log.append("\nmodule directory is not found");
        return false;
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
    foreach (QString fileName, moduleList)
    {
        QString moduleName=fileName.split('.')[0];
        if(moduleName.startsWith("lib"))
            moduleName.remove(0,3);
        if (!checkModule(dir.absoluteFilePath(fileName)))
        {
            m_log.append("\nmodule "+moduleName+" is invalid");
            removeModule(moduleName);
            continue;
        }
        m_log.append("\n"+moduleName);

    }

    return true;
}

bool CommandExecutor::installModule(QString libPath)
{
    if(!checkModule(libPath)){
        m_log.append("\nfile "+libPath+" is invalid ");
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
    m_log.append("\nmodule "+libPath+" was installed");
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
//        QPluginLoader loader(fileName);
//        bool bla=loader.isLoaded();
        //(TODO)

        if(!dir.remove(fileName)){
            m_log.append("\ncant't delete file "+fileName);
            return false;
        }
    }
    m_log.append("\nmodule "+name+" was removed");
    return true;
}

QByteArray CommandExecutor::log()
{
    return m_log;
}

bool CommandExecutor::checkModule(QString libPath)
{
    bool check = false;
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

