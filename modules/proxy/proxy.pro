#-------------------------------------------------
#
# Project created by QtCreator 2014-08-11T15:59:24
#
#-------------------------------------------------

QT       -= gui
QT       += network

DESTDIR = ../bin
TARGET = proxy
TEMPLATE = lib

DEFINES += LIBRARY

INCLUDEPATH += "../../jinn_api"
LIBS += -L"../../bin" -ljinn_api

INCLUDEPATH += "../../../qhttpparser/src"
LIBS += -L"../../../qhttpparser/bin" -lqhttpparser

INCLUDEPATH += "../../../qjs/src"
LIBS += -L"../../../qjs/bin" -lqjs

SOURCES += \
    module.cpp \
    contentprocessor.cpp

HEADERS +=\
#    global.h \
    module.h \
    contentprocessor.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
