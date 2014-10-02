#ifndef QHTTPMANIPULATOR_H
#define QHTTPMANIPULATOR_H

#include "QHttpRequest"
#include "QHttpResponse"
#include "QHttpStatusCodes"
#include "qhttpparser_global.h"

class QHTTPPARSERSHARED_EXPORT QHttpManipulator
{
public:
    QHttpManipulator();
    QHttpRequest *request();
    QHttpResponse *response();

    void responseCode(int code);
    void header(QString header);
    void echo(QString string);
private:
    friend class QWebResourseProvider;
    QHttpRequest* m_request;
    QHttpResponse* m_response;
    void setRequestResponse(QHttpRequest* request, QHttpResponse* response);
    void finish();
    void finishWithoutSendingHeaders();
    void free();
};

#endif // QHTTPMANIPULATOR_H
