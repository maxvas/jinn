#ifndef QWEBER_CONTENTPROCESSOR_H
#define QWEBER_CONTENTPROCESSOR_H

#include <requestprocessor.h>
#include <QString>
#include <QJS>

class QWeberContentProcessor : public RequestProcessor
{
public:
    bool checkUrl(QString url, QJS &settings);
    void headerRecieved(QHttpManipulator *http, QJS &settings);
};

#endif // QWEBER_CONTENTPROCESSOR_H
