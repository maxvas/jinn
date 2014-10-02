#-------------------------------------------------
#
# Project created by QtCreator 2014-07-21T10:32:57
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_requesttest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += "../../src"
LIBS += -L"../../bin" -lqhttpparser

SOURCES += tst_requesttest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
