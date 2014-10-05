/****************************************************************************
** Meta object code from reading C++ file 'qwebresourseprovider.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/core/qwebresourseprovider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwebresourseprovider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QWebResourseProvider_t {
    QByteArrayData data[18];
    char stringdata[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QWebResourseProvider_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QWebResourseProvider_t qt_meta_stringdata_QWebResourseProvider = {
    {
QT_MOC_LITERAL(0, 0, 20),
QT_MOC_LITERAL(1, 21, 14),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 4),
QT_MOC_LITERAL(4, 42, 13),
QT_MOC_LITERAL(5, 56, 7),
QT_MOC_LITERAL(6, 64, 14),
QT_MOC_LITERAL(7, 79, 8),
QT_MOC_LITERAL(8, 88, 17),
QT_MOC_LITERAL(9, 106, 4),
QT_MOC_LITERAL(10, 111, 12),
QT_MOC_LITERAL(11, 124, 17),
QT_MOC_LITERAL(12, 142, 4),
QT_MOC_LITERAL(13, 147, 20),
QT_MOC_LITERAL(14, 168, 11),
QT_MOC_LITERAL(15, 180, 9),
QT_MOC_LITERAL(16, 190, 11),
QT_MOC_LITERAL(17, 202, 11)
    },
    "QWebResourseProvider\0headerRecieved\0"
    "\0port\0QHttpRequest*\0request\0QHttpResponse*\0"
    "response\0dataBlockRecieved\0data\0"
    "bodyRecieved\0beforeSendHeaders\0free\0"
    "onModulesListChanged\0addressData\0"
    "operation\0newDataData\0oldDataData\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QWebResourseProvider[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x0a,
       8,    1,   51,    2, 0x0a,
      10,    0,   54,    2, 0x0a,
      11,    0,   55,    2, 0x0a,
      12,    0,   56,    2, 0x0a,
      13,    4,   57,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::Short, 0x80000000 | 4, 0x80000000 | 6,    3,    5,    7,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QString, QMetaType::QByteArray, QMetaType::QByteArray,   14,   15,   16,   17,

       0        // eod
};

void QWebResourseProvider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QWebResourseProvider *_t = static_cast<QWebResourseProvider *>(_o);
        switch (_id) {
        case 0: _t->headerRecieved((*reinterpret_cast< qint16(*)>(_a[1])),(*reinterpret_cast< QHttpRequest*(*)>(_a[2])),(*reinterpret_cast< QHttpResponse*(*)>(_a[3]))); break;
        case 1: _t->dataBlockRecieved((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->bodyRecieved(); break;
        case 3: _t->beforeSendHeaders(); break;
        case 4: _t->free(); break;
        case 5: _t->onModulesListChanged((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3])),(*reinterpret_cast< QByteArray(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QHttpRequest* >(); break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QHttpResponse* >(); break;
            }
            break;
        }
    }
}

const QMetaObject QWebResourseProvider::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QWebResourseProvider.data,
      qt_meta_data_QWebResourseProvider,  qt_static_metacall, 0, 0}
};


const QMetaObject *QWebResourseProvider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QWebResourseProvider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QWebResourseProvider.stringdata))
        return static_cast<void*>(const_cast< QWebResourseProvider*>(this));
    return QObject::qt_metacast(_clname);
}

int QWebResourseProvider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
