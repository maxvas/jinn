QT       += gui

DESTDIR = ../../bin

TARGET = qhttpparser
TEMPLATE = lib
DEFINES += QHTTPPARSER_LIBRARY

SOURCES += \
    qhttprequest.cpp \
    qhttppart.cpp \
    qhttpresponse.cpp \
    qhttpheaderslist.cpp \
    qhttpheader.cpp \
    qhttpmanipulator.cpp \
    qhttprequestparser.cpp \
    qhttpresponseparser.cpp

HEADERS += \
    qhttprequest.h \
    qhttppart.h \
    qhttpresponse.h \
    statuses.h \
    qhttpstatuscodes.h \
    qhttpheaderslist.h \
    qhttpheader.h \
    qhttpmanipulator.h \
    qhttpparser_global.h \
    qhttprequestparser.h \
    QHttpRequestParser \
    qhttpresponseparser.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    QHttpRequest \
    QHttpResponse \
    QHttpStatusCodes \
    QHttpHeadersList \
    QHttpHeader
