/****************************************************************************
** Meta object code from reading C++ file 'picasamodel.h'
**
** Created: Thu May 16 20:24:25 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../browsingbackends/onlineservices/picasa/picasamodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'picasamodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PicasaModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      33,   13,   12,   12, 0x05,
      89,   82,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     118,  109,   12,   12, 0x09,
     160,  156,   12,   12, 0x09,
     180,  156,   12,   12, 0x09,
     199,  109,   12,   12, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_PicasaModel[] = {
    "PicasaModel\0\0searchTerm,id,image\0"
    "result(QString,QString,Plasma::DataEngine::Data)\0"
    "status\0loginComplete(bool)\0job,data\0"
    "picasaDataReady(KIO::Job*,QByteArray)\0"
    "job\0parseResults(KJob*)\0passwordJob(KJob*)\0"
    "token(KIO::Job*,QByteArray)\0"
};

void PicasaModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PicasaModel *_t = static_cast<PicasaModel *>(_o);
        switch (_id) {
        case 0: _t->result((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const Plasma::DataEngine::Data(*)>(_a[3]))); break;
        case 1: _t->loginComplete((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->picasaDataReady((*reinterpret_cast< KIO::Job*(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 3: _t->parseResults((*reinterpret_cast< KJob*(*)>(_a[1]))); break;
        case 4: _t->passwordJob((*reinterpret_cast< KJob*(*)>(_a[1]))); break;
        case 5: _t->token((*reinterpret_cast< KIO::Job*(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PicasaModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PicasaModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_PicasaModel,
      qt_meta_data_PicasaModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PicasaModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PicasaModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PicasaModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PicasaModel))
        return static_cast<void*>(const_cast< PicasaModel*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int PicasaModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void PicasaModel::result(const QString & _t1, const QString & _t2, const Plasma::DataEngine::Data & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PicasaModel::loginComplete(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
