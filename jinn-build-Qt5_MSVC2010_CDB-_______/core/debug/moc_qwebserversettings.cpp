/****************************************************************************
** Meta object code from reading C++ file 'qwebserversettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/core/websettings/qwebserversettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwebserversettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QWebServerSettings_t {
    QByteArrayData data[7];
    char stringdata[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QWebServerSettings_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QWebServerSettings_t qt_meta_stringdata_QWebServerSettings = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 3),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 1),
QT_MOC_LITERAL(4, 26, 1),
QT_MOC_LITERAL(5, 28, 1),
QT_MOC_LITERAL(6, 30, 1)
    },
    "QWebServerSettings\0bla\0\0a\0s\0d\0f\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QWebServerSettings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   19,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QString, QMetaType::QByteArray, QMetaType::QByteArray,    3,    4,    5,    6,

       0        // eod
};

void QWebServerSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QWebServerSettings *_t = static_cast<QWebServerSettings *>(_o);
        switch (_id) {
        case 0: _t->bla((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3])),(*reinterpret_cast< QByteArray(*)>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObject QWebServerSettings::staticMetaObject = {
    { &QJS::staticMetaObject, qt_meta_stringdata_QWebServerSettings.data,
      qt_meta_data_QWebServerSettings,  qt_static_metacall, 0, 0}
};


const QMetaObject *QWebServerSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QWebServerSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QWebServerSettings.stringdata))
        return static_cast<void*>(const_cast< QWebServerSettings*>(this));
    return QJS::qt_metacast(_clname);
}

int QWebServerSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QJS::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
