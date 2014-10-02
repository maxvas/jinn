QT       += network
QT       -= gui

TEMPLATE = app
DESTDIR = ../../bin
TARGET = jinnd

INCLUDEPATH += "../../../qjs/src"
LIBS += -L"../../../qjs/bin" -lqjs

INCLUDEPATH += "../qhttpparser"
LIBS += -L"../../bin" -lqhttpparser

INCLUDEPATH += "../core"
LIBS += -L"../../bin" -lcore

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
