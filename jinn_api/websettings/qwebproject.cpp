#include "qwebproject.h"
#include <QFile>
#include "../qwebglobaldata.h"
#include "qwebmodule.h"
#include "qwebproxy.h"

QWebProject::QWebProject(QJS json):
    QJS(json)
{
}

QDir QWebProject::dir()
{
    QString dirName = this->get("dir").toString();
    return QDir(dirName);
}

void QWebProject::readModuleSettings(QString fileName, QString url)
{
    disableSignals();
    QString mdlFileName = dir().absoluteFilePath(fileName);
    QFile mdlFile(mdlFileName);
    if (!mdlFile.open(QFile::ReadOnly))
    {
        //TODO: вывод ошибки
        return;
    }
    QString text = mdlFile.readAll();
    QWebModule module = (QWebModule)QJS::fromJson(text);
    if (module.hasParsingError())
    {
        //TODO: вывод ошибки
        return;
    }
    QFileInfo mdlFileInfo(mdlFileName);
    module["dir"] = mdlFileInfo.absolutePath();
    foreach (QJS mdl, this->modules()) {
        if (mdl==module)
        {
            //TODO: проект уже загружен
            return;
        }
    }
    module.setUrl(url);
    setModule(module.name(), module);
    enableSignals();
}

void QWebProject::readModules()
{
    foreach (QJS js, moduleLinks()) {
        QWebModuleLink &lnk = (QWebModuleLink&)js;
        readModuleSettings(lnk.mdlFile(), lnk.url());
    }
}

void QWebProject::addModule(QString mdlFile, QString url)
{
    QWebModuleLink link;
    link.setMdlFile(mdlFile);
    link.setUrl(url);
    foreach(QJS item, moduleLinks())
    {
        if (item==link)
        {
            //TODO: такой модуль уже существет
            return;
        }
    }
    addModuleLink(link);
    readModuleSettings(mdlFile, url);
}

//bool QWebProject::parse(QStringList &errors)
//{
//    if (!(*this).keys().contains("hosts"))
//    {
//        errors.append("field 'hosts' is abscent");
//    }
//    if (!(*this).keys().contains("modules"))
//    {
//        errors.append("field 'modules' is abscent");
//    }
//    if (errors.count()>0)
//    {
//        return false;
//    }
//    m_hosts.clear();
//    m_modulesLinks.clear();
//    foreach (QJS hostJS, (*this)["hosts"])
//    {
//        QWebHost *host = new QWebHost(hostJS, errors);
//        m_hosts.append(host);
//    }
//    foreach (QJS moduleLinkJS, (*this)["modules"])
//    {
//        QWebModuleLink *host = new QWebModuleLink(moduleLinkJS, errors);
//        m_modulesLinks.append(host);
//    }
//    m_parsed = true;
//    return true;
//}
