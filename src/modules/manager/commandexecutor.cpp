#include "commandexecutor.h"
#include <QDebug>

CommandExecutor::CommandExecutor(QWebServerSettings& serverSettings)
    :m_serverSettings(serverSettings)
{
    m_moduleFolder = serverSettings.modulesFolder();

//    ////
//    QDir dir = serverSettings.dir();
//    QString modulesDir = dir.absoluteFilePath(serverSettings.modulesFolder());
//    if(!dir.cd(modulesDir)){
//        qDebug()<<"директория с модулями не найдена";
//        return;
//    }
//    QStringList filters;
//    QString libExtansion;
//    #ifdef _WIN32
//    filters << "*.dll";
//    libExtansion=".dll";
//    #endif
//    //#endif
//    #ifdef __unix
//    filters << "*.so";
//    libExtansion=".so";
//    #endif

//    dir.setNameFilters(filters);
//    QStringList moduleList=dir.entryList(filters,QDir::Files);
//    qDebug()<<"Modules:";
////    foreach (QString fileName, moduleList) {
////        for (QJS::iterator i=modules.begin(); i!=modules.end(); ++i){
////            QString moduleName = (*i).toString();
////            if(fileName.contains(moduleName+libExtansion)){
////                QPluginLoader loader(dir.absoluteFilePath(fileName));
////                if (!loader.load())
////                {
////                    qDebug()<<loader.errorString();
////                    continue;
////                }
////                JinnModule *m = (JinnModule*)loader.instance();
////                m->init(global);
////                qDebug()<<moduleName;
////                this->modules[moduleName] = m;
////                if(!configDir.exists(moduleName)){
////                    configDir.mkdir(moduleName);
////                }
////                break;
////            }
////        }
////    }
}

bool CommandExecutor::listModule(QByteArray* response)
{
    response->append("\nlist of modules:\n");
    response->append("\nmod1");
    response->append("\nmod2\n");
    return true;
}

