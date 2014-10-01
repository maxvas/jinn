#ifndef QHTTPSTATUSCODES_H
#define QHTTPSTATUSCODES_H

#include "qhttpparser_global.h"

class QHTTPPARSERSHARED_EXPORT QHttpStatusCodes
{
public:
    enum{
        OK = 200,
        MovedTemporarily = 302,
        BadRequest = 400,
        Unauthorized = 401,
        Forbidden = 403,
        NotFound = 404,
        BadGateway = 502
    };
};

#endif // QHTTPSTATUSCODES_H
