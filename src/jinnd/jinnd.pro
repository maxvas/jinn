include($$top_srcdir/jinnconfig.pri)
include(../qtservice/src/qtservice.pri)

QT       += core network
QT       -= gui

TEMPLATE = app
TARGET = jinnd

CONFIG += qjs

INCLUDEPATH += "../qhttpparser"
LIBS += -L$$DESTDIR -lqhttpparser

INCLUDEPATH += "../core"
LIBS += -L$$DESTDIR -ljinn

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

#Шаг install
target.path = $$PATH_BIN
QMAKE_CLEAN += $${DESTDIR}/*$${TARGET}*
#Конфиги на линуксе должны копироваться всегда в /etc/jinn
#На Windows конфиги по умолчанию лежат в C:/Programm Files/Jinn, но это не всегда так.
#Поэтому конфиг на Windows будет генерироваться установщиком
unix{
    configs.path =  /etc/jinn
    configs.files = $$top_srcdir/../projects
}
unix{
    projects.path = /srv/jinn
    projects.files = $$top_srcdir/../config/*
}
INSTALLS += target configs projects
#make clean
QMAKE_CLEAN += $${DESTDIR}/*$${TARGET}*
unix {
    QMAKE_CLEAN += /usr/bin/$${TARGET}
    QMAKE_CLEAN += -r /etc/jinn
}
