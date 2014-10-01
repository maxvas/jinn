#-------------------------------------------------
#
# Project created by QtCreator 2014-08-11T15:59:24
#
#-------------------------------------------------

QT -= gui
QT += network

DESTDIR = $$PWD"/../bin"
TARGET = proxy
TEMPLATE = lib

DEFINES += LIBRARY

INCLUDEPATH += "../../jinn_api"
LIBS += -L"../../../bin" -ljinn_api

INCLUDEPATH += "../../qhttpparser"
LIBS += -L"../../../bin" -lqhttpparser

INCLUDEPATH += "../../../../qjs/src"
LIBS += -L"../../../../qjs/bin" -lqjs

SOURCES += \
    proxymodule.cpp \
    proxyprocessor.cpp

HEADERS +=\
#    global.h \
    proxymodule.h \
    proxyprocessor.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
