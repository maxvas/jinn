include(../dependencies.pri)

QT       -= gui

TARGET = qweber
TEMPLATE = lib

DEFINES += QWEBER_LIBRARY

SOURCES += qweber.cpp \
    qwebercontentprocessor.cpp

HEADERS += qweber.h\
        global.h \
    qwebercontentprocessor.h
