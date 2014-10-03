#ifndef COMMAND_H
#define COMMAND_H
#include <QByteArray>
#include <QStringList>
#include <QJS>
#include "commandexecutor.h"

class Command
{
public:
    Command(CommandExecutor *cmdExecutor);
    bool parse(QByteArray &data);
    bool exec();
    bool hasError();
    QString error();
    QByteArray response();

private:
    bool m_hasError;
    QByteArray m_response;
    QString m_errorString;
    QString m_branch;
    QString m_oper;
    QStringList options;

    CommandExecutor* m_cmdExecutor;

    static QJS& cmdTree();

};

#endif // COMMAND_H
