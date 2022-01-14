/****************************************************************************
** Meta object code from reading C++ file 'game_over_view.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "game_over_view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game_over_view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameOverSingleModeView_t {
    QByteArrayData data[5];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameOverSingleModeView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameOverSingleModeView_t qt_meta_stringdata_GameOverSingleModeView = {
    {
QT_MOC_LITERAL(0, 0, 22), // "GameOverSingleModeView"
QT_MOC_LITERAL(1, 23, 17), // "RequestGameReplay"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 18), // "RequestGameRestart"
QT_MOC_LITERAL(4, 61, 15) // "RequestExitGame"

    },
    "GameOverSingleModeView\0RequestGameReplay\0"
    "\0RequestGameRestart\0RequestExitGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameOverSingleModeView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    0,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameOverSingleModeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameOverSingleModeView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RequestGameReplay(); break;
        case 1: _t->RequestGameRestart(); break;
        case 2: _t->RequestExitGame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameOverSingleModeView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameOverSingleModeView::RequestGameReplay)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameOverSingleModeView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameOverSingleModeView::RequestGameRestart)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GameOverSingleModeView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameOverSingleModeView::RequestExitGame)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GameOverSingleModeView::staticMetaObject = { {
    &QGraphicsWidget::staticMetaObject,
    qt_meta_stringdata_GameOverSingleModeView.data,
    qt_meta_data_GameOverSingleModeView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GameOverSingleModeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameOverSingleModeView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameOverSingleModeView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsWidget::qt_metacast(_clname);
}

int GameOverSingleModeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void GameOverSingleModeView::RequestGameReplay()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GameOverSingleModeView::RequestGameRestart()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GameOverSingleModeView::RequestExitGame()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
struct qt_meta_stringdata_GameOverDoubleModeView_t {
    QByteArrayData data[5];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameOverDoubleModeView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameOverDoubleModeView_t qt_meta_stringdata_GameOverDoubleModeView = {
    {
QT_MOC_LITERAL(0, 0, 22), // "GameOverDoubleModeView"
QT_MOC_LITERAL(1, 23, 17), // "RequestGameReplay"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 18), // "RequestGameRestart"
QT_MOC_LITERAL(4, 61, 15) // "RequestExitGame"

    },
    "GameOverDoubleModeView\0RequestGameReplay\0"
    "\0RequestGameRestart\0RequestExitGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameOverDoubleModeView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    0,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameOverDoubleModeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameOverDoubleModeView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RequestGameReplay(); break;
        case 1: _t->RequestGameRestart(); break;
        case 2: _t->RequestExitGame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameOverDoubleModeView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameOverDoubleModeView::RequestGameReplay)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameOverDoubleModeView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameOverDoubleModeView::RequestGameRestart)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GameOverDoubleModeView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameOverDoubleModeView::RequestExitGame)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GameOverDoubleModeView::staticMetaObject = { {
    &QGraphicsWidget::staticMetaObject,
    qt_meta_stringdata_GameOverDoubleModeView.data,
    qt_meta_data_GameOverDoubleModeView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GameOverDoubleModeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameOverDoubleModeView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameOverDoubleModeView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsWidget::qt_metacast(_clname);
}

int GameOverDoubleModeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void GameOverDoubleModeView::RequestGameReplay()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GameOverDoubleModeView::RequestGameRestart()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GameOverDoubleModeView::RequestExitGame()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
