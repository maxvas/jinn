include(../dependencies.pri)

QT       -= gui

TARGET = manager
TEMPLATE = lib

DEFINES += LIBRARY

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
