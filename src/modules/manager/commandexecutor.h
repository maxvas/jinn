#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H
#include <QString>
#include <qwebglobaldata.h>

class CommandExecutor
{
public:
    CommandExecutor(QWebServerSettings& serverSettings);

    bool listModule(QByteArray *response);
    bool installModule();
    bool removeModule();

    bool listProject();
    bool addProject(QString filePath);
    bool removeProject();
private:
    QWebServerSettings m_serverSettings;
    QString m_moduleFolder;
};

#endif // COMMANDEXECUTOR_H
