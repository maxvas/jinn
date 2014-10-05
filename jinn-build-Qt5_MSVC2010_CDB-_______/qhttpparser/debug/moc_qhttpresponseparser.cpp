/****************************************************************************
** Meta object code from reading C++ file 'qhttpresponseparser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/qhttpparser/qhttpresponseparser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qhttpresponseparser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QHttpResponseParser_t {
    QByteArrayData data[9];
    char stringdata[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QHttpResponseParser_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QHttpResponseParser_t qt_meta_stringdata_QHttpResponseParser = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 14),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 12),
QT_MOC_LITERAL(4, 49, 21),
QT_MOC_LITERAL(5, 71, 4),
QT_MOC_LITERAL(6, 76, 17),
QT_MOC_LITERAL(7, 94, 8),
QT_MOC_LITERAL(8, 103, 8)
    },
    "QHttpResponseParser\0headerRecieved\0\0"
    "bodyRecieved\0bodyDataBlockRecieved\0"
    "data\0beforeSendHeaders\0sendData\0"
    "finished\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QHttpResponseParser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x05,
       3,    0,   45,    2, 0x05,
       4,    1,   46,    2, 0x05,
       6,    0,   49,    2, 0x05,
       7,    1,   50,    2, 0x05,
       8,    0,   53,    2, 0x05,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void,

       0        // eod
};

void QHttpResponseParser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QHttpResponseParser *_t = static_cast<QHttpResponseParser *>(_o);
        switch (_id) {
        case 0: _t->headerRecieved(); break;
        case 1: _t->bodyRecieved(); break;
        case 2: _t->bodyDataBlockRecieved((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->beforeSendHeaders(); break;
        case 4: _t->sendData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->finished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QHttpResponseParser::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QHttpResponseParser::headerRecieved)) {
                *result = 0;
            }
        }
        {
            typedef void (QHttpResponseParser::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QHttpResponseParser::bodyRecieved)) {
                *result = 1;
            }
        }
        {
            typedef void (QHttpResponseParser::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QHttpResponseParser::bodyDataBlockRecieved)) {
                *result = 2;
            }
        }
        {
            typedef void (QHttpResponseParser::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QHttpResponseParser::beforeSendHeaders)) {
                *result = 3;
            }
        }
        {
            typedef void (QHttpResponseParser::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QHttpResponseParser::sendData)) {
                *result = 4;
            }
        }
        {
            typedef void (QHttpResponseParser::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QHttpResponseParser::finished)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject QHttpResponseParser::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QHttpResponseParser.data,
      qt_meta_data_QHttpResponseParser,  qt_static_metacall, 0, 0}
};


const QMetaObject *QHttpResponseParser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QHttpResponseParser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QHttpResponseParser.stringdata))
        return static_cast<void*>(const_cast< QHttpResponseParser*>(this));
    return QObject::qt_metacast(_clname);
}

int QHttpResponseParser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QHttpResponseParser::headerRecieved()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QHttpResponseParser::bodyRecieved()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QHttpResponseParser::bodyDataBlockRecieved(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QHttpResponseParser::beforeSendHeaders()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void QHttpResponseParser::sendData(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QHttpResponseParser::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
