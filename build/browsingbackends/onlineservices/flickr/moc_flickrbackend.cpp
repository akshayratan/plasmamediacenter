/****************************************************************************
** Meta object code from reading C++ file 'flickrbackend.h'
**
** Created: Thu May 16 20:24:24 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../browsingbackends/onlineservices/flickr/flickrbackend.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'flickrbackend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FlickrBackend[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   14,   15,   14, 0x0a,
      31,   14,   15,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FlickrBackend[] = {
    "FlickrBackend\0\0bool\0initImpl()\0"
    "goOneLevelUp()\0"
};

void FlickrBackend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FlickrBackend *_t = static_cast<FlickrBackend *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->initImpl();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->goOneLevelUp();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FlickrBackend::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FlickrBackend::staticMetaObject = {
    { &MediaCenter::AbstractBrowsingBackend::staticMetaObject, qt_meta_stringdata_FlickrBackend,
      qt_meta_data_FlickrBackend, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FlickrBackend::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FlickrBackend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FlickrBackend::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FlickrBackend))
        return static_cast<void*>(const_cast< FlickrBackend*>(this));
    typedef MediaCenter::AbstractBrowsingBackend QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int FlickrBackend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef MediaCenter::AbstractBrowsingBackend QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
