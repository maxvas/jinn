TEMPLATE = subdirs

#Lets build projects in order of it's enumeration in SUBDIRS variable
CONFIG += ordered

SUBDIRS += \
    ../../qjs/src/qjs.pro \
    qhttpparser/qhttpparser.pro \
    jinn_api \
    jinn_core \
    modules \
    jinn_client
