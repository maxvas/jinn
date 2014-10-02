#ifndef QWEBGLOBALDATA_H
#define QWEBGLOBALDATA_H

#include "QJSMapping"
#include <QJSSharedNode>
#include <QDir>
#include "websettings/qwebserversettings.h"
#include "core_global.h"

class JINN_CORESHARED_EXPORT QWebGlobalData : public QJSSharedNode
{
    Q_OBJECT
public:
    QWebGlobalData(QString settingsFileName);
    QWebGlobalData(QByteArray initData);
    void readSettings();
    QJS_MAPPING_OBJECT("settings", settings, setSettings, QWebServerSettings)
    QJS_MAPPING_QSTRING("settingsFileName", settingsFileName, setSettingsFileName)
    QJS_MAPPING_QSTRING("dir", dir, setDir)

private:
    void doneConnects();

signals:

public slots:
    void saveSettings();

};

#endif // QWEBGLOBALDATA_H
