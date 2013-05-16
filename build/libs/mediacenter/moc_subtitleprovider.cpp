/****************************************************************************
** Meta object code from reading C++ file 'subtitleprovider.h'
**
** Created: Thu May 16 20:23:39 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../libs/mediacenter/subtitleprovider.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'subtitleprovider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SubtitleProvider[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       3,   24, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      36,   17,   17,   17, 0x05,

 // properties: name, type, flags
      66,   58, 0x0a495001,
      80,   75, 0x11095103,
      96,   89, 0x04495103,

 // properties: notify_signal_id
       0,
       0,
       1,

       0        // eod
};

static const char qt_meta_stringdata_SubtitleProvider[] = {
    "SubtitleProvider\0\0subtitleChanged()\0"
    "subtitleTimeChanged()\0QString\0subtitle\0"
    "QUrl\0filename\0qint64\0subtitleTime\0"
};

void SubtitleProvider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SubtitleProvider *_t = static_cast<SubtitleProvider *>(_o);
        switch (_id) {
        case 0: _t->subtitleChanged(); break;
        case 1: _t->subtitleTimeChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SubtitleProvider::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SubtitleProvider::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SubtitleProvider,
      qt_meta_data_SubtitleProvider, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SubtitleProvider::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SubtitleProvider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SubtitleProvider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SubtitleProvider))
        return static_cast<void*>(const_cast< SubtitleProvider*>(this));
    return QObject::qt_metacast(_clname);
}

int SubtitleProvider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = subtitle(); break;
        case 1: *reinterpret_cast< QUrl*>(_v) = filename(); break;
        case 2: *reinterpret_cast< qint64*>(_v) = subtitleTime(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: setFilename(*reinterpret_cast< QUrl*>(_v)); break;
        case 2: setSubtitleTime(*reinterpret_cast< qint64*>(_v)); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void SubtitleProvider::subtitleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SubtitleProvider::subtitleTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
