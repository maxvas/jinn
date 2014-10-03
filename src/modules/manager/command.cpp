#include "command.h"


Command::Command(CommandExecutor *cmdExecutor)
    :m_hasError(false),m_cmdExecutor(cmdExecutor)
{
    m_errorString = "";
}

bool Command::parse(QByteArray &data)
{
    QList<QByteArray> params=data.split('\n');
    params.removeLast();
    if(params.empty()){
        m_hasError = true;
        m_errorString = "usage: jinn <command branch> <command> <options>\nsee jinn help for more indormation";
        return false;
    }

    QJS tree=Command::cmdTree();
    QString branch = params.at(0);
    if(!tree[branch].isNull()){
        m_branch = branch;
        params.removeFirst();
        if(params.empty()){
            m_hasError = true;
            m_errorString = "";
            return false;
        }
        QString oper = params.at(0);
        if(!tree[branch][oper].isNull()){
            m_oper = oper;
        }
    }
    else{
        m_hasError = true;
        m_errorString = "";
    }

    return !m_hasError;
}

bool Command::exec()
{
    if(!m_hasError){
        if(m_branch == "project"){

        }
        if(m_branch == "module"){
            if(m_oper=="list"){
                m_hasError = !m_cmdExecutor->listModule(&m_response);
            }
            if(m_oper=="install"){

            }
            if(m_oper=="remove"){

            }
        }
        if(m_branch == "config"){

        }
        if(m_branch == "help"){

        }
        if(m_branch == "log"){

        }

        if(m_hasError){
            m_errorString = "grust";
        }
    }
    return !m_hasError;
}

bool Command::hasError()
{
    return m_hasError;
}

QString Command::error()
{
    return m_errorString;
}

QByteArray Command::response()
{
    return m_response;
}


QJS &Command::cmdTree()
{
    QJS *tree = new QJS();
    (*tree)["project"]["add"]["path"]["-h"]=QJS::Null;
    (*tree)["project"]["list"]["-h"]=QJS::Null;
    (*tree)["project"]["remove"]["name"]["-h"]=QJS::Null;

    (*tree)["module"]["install"]["path"]["-h"]=QJS::Null;
    (*tree)["module"]["list"]["-h"]=QJS::Null;
    (*tree)["module"]["remove"]["-h"]["name"]=QJS::Null;

    (*tree)["config"]["set"]["cpw"]=QJS::Null;
    (*tree)["config"]["set"]["wc"]=QJS::Null;

    (*tree)["help"]=QJS::Null;

    return *tree;
}

