#ifndef QHTTPPARSER_GLOBAL_H
#define QHTTPPARSER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QHTTPPARSER_LIBRARY)
#  define QHTTPPARSERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QHTTPPARSERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QHTTPPARSER_GLOBAL_H
