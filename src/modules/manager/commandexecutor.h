#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H
#include <QString>
#include <qwebglobaldata.h>

class CommandExecutor
{
public:
    CommandExecutor(QWebServerSettings* serverSettings);

    bool listModule();
    bool installModule(QString libPath); //TODO: сделать zip
    bool removeModule(QString name);

    bool listProject();
    bool addProject(QString filePath);
    bool removeProject();

    QByteArray log();
private:
    QWebServerSettings *m_serverSettings;
    QString m_moduleFolder;
    QByteArray m_log;

    bool checkModule(QString libPath);

};

#endif // COMMANDEXECUTOR_H
