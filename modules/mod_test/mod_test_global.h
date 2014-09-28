#ifndef MOD_TEST_GLOBAL_H
#define MOD_TEST_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MOD_TEST_LIBRARY)
#  define MOD_TESTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MOD_TESTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MOD_TEST_GLOBAL_H
