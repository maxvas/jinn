#ifndef TESTCONTENTPROCESSOR_H
#define TESTCONTENTPROCESSOR_H

#include <requestprocessor.h>
#include <QString>
#include <QJS>

class ContentProcessor : public RequestProcessor
{
public:
    bool checkUrl(QString url, QJS &settings);
    QString settingsName();
    void headerRecieved(QHttpManipulator *http, QJS &settings);
};

#endif // TESTCONTENTPROCESSOR_H
