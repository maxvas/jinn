/****************************************************************************
** Meta object code from reading C++ file 'qwebprocessor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/core/qwebprocessor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwebprocessor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QWebProcessor_t {
    QByteArrayData data[9];
    char stringdata[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QWebProcessor_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QWebProcessor_t qt_meta_stringdata_QWebProcessor = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 8),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 10),
QT_MOC_LITERAL(4, 35, 11),
QT_MOC_LITERAL(5, 47, 4),
QT_MOC_LITERAL(6, 52, 16),
QT_MOC_LITERAL(7, 69, 22),
QT_MOC_LITERAL(8, 92, 20)
    },
    "QWebProcessor\0finished\0\0socketRead\0"
    "socketWrite\0data\0onParserFinished\0"
    "onParserHeaderRecieved\0onSocketDisconnected\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QWebProcessor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08,
       4,    1,   46,    2, 0x08,
       6,    0,   49,    2, 0x08,
       7,    0,   50,    2, 0x08,
       8,    0,   51,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QWebProcessor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QWebProcessor *_t = static_cast<QWebProcessor *>(_o);
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->socketRead(); break;
        case 2: _t->socketWrite((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->onParserFinished(); break;
        case 4: _t->onParserHeaderRecieved(); break;
        case 5: _t->onSocketDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QWebProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QWebProcessor::finished)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QWebProcessor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QWebProcessor.data,
      qt_meta_data_QWebProcessor,  qt_static_metacall, 0, 0}
};


const QMetaObject *QWebProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QWebProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QWebProcessor.stringdata))
        return static_cast<void*>(const_cast< QWebProcessor*>(this));
    return QObject::qt_metacast(_clname);
}

int QWebProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QWebProcessor::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
