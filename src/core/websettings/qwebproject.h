#ifndef QWEBPROJECT_H
#define QWEBPROJECT_H

#include <QJS>
#include <QList>
#include <QJSMapping>
#include <QDir>
#include "qwebmodule.h"
#include "qwebmodulelink.h"
#include "qwebhost.h"
#include "../core_global.h"

class JINN_CORESHARED_EXPORT QWebProject : public QJS
{
    Q_OBJECT
public:
    QWebProject(QJS json);
    QJS_MAPPING_QSTRING("name", name, setName)
    QJS_MAPPING_ARRAY("hosts", hosts, addHost, QWebHost)
    QJS_MAPPING_ARRAY("proxy", proxy, addProxy, QWebHost)
    QJS_MAPPING_ARRAY("moduleLinks", moduleLinks, addModuleLink, QWebModuleLink)
    QJS_MAPPING_STRINGHASH("modules", modules, getModule, setModule, QWebModule)

    QDir dir();
    void readModuleSettings(QString fileName, QString url);
    void readModules();
    void addModule(QString mdlFile, QString url);
private:

signals:

public slots:

};

#endif // QWEBPROJECT_H
