#include "qwebglobaldata.h"
#include <QFile>
#include <QFileInfo>
#include <QDebug>

QWebGlobalData::QWebGlobalData(QString settingsFileName) :
    QJSSharedNode()
{
    QFileInfo fileInfo(settingsFileName);
    setSettingsFileName(fileInfo.absoluteFilePath());
    setDir(fileInfo.absolutePath());
    readSettings();
    doneConnects();
}

QWebGlobalData::QWebGlobalData(QByteArray initData):
    QJSSharedNode(initData)
{
}

void QWebGlobalData::readSettings()
{
    this->disableSignals();
    QFile file(settingsFileName());
    if (!file.open(QFile::ReadOnly))
    {
        //TODO: вывод ошибки
        return;
    }
    QString text = file.readAll();
    (*this)["settings"] = QJS::fromJson(text);
    this->settings().loadProjects();
//    foreach(QJS prjFileItem, this->settings().prjFiles())
//    {
//        QString fileName = prjFileItem.toString();
//        settings().readProjectSettings(fileName);
//    }
    this->enableSignals();
}

void QWebGlobalData::saveSettings()
{
    QFile file(settingsFileName());
    if (!file.open(QFile::ReadWrite))
    {
        qDebug()<<"Error on write settings: Can't open file "<<settingsFileName();
        return;
    }
    QJS settings = this->get("settings");
    settings.remove("projects");
    file.write(settings.toJson().toUtf8());
    file.close();
}

void QWebGlobalData::doneConnects()
{
//    connect(this, SIGNAL(dataChanged(QByteArray,QString,QByteArray,QByteArray)), this, SLOT(saveSettings(QByteArray,QString,QByteArray,QByteArray))); //Автосохранение будет происходить только при локальном изменении данных
    connect(this, SIGNAL(changed()), this, SLOT(saveSettings()));
}
