#include "qwebglobaldata.h"
#include <QFile>
#include <QFileInfo>

QWebGlobalData::QWebGlobalData(QString settingsFileName) :
    QJSSharedNode()
{
    QFileInfo fileInfo(settingsFileName);
    setSettingsFileName(fileInfo.absoluteFilePath());
    setDir(fileInfo.absolutePath());
    readSettings();
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
    foreach(QJS prjFileItem, this->settings().prjFiles())
    {
        QString fileName = prjFileItem.toString();
        settings().readProjectSettings(fileName);
    }
    this->enableSignals();
}

void QWebGlobalData::saveSettings()
{
    QFile file(settingsFileName());
    if (!file.open(QFile::ReadWrite))
    {
        //TODO: вывод ошибки
        return;
    }
    file.write(this->get("settings").toJson().toUtf8());
    file.close();
}

void QWebGlobalData::doneConnects()
{
    connect(this, SIGNAL(dataChanged(QJS*,QString,QJS*,QJS*)), this, SLOT(saveSettings())); //Автосохранение будет происходить только при локальном изменении данных
}
