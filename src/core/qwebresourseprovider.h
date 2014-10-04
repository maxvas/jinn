#ifndef QWEBRESOURSEPROVIDER_H
#define QWEBRESOURSEPROVIDER_H

#include <QObject>
#include <QHttpRequest>
#include <QHttpResponse>
#include "qwebglobaldata.h"
#include "qhttpmanipulator.h"
#include "requestprocessor.h"
#include "jinnmodule.h"

class QPluginLoader;
class QHttpManipulator;

class QWebResource
{
public:
    enum Type{
        File,
        PHPScript,
        WebHandler,
        RemoteResource
    };
};

class QWebResourseProvider : public QObject
{
    Q_OBJECT
public:
    explicit QWebResourseProvider(QObject *parent, QWebGlobalData* global);
    ~QWebResourseProvider();

private:
    QHash< QString, JinnModule* >  modules;
    QHash< QString, QPluginLoader* >  loaders;
    QHttpManipulator* http;
    QWebGlobalData* global;
    qint16 port;
    QHttpRequest *request;
    QHttpResponse *response;
    QWebProject *project;
    QJS *cpSettings;
    bool findProject(QString host, qint16 port);
    bool findContentProcessor(QString url);
    RequestProcessor *cp;
    void loadModules();
    bool loadModule(QString name);
    bool unloadModule(QString name);

signals:

public slots:
    void headerRecieved(qint16 port, QHttpRequest *request, QHttpResponse *response);
    void dataBlockRecieved(QByteArray data);
    void bodyRecieved();
    void beforeSendHeaders();
    void free();
    void onModulesListChanged(QByteArray addressData, QString operation, QByteArray newDataData, QByteArray oldDataData);

};

#endif // QWEBRESOURSEPROVIDER_H
