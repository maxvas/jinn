#-------------------------------------------------
#
# Project created by QtCreator 2014-08-11T00:03:41
#
#-------------------------------------------------

QT       -= gui

DESTDIR = ../bin
TARGET = test
TEMPLATE = lib

DEFINES += LIBRARY

INCLUDEPATH += "../../jinn_api"
LIBS += -L"../../bin" -ljinn_api

INCLUDEPATH += "../../../qhttpparser/src"
LIBS += -L"../../../qhttpparser/bin" -lqhttpparser

INCLUDEPATH += "../../../qjs/src"
LIBS += -L"../../../qjs/bin" -lqjs

SOURCES += \
    testmodule.cpp \
    testprocessor.cpp

HEADERS +=\
#    global.h
    testmodule.h \
    testprocessor.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
