/****************************************************************************
** Meta object code from reading C++ file 'qtcpportlistener.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/jinnd/qtcpportlistener.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtcpportlistener.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QTcpPortListener_t {
    QByteArrayData data[6];
    char stringdata[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QTcpPortListener_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QTcpPortListener_t qt_meta_stringdata_QTcpPortListener = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 13),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 4),
QT_MOC_LITERAL(4, 37, 7),
QT_MOC_LITERAL(5, 45, 16)
    },
    "QTcpPortListener\0newConnection\0\0port\0"
    "qintptr\0socketDescriptor\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTcpPortListener[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x05,

 // signals: parameters
    QMetaType::Void, QMetaType::Short, 0x80000000 | 4,    3,    5,

       0        // eod
};

void QTcpPortListener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QTcpPortListener *_t = static_cast<QTcpPortListener *>(_o);
        switch (_id) {
        case 0: _t->newConnection((*reinterpret_cast< qint16(*)>(_a[1])),(*reinterpret_cast< qintptr(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QTcpPortListener::*_t)(qint16 , qintptr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QTcpPortListener::newConnection)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QTcpPortListener::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_QTcpPortListener.data,
      qt_meta_data_QTcpPortListener,  qt_static_metacall, 0, 0}
};


const QMetaObject *QTcpPortListener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTcpPortListener::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QTcpPortListener.stringdata))
        return static_cast<void*>(const_cast< QTcpPortListener*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int QTcpPortListener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void QTcpPortListener::newConnection(qint16 _t1, qintptr _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
