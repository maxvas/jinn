#-------------------------------------------------
#
# Project created by QtCreator 2014-08-10T21:16:25
#
#-------------------------------------------------

QT       -= gui
QT       += network

DESTDIR = ../../bin

TARGET = jinn_api
TEMPLATE = lib

DEFINES += JINN_API_LIBRARY

INCLUDEPATH += "../../../qjs/src"
LIBS += -L"../../../qjs/bin" -lqjs

INCLUDEPATH += "../qhttpparser"
LIBS += -L"../../bin" -lqhttpparser

SOURCES += jinnmodule.cpp \
    websettings/qwebcontentpath.cpp \
    websettings/qwebhost.cpp \
    websettings/qwebmodule.cpp \
    websettings/qwebmodulelink.cpp \
    websettings/qwebproject.cpp \
    websettings/qwebserversettings.cpp \
    qwebglobaldata.cpp \
    qwebprocessor.cpp \
    qwebresourseprovider.cpp

HEADERS += jinnmodule.h\
        jinn_api_global.h \
    websettings/qwebcontentpath.h \
    websettings/QWebHost \
    websettings/qwebhost.h \
    websettings/QWebModule \
    websettings/qwebmodule.h \
    websettings/QWebModuleLink \
    websettings/qwebmodulelink.h \
    websettings/QWebProject \
    websettings/qwebproject.h \
    websettings/qwebproxy.h \
    websettings/QWebServerSettings \
    websettings/qwebserversettings.h \
    qwebglobaldata.h \
    qwebprocessor.h \
    qwebresourseprovider.h \
    QWebGlobalData \
    requestprocessor.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
