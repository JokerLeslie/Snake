/****************************************************************************
** Meta object code from reading C++ file 'game_unit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "game_unit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game_unit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mushroom_t {
    QByteArrayData data[5];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mushroom_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mushroom_t qt_meta_stringdata_Mushroom = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Mushroom"
QT_MOC_LITERAL(1, 9, 21), // "RequestRemoveMushroom"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 20), // "QGraphicsPixmapItem*"
QT_MOC_LITERAL(4, 53, 8) // "mushroom"

    },
    "Mushroom\0RequestRemoveMushroom\0\0"
    "QGraphicsPixmapItem*\0mushroom"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mushroom[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void Mushroom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Mushroom *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RequestRemoveMushroom((*reinterpret_cast< QGraphicsPixmapItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Mushroom::*)(QGraphicsPixmapItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mushroom::RequestRemoveMushroom)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Mushroom::staticMetaObject = { {
    &BaseUnit::staticMetaObject,
    qt_meta_stringdata_Mushroom.data,
    qt_meta_data_Mushroom,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Mushroom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mushroom::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mushroom.stringdata0))
        return static_cast<void*>(this);
    return BaseUnit::qt_metacast(_clname);
}

int Mushroom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseUnit::qt_metacall(_c, _id, _a);
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
void Mushroom::RequestRemoveMushroom(QGraphicsPixmapItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_Stone_t {
    QByteArrayData data[5];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Stone_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Stone_t qt_meta_stringdata_Stone = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Stone"
QT_MOC_LITERAL(1, 6, 18), // "RequestRemoveStone"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 20), // "QGraphicsPixmapItem*"
QT_MOC_LITERAL(4, 47, 5) // "stone"

    },
    "Stone\0RequestRemoveStone\0\0"
    "QGraphicsPixmapItem*\0stone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Stone[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void Stone::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Stone *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RequestRemoveStone((*reinterpret_cast< QGraphicsPixmapItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Stone::*)(QGraphicsPixmapItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Stone::RequestRemoveStone)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Stone::staticMetaObject = { {
    &BaseUnit::staticMetaObject,
    qt_meta_stringdata_Stone.data,
    qt_meta_data_Stone,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Stone::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Stone::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Stone.stringdata0))
        return static_cast<void*>(this);
    return BaseUnit::qt_metacast(_clname);
}

int Stone::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseUnit::qt_metacall(_c, _id, _a);
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
void Stone::RequestRemoveStone(QGraphicsPixmapItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_Food_t {
    QByteArrayData data[5];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Food_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Food_t qt_meta_stringdata_Food = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Food"
QT_MOC_LITERAL(1, 5, 17), // "RequestRemoveFood"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 20), // "QGraphicsPixmapItem*"
QT_MOC_LITERAL(4, 45, 4) // "food"

    },
    "Food\0RequestRemoveFood\0\0QGraphicsPixmapItem*\0"
    "food"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Food[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void Food::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Food *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RequestRemoveFood((*reinterpret_cast< QGraphicsPixmapItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Food::*)(QGraphicsPixmapItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Food::RequestRemoveFood)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Food::staticMetaObject = { {
    &BaseUnit::staticMetaObject,
    qt_meta_stringdata_Food.data,
    qt_meta_data_Food,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Food::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Food::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Food.stringdata0))
        return static_cast<void*>(this);
    return BaseUnit::qt_metacast(_clname);
}

int Food::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseUnit::qt_metacall(_c, _id, _a);
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
void Food::RequestRemoveFood(QGraphicsPixmapItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
