/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Game_t {
    QByteArrayData data[25];
    char stringdata0[326];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Game_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Game_t qt_meta_stringdata_Game = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Game"
QT_MOC_LITERAL(1, 5, 24), // "ResponseSingleModeChoose"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 24), // "ResponseDoubleModeChoose"
QT_MOC_LITERAL(4, 56, 24), // "ResponseReturnModeChoose"
QT_MOC_LITERAL(5, 81, 25), // "ResponseGetSingleModeInfo"
QT_MOC_LITERAL(6, 107, 4), // "name"
QT_MOC_LITERAL(7, 112, 5), // "level"
QT_MOC_LITERAL(8, 118, 25), // "ResponseGetDoubleModeInfo"
QT_MOC_LITERAL(9, 144, 5), // "type1"
QT_MOC_LITERAL(10, 150, 5), // "name1"
QT_MOC_LITERAL(11, 156, 6), // "level1"
QT_MOC_LITERAL(12, 163, 5), // "type2"
QT_MOC_LITERAL(13, 169, 5), // "name2"
QT_MOC_LITERAL(14, 175, 6), // "level2"
QT_MOC_LITERAL(15, 182, 22), // "ResponseSingleModeOver"
QT_MOC_LITERAL(16, 205, 5), // "score"
QT_MOC_LITERAL(17, 211, 22), // "ResponseDoubleModeOver"
QT_MOC_LITERAL(18, 234, 7), // "winName"
QT_MOC_LITERAL(19, 242, 8), // "winScore"
QT_MOC_LITERAL(20, 251, 8), // "loseName"
QT_MOC_LITERAL(21, 260, 9), // "loseScore"
QT_MOC_LITERAL(22, 270, 18), // "ResponseGameReplay"
QT_MOC_LITERAL(23, 289, 19), // "ResponseGameRestart"
QT_MOC_LITERAL(24, 309, 16) // "ResponseExitGame"

    },
    "Game\0ResponseSingleModeChoose\0\0"
    "ResponseDoubleModeChoose\0"
    "ResponseReturnModeChoose\0"
    "ResponseGetSingleModeInfo\0name\0level\0"
    "ResponseGetDoubleModeInfo\0type1\0name1\0"
    "level1\0type2\0name2\0level2\0"
    "ResponseSingleModeOver\0score\0"
    "ResponseDoubleModeOver\0winName\0winScore\0"
    "loseName\0loseScore\0ResponseGameReplay\0"
    "ResponseGameRestart\0ResponseExitGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Game[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    2,   67,    2, 0x0a /* Public */,
       8,    6,   72,    2, 0x0a /* Public */,
      15,    2,   85,    2, 0x0a /* Public */,
      17,    4,   90,    2, 0x0a /* Public */,
      22,    0,   99,    2, 0x0a /* Public */,
      23,    0,  100,    2, 0x0a /* Public */,
      24,    0,  101,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,    6,    7,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::UInt, QMetaType::UInt, QMetaType::QString, QMetaType::UInt,    9,   10,   11,   12,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,    6,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::QString, QMetaType::UInt,   18,   19,   20,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Game *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ResponseSingleModeChoose(); break;
        case 1: _t->ResponseDoubleModeChoose(); break;
        case 2: _t->ResponseReturnModeChoose(); break;
        case 3: _t->ResponseGetSingleModeInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 4: _t->ResponseGetDoubleModeInfo((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< quint32(*)>(_a[6]))); break;
        case 5: _t->ResponseSingleModeOver((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 6: _t->ResponseDoubleModeOver((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4]))); break;
        case 7: _t->ResponseGameReplay(); break;
        case 8: _t->ResponseGameRestart(); break;
        case 9: _t->ResponseExitGame(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Game::staticMetaObject = { {
    &QGraphicsView::staticMetaObject,
    qt_meta_stringdata_Game.data,
    qt_meta_data_Game,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Game::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Game.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int Game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
