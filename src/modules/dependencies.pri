DESTDIR = $$top_srcdir/../bin/modules

INCLUDEPATH += "../../core"
LIBS += -L$$top_srcdir/../bin -ljinn

INCLUDEPATH += "../../qhttpparser"
LIBS += -L$$top_srcdir/../bin -lqhttpparser

CONFIG += qjs

unix {
    target.path = /usr/share/jinn/modules
} else {
    target.path = $$PATH_PACK/modules
}
INSTALLS += target
QMAKE_CLEAN += $${DESTDIR}/$${TARGET}
unix {
    QMAKE_CLEAN += /usr/share/jinn/modules/*$${TARGET}*
}
