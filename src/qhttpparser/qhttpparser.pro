include($$top_srcdir/jinnconfig.pri)

QT += core network
QT -= gui

TARGET = qhttpparser
TEMPLATE = lib
DEFINES += QHTTPPARSER_LIBRARY

SOURCES += \
    qhttprequest.cpp \
    qhttppart.cpp \
    qhttpresponse.cpp \
    qhttpheaderslist.cpp \
    qhttpheader.cpp \
    qhttpmanipulator.cpp \
    qhttprequestparser.cpp \
    qhttpresponseparser.cpp

HEADERS += \
    qhttprequest.h \
    qhttppart.h \
    qhttpresponse.h \
    statuses.h \
    qhttpstatuscodes.h \
    qhttpheaderslist.h \
    qhttpheader.h \
    qhttpmanipulator.h \
    qhttpparser_global.h \
    qhttprequestparser.h \
    QHttpRequestParser \
    qhttpresponseparser.h \
    QHttpRequest \
    QHttpResponse \
    QHttpStatusCodes \
    QHttpHeadersList \
    QHttpHeader

#На шаге INSTALL мы копируем собранную библиотеку туда, где должны храниться библиотеки
target.path = $$PATH_LIB
#Копируем заголовочные файлы
includes.path =  $$PATH_INCLUDE/qhttpparser
includes.files = $$HEADERS
#Создаем фичу QT для написания модулей Jinn
prffile = $${QTDIR}/mkspecs/features/jinnmodule.prf
unix{
    feature.path = $${OUT_PWD}
    feature.files = $$prffile
    feature.extra += echo "INCLUDEPATH += $$PATH_INCLUDE/qhttpparser" >> $$prffile $$\
        echo "LIBS += -L$$PATH_LIB -ljinn" >> $$prffile
}
win32{
    feature.path = $${OUT_PWD}
    feature.files = $$prffile
    feature.extra += echo "CONFIG += qjs qhttpparser" > $$prffile\
        echo "target.path = $$(JINN_MODULES_DIR)" >> $$prffile\
        echo "INCLUDEPATH += $$PATH_INCLUDE/qhttpparser" >> $$prffile\
        echo "LIBS += -L$$PATH_LIB -ljinn" >> $$prffile
}

INSTALLS += target includes feature
#Шаг clean
QMAKE_CLEAN += $$PATH_LIB/*$${TARGET}*
QMAKE_CLEAN += -r $$PATH_INCLUDE/qhttpparser
QMAKE_CLEAN += $$prffile
