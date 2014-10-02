#ifndef TESTCONTENTPROCESSOR_H
#define TESTCONTENTPROCESSOR_H

#include <requestprocessor.h>
#include <QString>
#include <QJS>

class TestProcessor : public RequestProcessor
{
public:
    bool checkUrl(QString url, QWebProject *settings);
    void headerRecieved(QHttpManipulator *http, QJS &settings);
    void bodyRecieved(QHttpManipulator *http, QJS &settings);
};

#endif // TESTCONTENTPROCESSOR_H
