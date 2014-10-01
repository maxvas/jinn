QT       += network
QT       -= gui

TEMPLATE = app
DESTDIR = ../../bin

INCLUDEPATH += "../../../qjs/src"
LIBS += -L"../../../qjs/bin" -lqjs

INCLUDEPATH += "../qhttpparser"
LIBS += -L"../../bin" -lqhttpparser

INCLUDEPATH += "../jinn_api"
LIBS += -L"../../bin" -ljinn_api

include(../qtservice/src/qtservice.pri)

SOURCES += \
    main.cpp \
    qhttpworker.cpp \
    qweblistener.cpp \
    qtcpportlistener.cpp \
    qwebserver.cpp \
    jinnservice.cpp

HEADERS += \
    qhttpworker.h \
    qweblistener.h \
    qtcpportlistener.h \
    qwebserver.h \
    jinnservice.h
