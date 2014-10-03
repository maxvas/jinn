#-------------------------------------------------
#
# Project created by QtCreator 2014-08-11T00:03:41
#
#-------------------------------------------------

QT       -= gui

DESTDIR = $$PWD"/../bin"
TARGET = manager
TEMPLATE = lib

DEFINES += LIBRARY

include(../dependencies.pri)

SOURCES += \
    managermodule.cpp \
    managerprocessor.cpp \
    command.cpp \
    commandexecutor.cpp

HEADERS +=\
#    global.h
    managermodule.h \
    managerprocessor.h \
    command.h \
    commandexecutor.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
