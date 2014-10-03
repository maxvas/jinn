#-------------------------------------------------
#
# Project created by QtCreator 2014-08-11T00:03:41
#
#-------------------------------------------------

QT       -= gui

DESTDIR = $$PWD"/../bin"
TARGET = static
TEMPLATE = lib

DEFINES += LIBRARY

include(../dependencies.pri)

SOURCES += \
    staticprocessor.cpp \
    staticmodule.cpp

HEADERS +=\
    staticmodule.h \
    staticprocessor.h
