#ifndef MOD_PROXY_GLOBAL_H
#define MOD_PROXY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MOD_PROXY_LIBRARY)
#  define MOD_PROXYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MOD_PROXYSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MOD_PROXY_GLOBAL_H
