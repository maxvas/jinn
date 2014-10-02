#ifndef TESTCONTENTPROCESSOR_H
#define TESTCONTENTPROCESSOR_H

#include <requestprocessor.h>
#include <QString>
#include <QJS>

class StaticProcessor : public RequestProcessor
{
public:
    StaticProcessor();
    bool init(QWebGlobalData *global);
    bool checkUrl(QString url, QJS &settings, QWebProject &project);
    QString settingsName();
    void headerRecieved(QHttpManipulator *http, QJS &settings);
private:
    void loadMimeTypes(QString path);
    void sendFile(QHttpManipulator *http);
    QHash<QString, QString> mimeTypes;
    QString filePath;
    QList<QString> suffixes;

};

#endif // TESTCONTENTPROCESSOR_H
