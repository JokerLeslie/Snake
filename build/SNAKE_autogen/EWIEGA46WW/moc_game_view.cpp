/****************************************************************************
** Meta object code from reading C++ file 'game_view.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "game_view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game_view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameView_t {
    QByteArrayData data[16];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameView_t qt_meta_stringdata_GameView = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GameView"
QT_MOC_LITERAL(1, 9, 21), // "RequestSingleModeOver"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "name"
QT_MOC_LITERAL(4, 37, 5), // "score"
QT_MOC_LITERAL(5, 43, 21), // "RequestDoubleModeOver"
QT_MOC_LITERAL(6, 65, 7), // "winName"
QT_MOC_LITERAL(7, 73, 8), // "winScore"
QT_MOC_LITERAL(8, 82, 8), // "loseName"
QT_MOC_LITERAL(9, 91, 9), // "loseScore"
QT_MOC_LITERAL(10, 101, 22), // "ResponseRemoveMushroom"
QT_MOC_LITERAL(11, 124, 20), // "QGraphicsPixmapItem*"
QT_MOC_LITERAL(12, 145, 4), // "item"
QT_MOC_LITERAL(13, 150, 19), // "ResponseRemoveStone"
QT_MOC_LITERAL(14, 170, 18), // "ResponseRemoveFood"
QT_MOC_LITERAL(15, 189, 19) // "ResponseRemoveSnake"

    },
    "GameView\0RequestSingleModeOver\0\0name\0"
    "score\0RequestDoubleModeOver\0winName\0"
    "winScore\0loseName\0loseScore\0"
    "ResponseRemoveMushroom\0QGraphicsPixmapItem*\0"
    "item\0ResponseRemoveStone\0ResponseRemoveFood\0"
    "ResponseRemoveSnake"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    4,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   58,    2, 0x0a /* Public */,
      13,    1,   61,    2, 0x0a /* Public */,
      14,    1,   64,    2, 0x0a /* Public */,
      15,    1,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::QString, QMetaType::UInt,    6,    7,    8,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::QObjectStar,   12,

       0        // eod
};

void GameView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RequestSingleModeOver((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 1: _t->RequestDoubleModeOver((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4]))); break;
        case 2: _t->ResponseRemoveMushroom((*reinterpret_cast< QGraphicsPixmapItem*(*)>(_a[1]))); break;
        case 3: _t->ResponseRemoveStone((*reinterpret_cast< QGraphicsPixmapItem*(*)>(_a[1]))); break;
        case 4: _t->ResponseRemoveFood((*reinterpret_cast< QGraphicsPixmapItem*(*)>(_a[1]))); break;
        case 5: _t->ResponseRemoveSnake((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameView::*)(QString , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameView::RequestSingleModeOver)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameView::*)(QString , quint32 , QString , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameView::RequestDoubleModeOver)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GameView::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_GameView.data,
    qt_meta_data_GameView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GameView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameView.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsRectItem"))
        return static_cast< QGraphicsRectItem*>(this);
    return QObject::qt_metacast(_clname);
}

int GameView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void GameView::RequestSingleModeOver(QString _t1, quint32 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameView::RequestDoubleModeOver(QString _t1, quint32 _t2, QString _t3, quint32 _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
