#ifndef REQUESTPROCESSOR_H
#define REQUESTPROCESSOR_H

#include "jinn_api_global.h"
#include <qhttpmanipulator.h>
#include <QByteArray>
#include <QJS>
#include <QWebGlobalData>

class QHttpManipulator;

class RequestProcessor
{
public:

    virtual QString settingsName(){
        return "settings";
    }

    virtual bool init(QWebGlobalData *global){
        (void)global;
        return true;
    }
    virtual bool checkUrl(QString url, QWebProject *project){
        (void)url;
        (void)project;
        return false;
    }
    virtual void headerRecieved(QHttpManipulator *http, QJS &settings){
        (void)http;
        (void)settings;
    }
    virtual void bodyRecieved(QHttpManipulator *http, QJS &settings){
        (void)http;
        (void)settings;
    }
    virtual void bodyDataBlockRecieved(QByteArray data, QJS &settings){
        (void)data;
        (void)settings;
    }
    virtual void beforeSendHeaders(QHttpManipulator *http, QJS &settings){
        (void)http;
        (void)settings;
    }
    virtual void beforeFinished(QJS &settings){
        (void)settings;
    }
    virtual void clear(){
    }

    QWebGlobalData *global;

};

#endif // REQUESTPROCESSOR_H
