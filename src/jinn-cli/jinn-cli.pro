include($$top_srcdir/jinnconfig.pri)

QT       += core network
QT       -= gui

TARGET = jinn

TEMPLATE = app

SOURCES += main.cpp \
    jinnclient.cpp

HEADERS += \
    jinnclient.h

#Шаг install
target.path = $$PATH_BIN
INSTALLS += target
QMAKE_CLEAN += $${DESTDIR}/$${TARGET}
unix {
    QMAKE_CLEAN += /usr/bin/$${TARGET}
}
