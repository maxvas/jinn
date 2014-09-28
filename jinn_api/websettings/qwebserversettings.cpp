#include "qwebserversettings.h"

#include <QFile>
#include <qlogging.h>
#include <QLoggingCategory>
#include "qwebglobaldata.h"

void QWebServerSettings::addProject(QString prjFileName)
{

    QString fileName = dir().absoluteFilePath(prjFileName);
    foreach(QJS file, prjFiles())
    {
        if (file.toString()==fileName)
            return;
    }
    readProjectSettings(fileName);
    this->prjFiles().append(fileName);
}

void QWebServerSettings::readProjectSettings(QString fileName)
{
    disableSignals();
    QString prjFileName = dir().absoluteFilePath(fileName);
    QFile prjFile(prjFileName);
    if (!prjFile.open(QFile::ReadOnly))
    {
        //TODO: вывод ошибки
        return;
    }
    QString text = prjFile.readAll();
    QWebProject project = (QWebProject)QJS::fromJson(text);
    if (project.hasParsingError())
    {
        //TODO: вывод ошибки
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
