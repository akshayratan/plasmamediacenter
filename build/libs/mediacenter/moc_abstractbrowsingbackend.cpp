/****************************************************************************
** Meta object code from reading C++ file 'abstractbrowsingbackend.h'
**
** Created: Thu May 16 20:23:39 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../libs/mediacenter/abstractbrowsingbackend.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'abstractbrowsingbackend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MediaCenter__AbstractBrowsingBackend[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       4,   64, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      38,   37,   37,   37, 0x05,
      53,   37,   37,   37, 0x05,
      76,   37,   37,   37, 0x05,
      90,   37,   37,   37, 0x05,

 // methods: signature, parameters, type, tag, flags
     126,   37,  121,   37, 0x02,
     133,   37,  121,   37, 0x02,
     152,  148,  121,   37, 0x02,
     172,   37,  164,   37, 0x02,
     195,   37,  121,   37, 0x02,
     223,  212,   37,   37, 0x02,

 // properties: name, type, flags
     248,  239, 0x88495001,
     261,  239, 0x88495103,
     275,  121, 0x01495001,
     280,  164, 0x0a495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

static const char qt_meta_stringdata_MediaCenter__AbstractBrowsingBackend[] = {
    "MediaCenter::AbstractBrowsingBackend\0"
    "\0modelChanged()\0metadataModelChanged()\0"
    "busyChanged()\0mediaBrowserSidePanelChanged()\0"
    "bool\0init()\0goOneLevelUp()\0row\0"
    "expand(int)\0QString\0mediaBrowserOverride()\0"
    "supportsSearch()\0searchTerm\0search(QString)\0"
    "QObject*\0backendModel\0metadataModel\0"
    "busy\0mediaBrowserSidePanel\0"
};

void MediaCenter::AbstractBrowsingBackend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AbstractBrowsingBackend *_t = static_cast<AbstractBrowsingBackend *>(_o);
        switch (_id) {
        case 0: _t->modelChanged(); break;
        case 1: _t->metadataModelChanged(); break;
        case 2: _t->busyChanged(); break;
        case 3: _t->mediaBrowserSidePanelChanged(); break;
        case 4: { bool _r = _t->init();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->goOneLevelUp();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->expand((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { QString _r = _t->mediaBrowserOverride();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 8: { bool _r = _t->supportsSearch();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: _t->search((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MediaCenter::AbstractBrowsingBackend::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MediaCenter::AbstractBrowsingBackend::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MediaCenter__AbstractBrowsingBackend,
      qt_meta_data_MediaCenter__AbstractBrowsingBackend, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MediaCenter::AbstractBrowsingBackend::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MediaCenter::AbstractBrowsingBackend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MediaCenter::AbstractBrowsingBackend::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MediaCenter__AbstractBrowsingBackend))
        return static_cast<void*>(const_cast< AbstractBrowsingBackend*>(this));
    return QObject::qt_metacast(_clname);
}

int MediaCenter::AbstractBrowsingBackend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QObject**>(_v) = model(); break;
        case 1: *reinterpret_cast< QObject**>(_v) = metadataModel(); break;
        case 2: *reinterpret_cast< bool*>(_v) = busy(); break;
        case 3: *reinterpret_cast< QString*>(_v) = mediaBrowserSidePanel(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: setMetadataModel(*reinterpret_cast< QObject**>(_v)); break;
        case 3: setMediaBrowserSidePanel(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MediaCenter::AbstractBrowsingBackend::modelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MediaCenter::AbstractBrowsingBackend::metadataModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MediaCenter::AbstractBrowsingBackend::busyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MediaCenter::AbstractBrowsingBackend::mediaBrowserSidePanelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
