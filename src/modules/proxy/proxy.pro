include(../dependencies.pri)

QT -= gui
QT += network

TARGET = proxy
TEMPLATE = lib

DEFINES += LIBRARY

SOURCES += \
    proxymodule.cpp \
    proxyprocessor.cpp

HEADERS +=\
#    global.h \
    proxymodule.h \
    proxyprocessor.h
