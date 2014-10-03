#ifndef TESTCONTENTPROCESSOR_H
#define TESTCONTENTPROCESSOR_H

#include <requestprocessor.h>
#include <QString>
#include <QJS>

class ManagerProcessor : public RequestProcessor
{
public:
    bool checkUrl(QString url, QJS &settings, QWebProject &project);
    void bodyRecieved(QHttpManipulator *http, QJS &settings);
    bool init(QWebGlobalData *global);
private:
    QWebServerSettings serverSettings;
};

#endif // TESTCONTENTPROCESSOR_H
