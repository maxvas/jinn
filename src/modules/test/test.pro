include(../dependencies.pri)

QT       -= gui

TARGET = test
TEMPLATE = lib

DEFINES += LIBRARY

SOURCES += \
    testmodule.cpp \
    testprocessor.cpp

HEADERS +=\
#    global.h
    testmodule.h \
    testprocessor.h
