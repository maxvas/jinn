#include "command.h"


Command::Command(CommandExecutor *cmdExecutor)
    :m_hasError(false),m_cmdExecutor(cmdExecutor)
{
}

void Command::parse(QByteArray &data)
{
    QList<QByteArray> params=data.split('\n');
    params.removeLast();
    if(params.empty()){
        m_hasError = true;
//        m_errorString = "usage: jinn <command branch> <command> <options>\nsee jinn help for more indormation";
        return;
    }

    QJS tree=Command::cmdTree();
    QString branch = params.at(0);
    if(tree[branch]["exist"].toBool()){
        m_branch = branch;
        params.removeFirst();
        if(params.empty()){
            m_hasError = true;
            return;
        }
        QString oper = params.at(0);
        if(tree[branch][oper]["exist"].toBool()){
            m_oper = oper;

            params.removeFirst();
            if(!params.empty()){
                QString opt = params.at(0);
                if(tree[branch][oper][opt].toBool()){
                    m_opt = opt;
                    params.removeFirst();
                }
            }

            if(tree[branch][oper]["args"].toBool()){
                if(params.empty()){
                    m_hasError = true;
                    return;
                }
                m_arg = params.at(0);
            }
        }
    }
    else{
        m_hasError = true;
    }
    if(m_hasError)
        m_response.append("\nThe command is invalid. See jinn help for more information"); //or jinn <command> -h
}

void Command::exec()
{
    if(m_hasError)
        return;
    if(m_branch == "project"){

    }
    if(m_branch == "module"){
        if(m_oper=="list"){
            m_hasError = !m_cmdExecutor->listModule(m_opt=="--all");
        }
        if(m_oper=="install"){
            QString libPath=m_arg;
            m_hasError = !m_cmdExecutor->installModule(libPath);
        }
        if(m_oper=="remove"){
            QString name=m_arg;
            m_hasError = !m_cmdExecutor->removeModule(name);
        }
        if(m_oper=="on"){
            QString name=m_arg;
            m_hasError = !m_cmdExecutor->turnModuleOn(name);
        }
        if(m_oper=="off"){
            QString name=m_arg;
            m_hasError = !m_cmdExecutor->turnModuleOff(name);
        }
    }
    if(m_branch == "config"){

    }
    if(m_branch == "help"){

    }
    if(m_branch == "log"){

    }
    m_response.append(m_cmdExecutor->log());
    if(m_hasError)
        m_response.append("\nthe command failed");
}

bool Command::hasError()
{
    return m_hasError;
}

QByteArray Command::response()
{
    return m_response;
}


QJS &Command::cmdTree()
{
    QJS *tree = new QJS();
    //module branch
    (*tree)["module"]["exist"]=true;

    (*tree)["module"]["list"]["exist"]=true;
    (*tree)["module"]["list"]["--all"]=true;
    (*tree)["module"]["list"]["-h"]=QJS::Null;

    (*tree)["module"]["install"]["exist"]=true;
    (*tree)["module"]["install"]["--off"]=true;
    (*tree)["module"]["install"]["args"]=true;
    (*tree)["module"]["install"]["-h"]=QJS::Null;

    (*tree)["module"]["remove"]["exist"]=true;
    (*tree)["module"]["remove"]["args"]=true;
    (*tree)["module"]["remove"]["-h"]=QJS::Null;

    (*tree)["module"]["on"]["exist"]=true;
    (*tree)["module"]["on"]["args"]=true;
    (*tree)["module"]["on"]["-h"]=QJS::Null;

    (*tree)["module"]["off"]["exist"]=true;
    (*tree)["module"]["off"]["args"]=true;
    (*tree)["module"]["off"]["-h"]=QJS::Null;

    //project branch
    (*tree)["project"]["exist"]=true;

    (*tree)["project"]["list"]["exist"]=true;
    (*tree)["project"]["list"]["-h"]=QJS::Null;

    (*tree)["project"]["add"]["exist"]=true;
    (*tree)["project"]["add"]["args"]=true;
    (*tree)["project"]["add"]["-h"]=QJS::Null;

    (*tree)["project"]["remove"]["exist"]=true;
    (*tree)["project"]["remove"]["args"]=true;
    (*tree)["project"]["remove"]["-h"]=QJS::Null;

    //config branch
    (*tree)["config"]["exist"]=true;

    (*tree)["config"]["set"]["exist"]=true;
    (*tree)["config"]["set"]["opts"]=true;
    (*tree)["config"]["set"]["args"]=true;
    (*tree)["config"]["set"]["cpw"]=true;
    (*tree)["config"]["set"]["wc"]=true;

    (*tree)["config"]["get"]["exist"]=true;
    (*tree)["config"]["get"]["opts"]=true;
    (*tree)["config"]["get"]["cpw"]=true;
    (*tree)["config"]["get"]["wc"]=true;

    //help branch
    (*tree)["help"]["exist"]=true;

    return *tree;
}

