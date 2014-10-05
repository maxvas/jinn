/****************************************************************************
** Meta object code from reading C++ file 'qhttpworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/jinnd/qhttpworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qhttpworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QHttpWorker_t {
    QByteArrayData data[8];
    char stringdata[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QHttpWorker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QHttpWorker_t qt_meta_stringdata_QHttpWorker = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 13),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 4),
QT_MOC_LITERAL(4, 32, 7),
QT_MOC_LITERAL(5, 40, 16),
QT_MOC_LITERAL(6, 57, 19),
QT_MOC_LITERAL(7, 77, 32)
    },
    "QHttpWorker\0newConnection\0\0port\0qintptr\0"
    "socketDescriptor\0onProcessorFinished\0"
    "getConnectionFromQueueAndStartIt\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QHttpWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x0a,
       6,    0,   34,    2, 0x08,
       7,    0,   35,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Short, 0x80000000 | 4,    3,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QHttpWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QHttpWorker *_t = static_cast<QHttpWorker *>(_o);
        switch (_id) {
        case 0: _t->newConnection((*reinterpret_cast< qint16(*)>(_a[1])),(*reinterpret_cast< qintptr(*)>(_a[2]))); break;
        case 1: _t->onProcessorFinished(); break;
        case 2: _t->getConnectionFromQueueAndStartIt(); break;
        default: ;
        }
    }
}

const QMetaObject QHttpWorker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QHttpWorker.data,
      qt_meta_data_QHttpWorker,  qt_static_metacall, 0, 0}
};


const QMetaObject *QHttpWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QHttpWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QHttpWorker.stringdata))
        return static_cast<void*>(const_cast< QHttpWorker*>(this));
    return QObject::qt_metacast(_clname);
}

int QHttpWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_QHttpWorkerThread_t {
    QByteArrayData data[3];
    char stringdata[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QHttpWorkerThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QHttpWorkerThread_t qt_meta_stringdata_QHttpWorkerThread = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 7),
QT_MOC_LITERAL(2, 26, 0)
    },
    "QHttpWorkerThread\0started\0\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QHttpWorkerThread[] = {

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
       1,    0,   19,    2, 0x05,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void QHttpWorkerThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QHttpWorkerThread *_t = static_cast<QHttpWorkerThread *>(_o);
        switch (_id) {
        case 0: _t->started(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QHttpWorkerThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QHttpWorkerThread::started)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QHttpWorkerThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_QHttpWorkerThread.data,
      qt_meta_data_QHttpWorkerThread,  qt_static_metacall, 0, 0}
};


const QMetaObject *QHttpWorkerThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QHttpWorkerThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QHttpWorkerThread.stringdata))
        return static_cast<void*>(const_cast< QHttpWorkerThread*>(this));
    return QThread::qt_metacast(_clname);
}

int QHttpWorkerThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void QHttpWorkerThread::started()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
