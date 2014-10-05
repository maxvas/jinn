#include "qwebserversettings.h"

#include <QFile>
#include <qlogging.h>
#include "../qwebglobaldata.h"
#include <QDebug>

void QWebServerSettings::addProject(QString prjFileName)
{
    //TODO сделать)
//    QString fileName = dir().absoluteFilePath(prjFileName);
//    foreach(QJS file, prjFiles())
//    {
//        if (file.toString()==fileName)
//            return;
//    }
//    readProjectSettings(fileName);
//    this->prjFiles().append(fileName);
}

void QWebServerSettings::readProjectSettings(QString fileName)
{
    disableSignals();
    QString prjFileName = dir().absoluteFilePath(fileName);
    QFile prjFile(prjFileName);
    if (!prjFile.open(QFile::ReadOnly))
    {
        //TODO: вывод ошибки
        qDebug()<<"Can't open file "<<prjFileName;
        return;
    }
    QString text = prjFile.readAll();
    QWebProject project = (QWebProject)QJS::fromJson(text);
    if (project.hasParsingError())
    {
        //TODO: вывод ошибки
        qDebug()<<"Can't parse project settings "<<prjFileName;
        qDebug()<<"Parsing error: "<<project.parsingErrorString();
        return;
    }
    QFileInfo prjFileInfo(prjFileName);
    project["dir"]=prjFileInfo.absolutePath();
    foreach (QJS prj, this->projects()) {
        if (prj==project)
        {
            //TODO: проект уже загружен
            return;
        }
    }
    setProject(project.name(), project);
    QWebProject &prj = getProject(project.name());
    prj.readModules();
    enableSignals();
}

QDir QWebServerSettings::dir()
{
    QString dirName = ((QWebGlobalData*)(this->parent()))->dir();
    return QDir(dirName);
}

int QWebServerSettings::moduleIndex(QString moduleName)
{
    QJS mods = modules();
    for(int i=0;i<mods.size();i++){
        if(moduleName == mods[i].toString())
            return i;
    }
    return -1;
}

void QWebServerSettings::removeModule(QString moduleName)
{
    QJS for_test = modules();
    int index = moduleIndex(moduleName);
    if(index>-1){
        modules().remove(index);
    }
    for_test = modules();
    qDebug()<<for_test.toString();
}

void QWebServerSettings::loadProjects()
{
    QDir dir(projectsDir());
    QStringList list = dir.entryList(QDir::Dirs);
    foreach (QString subdir, list) {
        QDir prjDir(dir);
        if(prjDir.cd(subdir)){
            QStringList filters;filters << "*.prj";
            QStringList fileList = prjDir.entryList(filters,QDir::Files);
            if(!fileList.empty()){
                QString fileName = fileList.at(0);
                QString path = prjDir.absoluteFilePath(fileName);
                readProjectSettings(path);
            }
        }
    }
}

void QWebServerSettings::unloadProjects()
{
    projects()=QJS::Null;
}
