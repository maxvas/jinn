include($$top_srcdir/jinnconfig.pri)

QT       -= gui
QT       += network

TARGET = jinn
TEMPLATE = lib

DEFINES += JINN_CORE_LIBRARY

CONFIG += qjs

INCLUDEPATH += "../qhttpparser"
LIBS += -L$$DESTDIR -lqhttpparser

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

#На шаге INSTALL мы копируем собранную библиотеку туда, где должны храниться библиотеки
target.path = $$PATH_LIB
#Копируем заголовочные файлы
includes.path =  $$PATH_INCLUDE/jinn
includes.files = $$HEADERS
#Создаем фичу QT для написания модулей Jinn
prffile = $${QTDIR}/mkspecs/features/jinnmodule.prf
unix{
    feature.path = $${OUT_PWD}
    feature.files = $$prffile
    feature.extra += echo "CONFIG += qjs qhttpparser" > $$prffile &&\
        echo "INCLUDEPATH += $$PATH_INCLUDE/jinn" >> $$prffile $$\
        echo "LIBS += -L$$PATH_LIB -ljinn" >> $$prffile &&\
        echo "target.path = /usr/share/jinn/modules" >> $$prffile $$\
        echo "INSTALLS += target" >> $$prffile
}
win32{
    feature.path = $${OUT_PWD}
    feature.files = $$prffile
    feature.extra += echo "CONFIG += qjs qhttpparser" > $$prffile echo "INCLUDEPATH += $$PATH_INCLUDE/jinn" >> $$prffile echo "LIBS += -L$$PATH_LIB -ljinn" >> $$prffile
}

INSTALLS += target includes feature
#Шаг clean
QMAKE_CLEAN += $$PATH_LIB/*$${TARGET}*
QMAKE_CLEAN += -r $$PATH_INCLUDE/jinn
QMAKE_CLEAN += $$prffile
