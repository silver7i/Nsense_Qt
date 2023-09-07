/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[28];
    char stringdata0[416];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "read_Img"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "cv::Mat"
QT_MOC_LITERAL(4, 29, 3), // "img"
QT_MOC_LITERAL(5, 33, 5), // "count"
QT_MOC_LITERAL(6, 39, 12), // "faceRegister"
QT_MOC_LITERAL(7, 52, 10), // "findPerson"
QT_MOC_LITERAL(8, 63, 11), // "blurringImg"
QT_MOC_LITERAL(9, 75, 8), // "cv::Mat&"
QT_MOC_LITERAL(10, 84, 12), // "faceindexImg"
QT_MOC_LITERAL(11, 97, 29), // "std::vector<Draw_FaceInfo_T>&"
QT_MOC_LITERAL(12, 127, 5), // "vFace"
QT_MOC_LITERAL(13, 133, 11), // "frame_count"
QT_MOC_LITERAL(14, 145, 19), // "on_cam_open_clicked"
QT_MOC_LITERAL(15, 165, 20), // "on_cam_close_clicked"
QT_MOC_LITERAL(16, 186, 10), // "read_Frame"
QT_MOC_LITERAL(17, 197, 8), // "cv::Mat*"
QT_MOC_LITERAL(18, 206, 13), // "update_window"
QT_MOC_LITERAL(19, 220, 16), // "getFormattedTime"
QT_MOC_LITERAL(20, 237, 13), // "timeInSeconds"
QT_MOC_LITERAL(21, 251, 27), // "on_video_silder_sliderMoved"
QT_MOC_LITERAL(22, 279, 8), // "position"
QT_MOC_LITERAL(23, 288, 29), // "on_video_silder_sliderPressed"
QT_MOC_LITERAL(24, 318, 30), // "on_video_silder_sliderReleased"
QT_MOC_LITERAL(25, 349, 19), // "on_play_btn_clicked"
QT_MOC_LITERAL(26, 369, 21), // "on_replay_btn_clicked"
QT_MOC_LITERAL(27, 391, 24) // "on_saveindex_btn_clicked"

    },
    "MainWindow\0read_Img\0\0cv::Mat\0img\0count\0"
    "faceRegister\0findPerson\0blurringImg\0"
    "cv::Mat&\0faceindexImg\0"
    "std::vector<Draw_FaceInfo_T>&\0vFace\0"
    "frame_count\0on_cam_open_clicked\0"
    "on_cam_close_clicked\0read_Frame\0"
    "cv::Mat*\0update_window\0getFormattedTime\0"
    "timeInSeconds\0on_video_silder_sliderMoved\0"
    "position\0on_video_silder_sliderPressed\0"
    "on_video_silder_sliderReleased\0"
    "on_play_btn_clicked\0on_replay_btn_clicked\0"
    "on_saveindex_btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   94,    2, 0x06 /* Public */,
       6,    0,   99,    2, 0x06 /* Public */,
       7,    0,  100,    2, 0x06 /* Public */,
       8,    1,  101,    2, 0x06 /* Public */,
      10,    3,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    2,  113,    2, 0x08 /* Private */,
      18,    2,  118,    2, 0x08 /* Private */,
      19,    1,  123,    2, 0x08 /* Private */,
      21,    1,  126,    2, 0x08 /* Private */,
      23,    0,  129,    2, 0x08 /* Private */,
      24,    0,  130,    2, 0x08 /* Private */,
      25,    0,  131,    2, 0x08 /* Private */,
      26,    0,  132,    2, 0x08 /* Private */,
      27,    0,  133,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 11, QMetaType::Int,    4,   12,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::QString, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->read_Img((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->faceRegister(); break;
        case 2: _t->findPerson(); break;
        case 3: _t->blurringImg((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 4: _t->faceindexImg((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< std::vector<Draw_FaceInfo_T>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->on_cam_open_clicked(); break;
        case 6: _t->on_cam_close_clicked(); break;
        case 7: _t->read_Frame((*reinterpret_cast< cv::Mat*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->update_window((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: { QString _r = _t->getFormattedTime((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->on_video_silder_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_video_silder_sliderPressed(); break;
        case 12: _t->on_video_silder_sliderReleased(); break;
        case 13: _t->on_play_btn_clicked(); break;
        case 14: _t->on_replay_btn_clicked(); break;
        case 15: _t->on_saveindex_btn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(cv::Mat , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::read_Img)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::faceRegister)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::findPerson)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(cv::Mat & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::blurringImg)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(cv::Mat , std::vector<Draw_FaceInfo_T> & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::faceindexImg)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::read_Img(cv::Mat _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::faceRegister()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::findPerson()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::blurringImg(cv::Mat & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::faceindexImg(cv::Mat _t1, std::vector<Draw_FaceInfo_T> & _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
