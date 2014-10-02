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

include(../dependencies.pri)

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
