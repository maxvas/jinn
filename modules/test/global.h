#ifndef GLOBAL_H
#define GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBRARY)
#  define SHARED_EXPORT Q_DECL_EXPORT
#else
#  define SHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GLOBAL_H
