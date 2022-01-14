/****************************************************************************
** Meta object code from reading C++ file 'game_mode_info_view.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "game_mode_info_view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game_mode_info_view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameSingleModeInfoView_t {
    QByteArrayData data[6];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameSingleModeInfoView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameSingleModeInfoView_t qt_meta_stringdata_GameSingleModeInfoView = {
    {
QT_MOC_LITERAL(0, 0, 22), // "GameSingleModeInfoView"
QT_MOC_LITERAL(1, 23, 24), // "RequestGetSingleModeInfo"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 4), // "name"
QT_MOC_LITERAL(4, 54, 5), // "level"
QT_MOC_LITERAL(5, 60, 23) // "RequestReturnModeChoose"

    },
    "GameSingleModeInfoView\0RequestGetSingleModeInfo\0"
    "\0name\0level\0RequestReturnModeChoose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameSingleModeInfoView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       5,    0,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,    3,    4,
    QMetaType::Void,

       0        // eod
};

void GameSingleModeInfoView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameSingleModeInfoView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RequestGetSingleModeInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 1: _t->RequestReturnModeChoose(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameSingleModeInfoView::*)(QString , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameSingleModeInfoView::RequestGetSingleModeInfo)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameSingleModeInfoView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameSingleModeInfoView::RequestReturnModeChoose)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GameSingleModeInfoView::staticMetaObject = { {
    &QGraphicsWidget::staticMetaObject,
    qt_meta_stringdata_GameSingleModeInfoView.data,
    qt_meta_data_GameSingleModeInfoView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GameSingleModeInfoView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameSingleModeInfoView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameSingleModeInfoView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsWidget::qt_metacast(_clname);
}

int GameSingleModeInfoView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GameSingleModeInfoView::RequestGetSingleModeInfo(QString _t1, quint32 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameSingleModeInfoView::RequestReturnModeChoose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_GameDoubleModeInfoView_t {
    QByteArrayData data[10];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameDoubleModeInfoView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameDoubleModeInfoView_t qt_meta_stringdata_GameDoubleModeInfoView = {
    {
QT_MOC_LITERAL(0, 0, 22), // "GameDoubleModeInfoView"
QT_MOC_LITERAL(1, 23, 24), // "RequestGetDoubleModeInfo"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 5), // "type1"
QT_MOC_LITERAL(4, 55, 5), // "name1"
QT_MOC_LITERAL(5, 61, 6), // "level1"
QT_MOC_LITERAL(6, 68, 5), // "type2"
QT_MOC_LITERAL(7, 74, 5), // "name2"
QT_MOC_LITERAL(8, 80, 6), // "level2"
QT_MOC_LITERAL(9, 87, 23) // "RequestReturnModeChoose"

    },
    "GameDoubleModeInfoView\0RequestGetDoubleModeInfo\0"
    "\0type1\0name1\0level1\0type2\0name2\0level2\0"
    "RequestReturnModeChoose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameDoubleModeInfoView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   24,    2, 0x06 /* Public */,
       9,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::UInt, QMetaType::UInt, QMetaType::QString, QMetaType::UInt,    3,    4,    5,    6,    7,    8,
    QMetaType::Void,

       0        // eod
};

void GameDoubleModeInfoView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameDoubleModeInfoView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RequestGetDoubleModeInfo((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< quint32(*)>(_a[6]))); break;
        case 1: _t->RequestReturnModeChoose(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameDoubleModeInfoView::*)(quint32 , QString , quint32 , quint32 , QString , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameDoubleModeInfoView::RequestGetDoubleModeInfo)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameDoubleModeInfoView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameDoubleModeInfoView::RequestReturnModeChoose)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GameDoubleModeInfoView::staticMetaObject = { {
    &QGraphicsWidget::staticMetaObject,
    qt_meta_stringdata_GameDoubleModeInfoView.data,
    qt_meta_data_GameDoubleModeInfoView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GameDoubleModeInfoView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameDoubleModeInfoView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameDoubleModeInfoView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsWidget::qt_metacast(_clname);
}

int GameDoubleModeInfoView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GameDoubleModeInfoView::RequestGetDoubleModeInfo(quint32 _t1, QString _t2, quint32 _t3, quint32 _t4, QString _t5, quint32 _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameDoubleModeInfoView::RequestReturnModeChoose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
