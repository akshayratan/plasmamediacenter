/****************************************************************************
** Meta object code from reading C++ file 'localfilesabstractbackend.h'
**
** Created: Thu May 16 20:23:57 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../browsingbackends/localfiles/localfilesabstractbackend.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'localfilesabstractbackend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LocalFilesAbstractBackend[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      47,   27,   26,   26, 0x08,

 // methods: signature, parameters, type, tag, flags
     112,   26,  103,   26, 0x02,
     130,  126,   26,   26, 0x02,
     149,   26,   26,   26, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_LocalFilesAbstractBackend[] = {
    "LocalFilesAbstractBackend\0\0"
    "error,errordata,udi\0"
    "slotStorageSetupDone(Solid::ErrorType,QVariant,QString)\0"
    "QObject*\0placesModel()\0row\0"
    "browseToPlace(int)\0browseOneLevelUp()\0"
};

void LocalFilesAbstractBackend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LocalFilesAbstractBackend *_t = static_cast<LocalFilesAbstractBackend *>(_o);
        switch (_id) {
        case 0: _t->slotStorageSetupDone((*reinterpret_cast< Solid::ErrorType(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: { QObject* _r = _t->placesModel();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 2: _t->browseToPlace((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->browseOneLevelUp(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LocalFilesAbstractBackend::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LocalFilesAbstractBackend::staticMetaObject = {
    { &MediaCenter::AbstractBrowsingBackend::staticMetaObject, qt_meta_stringdata_LocalFilesAbstractBackend,
      qt_meta_data_LocalFilesAbstractBackend, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LocalFilesAbstractBackend::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LocalFilesAbstractBackend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LocalFilesAbstractBackend::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LocalFilesAbstractBackend))
        return static_cast<void*>(const_cast< LocalFilesAbstractBackend*>(this));
    typedef MediaCenter::AbstractBrowsingBackend QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int LocalFilesAbstractBackend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef MediaCenter::AbstractBrowsingBackend QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
