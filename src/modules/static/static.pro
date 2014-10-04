include(../dependencies.pri)

QT       -= gui

TARGET = static
TEMPLATE = lib

DEFINES += LIBRARY

SOURCES += \
    staticprocessor.cpp \
    staticmodule.cpp

HEADERS +=\
    staticmodule.h \
    staticprocessor.h
