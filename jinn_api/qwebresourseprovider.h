#ifndef QWEBRESOURSEPROVIDER_H
#define QWEBRESOURSEPROVIDER_H

#include <QObject>
#include <QHttpRequest>
#include <QHttpResponse>
#include <QWebGlobalData>
#include "qhttpmanipulator.h"
#include "requestprocessor.h"
#include "jinnmodule.h"

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

private:
    QHash< QString, JinnModule* >  modules;
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

signals:

public slots:
    void headerRecieved(qint16 port, QHttpRequest *request, QHttpResponse *response);
    void dataBlockRecieved(QByteArray data);
    void bodyRecieved();
    void beforeSendHeaders();
    void free();

};

#endif // QWEBRESOURSEPROVIDER_H
