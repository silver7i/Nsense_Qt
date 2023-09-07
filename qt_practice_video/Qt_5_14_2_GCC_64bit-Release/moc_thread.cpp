/****************************************************************************
** Meta object code from reading C++ file 'thread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../thread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Player_t {
    QByteArrayData data[8];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Player_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Player_t qt_meta_stringdata_Player = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Player"
QT_MOC_LITERAL(1, 7, 14), // "processedImage"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "cv::Mat*"
QT_MOC_LITERAL(4, 32, 4), // "data"
QT_MOC_LITERAL(5, 37, 10), // "savedImage"
QT_MOC_LITERAL(6, 48, 6), // "fcount"
QT_MOC_LITERAL(7, 55, 6) // "capEnd"

    },
    "Player\0processedImage\0\0cv::Mat*\0data\0"
    "savedImage\0fcount\0capEnd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Player[] = {

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
       1,    1,   29,    2, 0x06 /* Public */,
       5,    2,   32,    2, 0x06 /* Public */,
       7,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    6,
    QMetaType::Void,

       0        // eod
};

void Player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Player *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processedImage((*reinterpret_cast< cv::Mat*(*)>(_a[1]))); break;
        case 1: _t->savedImage((*reinterpret_cast< cv::Mat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->capEnd(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Player::*)(cv::Mat * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Player::processedImage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Player::*)(cv::Mat * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Player::savedImage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Player::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Player::capEnd)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Player::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_Player.data,
    qt_meta_data_Player,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Player::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Player.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int Player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void Player::processedImage(cv::Mat * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Player::savedImage(cv::Mat * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Player::capEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
