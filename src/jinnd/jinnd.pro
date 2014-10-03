QT       += network
QT       -= gui

TEMPLATE = app
DESTDIR = ../../bin
TARGET = jinnd

CONFIG += qjs

INCLUDEPATH += "../qhttpparser"
LIBS += -L"../../bin" -lqhttpparser

INCLUDEPATH += "../core"
LIBS += -L"../../bin" -ljinn

include(../qtservice/src/qtservice.pri)

SOURCES += \
    main.cpp \
    qhttpworker.cpp \
    qweblistener.cpp \
    qtcpportlistener.cpp \
    qwebserver.cpp \
    jinnservice.cpp

HEADERS += \
    qhttpworker.h \
    qweblistener.h \
    qtcpportlistener.h \
    qwebserver.h \
    jinnservice.h

unix {
    target.path = /usr/bin
    configs.path =  /etc/jinn
    configs.files = $${PWD}/../../distr/linux/config/*
} else {
    target.path = $$PWD/../install/lib
}
INSTALLS += target configs
QMAKE_CLEAN += -r $${DESTDIR}
unix {
    QMAKE_CLEAN += /usr/bin/*$${TARGET}*
}
