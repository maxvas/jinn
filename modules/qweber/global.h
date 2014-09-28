#ifndef QWEBER_GLOBAL_H
#define QWEBER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QWEBER_LIBRARY)
#  define SHARED_EXPORT Q_DECL_EXPORT
#else
#  define SHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QWEBER_GLOBAL_H
