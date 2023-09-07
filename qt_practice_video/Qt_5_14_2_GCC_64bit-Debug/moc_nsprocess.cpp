/****************************************************************************
** Meta object code from reading C++ file 'nsprocess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../nsprocess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nsprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NSprocess_t {
    QByteArrayData data[20];
    char stringdata0[224];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NSprocess_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NSprocess_t qt_meta_stringdata_NSprocess = {
    {
QT_MOC_LITERAL(0, 0, 9), // "NSprocess"
QT_MOC_LITERAL(1, 10, 9), // "faceImage"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 20), // "std::queue<cv::Mat>*"
QT_MOC_LITERAL(4, 42, 4), // "data"
QT_MOC_LITERAL(5, 47, 5), // "qsize"
QT_MOC_LITERAL(6, 53, 9), // "Face_Rect"
QT_MOC_LITERAL(7, 63, 8), // "cv::Mat&"
QT_MOC_LITERAL(8, 72, 5), // "frame"
QT_MOC_LITERAL(9, 78, 10), // "NSblurring"
QT_MOC_LITERAL(10, 89, 11), // "NSfaceindex"
QT_MOC_LITERAL(11, 101, 8), // "cv::Mat*"
QT_MOC_LITERAL(12, 110, 11), // "frame_count"
QT_MOC_LITERAL(13, 122, 10), // "NSregister"
QT_MOC_LITERAL(14, 133, 10), // "NSdrawFace"
QT_MOC_LITERAL(15, 144, 7), // "cv::Mat"
QT_MOC_LITERAL(16, 152, 29), // "std::vector<Draw_FaceInfo_T>&"
QT_MOC_LITERAL(17, 182, 6), // "qFace_"
QT_MOC_LITERAL(18, 189, 17), // "reset_frame_infos"
QT_MOC_LITERAL(19, 207, 16) // "reset_user_infos"

    },
    "NSprocess\0faceImage\0\0std::queue<cv::Mat>*\0"
    "data\0qsize\0Face_Rect\0cv::Mat&\0frame\0"
    "NSblurring\0NSfaceindex\0cv::Mat*\0"
    "frame_count\0NSregister\0NSdrawFace\0"
    "cv::Mat\0std::vector<Draw_FaceInfo_T>&\0"
    "qFace_\0reset_frame_infos\0reset_user_infos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NSprocess[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   59,    2, 0x0a /* Public */,
       9,    1,   62,    2, 0x0a /* Public */,
      10,    2,   65,    2, 0x0a /* Public */,
      13,    0,   70,    2, 0x0a /* Public */,
      14,    3,   71,    2, 0x0a /* Public */,
      18,    0,   78,    2, 0x0a /* Public */,
      19,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,    8,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 16, QMetaType::Int,    8,   17,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NSprocess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NSprocess *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->faceImage((*reinterpret_cast< std::queue<cv::Mat>*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->Face_Rect((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 2: _t->NSblurring((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 3: _t->NSfaceindex((*reinterpret_cast< cv::Mat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->NSregister(); break;
        case 5: _t->NSdrawFace((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< std::vector<Draw_FaceInfo_T>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->reset_frame_infos(); break;
        case 7: _t->reset_user_infos(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NSprocess::*)(std::queue<cv::Mat> * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NSprocess::faceImage)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NSprocess::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_NSprocess.data,
    qt_meta_data_NSprocess,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NSprocess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NSprocess::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NSprocess.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int NSprocess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void NSprocess::faceImage(std::queue<cv::Mat> * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
