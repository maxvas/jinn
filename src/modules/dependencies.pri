INCLUDEPATH += "../../core"
LIBS += -L"../../../bin" -ljinn

INCLUDEPATH += "../../qhttpparser"
LIBS += -L"../../../bin" -lqhttpparser

CONFIG += qjs

unix {
    target.path = /usr/share/jinn/modules
} else {
    target.path = $$PWD/../../install/modules
}
INSTALLS += target
QMAKE_CLEAN += -r $${DESTDIR}
unix {
    QMAKE_CLEAN += /usr/share/jinn/modules/*$${TARGET}*
}
