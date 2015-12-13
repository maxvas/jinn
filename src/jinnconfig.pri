#В этом файле задаются пути, которые будут использоваться для сборки и установки jinn
DESTDIR = $$top_srcdir/../bin
#1. Задаем значения по умолчанию (они же будут использоваться и для Windows)
PATH_PACK = $$top_srcdir/../package/default/build
PATH_LIB = $$PATH_PACK
PATH_INCLUDE = $$PATH_PACK/include
PATH_BIN = $$PATH_PACK

#2. Задаем значения для UNIX
unix{
    PATH_PACK = $$top_srcdir/../package/unix/build
    PATH_LIB = /usr/lib
    PATH_INCLUDE = /usr/include
    PATH_BIN = /usr/bin
}
win32{
    PATH_PACK = $$top_srcdir/../package/win32/build
    PATH_LIB = $$PATH_PACK
    PATH_INCLUDE = $$PATH_PACK/include
    PATH_BIN = $$PATH_PACK
}
#3. Устанавливаем переменную QTDIR
defineReplace(findQtDir){
    QTDIR=$$(QTDIR)
    !isEmpty(QTDIR){
        #message("Enviroment variable QTDIR has been setted. So, we simple use it")
        #message(QTDIR=$${QTDIR})
        return($${QTDIR}/bin);
    }
    message(Enviroment variable QTDIR is empty. We will try to get it by parsing PATH variable)
    PATH = $$(PATH)
        win32{
                PATH_PARTS = $$split(PATH, ;)
        }else{
                PATH_PARTS = $$split(PATH, :)
        }
    FOUND = $$find(PATH_PARTS, Qt.*bin$)
    FOUND = $$first(FOUND)
    isEmpty(FOUND){
        error("Can't extract QTDIR from PATH")
    }
        message($$FOUND)
        FOUND2 = $${FOUND}$$QMAKE_DIR_SEP".."$$QMAKE_DIR_SEP
        message($$FOUND2)
    QTDIR=$$clean_path($$FOUND2)
    message(QTDIR=$$QTDIR)
    return($$QTDIR)
}
QTDIR=$$findQtDir()
#Делаем все пути красивыми
PATH_PACK=$$clean_path($$absolute_path($$PATH_PACK))
PATH_LIB=$$clean_path($$absolute_path($$PATH_LIB))
PATH_INCLUDE=$$clean_path($$absolute_path($$PATH_INCLUDE))
PATH_BIN=$$clean_path($$absolute_path($$PATH_BIN))
#message(PATH_PACK=$$PATH_PACK)
#message(PATH_LIB=$$PATH_LIB)
#message(PATH_INCLUDE=$$PATH_INCLUDE)
#message(PATH_BIN=$$PATH_BIN)
#message($$QTDIR)
