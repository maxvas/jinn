#-------------------------------------------------
#
# Project created by QtCreator 2014-08-11T00:03:41
#
#-------------------------------------------------

QT       -= gui

TARGET = qweber
TEMPLATE = lib

DEFINES += QWEBER_LIBRARY
include(../dependencies.pri)

SOURCES += qweber.cpp \
    qwebercontentprocessor.cpp

HEADERS += qweber.h\
        global.h \
    qwebercontentprocessor.h
