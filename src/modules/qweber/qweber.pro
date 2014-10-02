#-------------------------------------------------
#
# Project created by QtCreator 2014-08-11T00:03:41
#
#-------------------------------------------------

QT       -= gui

DESTDIR = $$PWD"/../bin"
TARGET = qweber
TEMPLATE = lib

DEFINES += QWEBER_LIBRARY

INCLUDEPATH += "../../jinn_api"
LIBS += -L"../../../bin" -ljinn_api

INCLUDEPATH += "../../qhttpparser"
LIBS += -L"../../../bin" -lqhttpparser

INCLUDEPATH += "../../../../qjs/src"
LIBS += -L"../../../../qjs/bin" -lqjs

SOURCES += qweber.cpp \
    qwebercontentprocessor.cpp

HEADERS += qweber.h\
        global.h \
    qwebercontentprocessor.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
