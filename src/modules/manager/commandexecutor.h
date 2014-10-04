#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H
#include <QString>
#include <qwebglobaldata.h>

class CommandExecutor
{
public:
    CommandExecutor(QWebServerSettings* serverSettings);

    bool listModule(bool showAll = false);
    bool installModule(QString libPath, bool moduleOff = false); //TODO: сделать zip(jml)
    bool removeModule(QString name);
    bool turnModuleOn(QString name);
    bool turnModuleOff(QString name);

    bool listProject();
    bool addProject(QString filePath);
    bool removeProject();

    QByteArray log();
private:
    QWebServerSettings *m_serverSettings;
    QString m_moduleFolder;
    QByteArray m_log;

    bool checkModule(QString libPath);
    QStringList activeModules();

};

#endif // COMMANDEXECUTOR_H
