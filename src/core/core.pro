#-------------------------------------------------
#
# Project created by QtCreator 2014-08-10T21:16:25
#
#-------------------------------------------------

QT       -= gui
QT       += network

DESTDIR = ../../bin

TARGET = jinn
TEMPLATE = lib

DEFINES += JINN_CORE_LIBRARY

CONFIG += qjs

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
    requestprocessor.h \
    core_global.h

unix {
    target.path = /usr/lib
    includes.path =  /usr/include/jinn
    includes.files = $$HEADERS
} else {
    target.path = $$PWD/../install/lib
    includes.path =  $$PWD/../install/include
    includes.files = $$HEADERS
}
features_dir = $$(QTDIR)/mkspecs/features
jinn_feature.path = $$(QTDIR)/mkspecs/features
jinn_feature.files = jinn.prf
unix{
        jinn_feature.extra += echo "INCLUDEPATH += /usr/include/jinn" > jinn.prf && echo "LIBS += -L/usr/lib/jinn -ljinn" >> jinn.prf
}
win32{
        jinn_feature.extra += echo "INCLUDEPATH += \"$$PWD/../install/lib\"" > jinn.prf & echo "LIBS += -L\"$$PWD/../install/lib\" -ljinn" >> jinn.prf
}
INSTALLS += target includes jinn_feature
QMAKE_CLEAN += jinn.prf
QMAKE_CLEAN += -r $${DESTDIR}
unix {
    QMAKE_CLEAN += /usr/lib/*$${TARGET}*
    QMAKE_CLEAN += -r /usr/include/jinn
} else {
    QMAKE_CLEAN += -r $$PWD/../install/lib
    QMAKE_CLEAN += -r $$PWD/../install/include
}
QMAKE_CLEAN += $$(QTDIR)/mkspecs/features/jinn.prf
