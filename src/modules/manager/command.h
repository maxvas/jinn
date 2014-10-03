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
    void parse(QByteArray &data);
    void exec();
    bool hasError();
    QByteArray response();

private:
    bool m_hasError;
    QByteArray m_response;
    QString m_branch;
    QString m_oper;
    QStringList m_options;
    QString m_opt; //пока
    QString m_arg;

    CommandExecutor* m_cmdExecutor;

    static QJS& cmdTree();

};

#endif // COMMAND_H
