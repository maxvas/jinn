TEMPLATE = subdirs

#Lets build projects in order of it's enumeration in SUBDIRS variable
CONFIG += ordered

SUBDIRS += \
    qhttpparser/qhttpparser.pro \
    core \
    jinnd \
    modules \
    jinn-cli
