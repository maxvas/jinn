#-------------------------------------------------
#
# Project created by QtCreator 2014-08-11T15:59:24
#
#-------------------------------------------------

QT       -= gui
QT       += network

DESTDIR = ../bin
TARGET = mod_proxy
TEMPLATE = lib

DEFINES += MOD_PROXY_LIBRARY

INCLUDEPATH += "../../anuta_api"
LIBS += -L"../../bin" -lanuta_api

INCLUDEPATH += "../../../qhttpparser/src"
LIBS += -L"../../../qhttpparser/bin" -lqhttpparser

INCLUDEPATH += "../../../qjs/src"
LIBS += -L"../../../qjs/bin" -lqjs

SOURCES += \
    proxymodule.cpp \
    proxyprocessor.cpp

HEADERS +=\
        mod_proxy_global.h \
    proxymodule.h \
    proxyprocessor.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
