#-------------------------------------------------
#
# Project created by QtCreator 2014-08-11T00:03:41
#
#-------------------------------------------------

QT       -= gui

DESTDIR = $$PWD"/../bin"
TARGET = test
TEMPLATE = lib

DEFINES += LIBRARY

include(../dependencies.pri)

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
