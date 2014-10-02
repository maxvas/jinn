#ifndef JINN_API_GLOBAL_H
#define JINN_API_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(JINN_CORE_LIBRARY)
#  define JINN_CORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define JINN_CORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // JINN_API_GLOBAL_H
