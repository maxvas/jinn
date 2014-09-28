#ifndef JINN_API_GLOBAL_H
#define JINN_API_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(JINN_API_LIBRARY)
#  define JINN_APISHARED_EXPORT Q_DECL_EXPORT
#else
#  define JINN_APISHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // JINN_API_GLOBAL_H
