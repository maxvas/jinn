#ifndef QWEBSERVERSETTINGS_H
#define QWEBSERVERSETTINGS_H

#include <QJSSharedNode>
#include <QJSMapping>
#include <QDir>
#include "qwebproject.h"
#include "../core_global.h"

class JINN_CORESHARED_EXPORT QWebServerSettings : public QJS
{
    Q_OBJECT
public:
    QJS_MAPPING_ARRAY("modules", modules, addModule, QString)
    QJS_MAPPING_QSTRING("modulesDir", modulesDir, setModulesDir)
    QJS_MAPPING_ARRAY("prjFiles", prjFiles, addProjectFile, QString)
    QJS_MAPPING_STRINGHASH("projects", projects, getProject, setProject, QWebProject)
    QJS_MAPPING_INT("connectionsPerWorker", connectionsPerWorker, setConnectionsPerWorker)
    QJS_MAPPING_INT("workersCount", workersCount, setWorkersCount)
    void addProject(QString prjFileName);
    void readProjectSettings(QString fileName);
    QDir dir();

private:

signals:

public slots:

};

#endif // QWEBSERVERSETTINGS_H
