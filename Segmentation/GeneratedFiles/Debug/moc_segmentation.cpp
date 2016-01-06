/****************************************************************************
** Meta object code from reading C++ file 'segmentation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../segmentation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'segmentation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Segmentation_t {
    QByteArrayData data[22];
    char stringdata0[349];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Segmentation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Segmentation_t qt_meta_stringdata_Segmentation = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Segmentation"
QT_MOC_LITERAL(1, 13, 21), // "on_seedButton_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 23), // "on_resultButton_clicked"
QT_MOC_LITERAL(4, 60, 24), // "on_segmentButton_clicked"
QT_MOC_LITERAL(5, 85, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(6, 107, 27), // "on_rgbImageAction_triggered"
QT_MOC_LITERAL(7, 135, 29), // "on_depthImageAction_triggered"
QT_MOC_LITERAL(8, 165, 26), // "on_rgbFileAction_triggered"
QT_MOC_LITERAL(9, 192, 28), // "on_depthFileAction_triggered"
QT_MOC_LITERAL(10, 221, 31), // "on_imageList_currentItemChanged"
QT_MOC_LITERAL(11, 253, 16), // "showImageOnLabel"
QT_MOC_LITERAL(12, 270, 7), // "QLabel*"
QT_MOC_LITERAL(13, 278, 5), // "label"
QT_MOC_LITERAL(14, 284, 7), // "imgPath"
QT_MOC_LITERAL(15, 292, 7), // "QImage&"
QT_MOC_LITERAL(16, 300, 8), // "objImage"
QT_MOC_LITERAL(17, 309, 9), // "needDepth"
QT_MOC_LITERAL(18, 319, 6), // "setDir"
QT_MOC_LITERAL(19, 326, 8), // "QString&"
QT_MOC_LITERAL(20, 335, 4), // "path"
QT_MOC_LITERAL(21, 340, 8) // "clearDir"

    },
    "Segmentation\0on_seedButton_clicked\0\0"
    "on_resultButton_clicked\0"
    "on_segmentButton_clicked\0on_saveButton_clicked\0"
    "on_rgbImageAction_triggered\0"
    "on_depthImageAction_triggered\0"
    "on_rgbFileAction_triggered\0"
    "on_depthFileAction_triggered\0"
    "on_imageList_currentItemChanged\0"
    "showImageOnLabel\0QLabel*\0label\0imgPath\0"
    "QImage&\0objImage\0needDepth\0setDir\0"
    "QString&\0path\0clearDir"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Segmentation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    3,   88,    2, 0x08 /* Private */,
      17,    0,   95,    2, 0x08 /* Private */,
      18,    1,   96,    2, 0x08 /* Private */,
      21,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12, QMetaType::QString, 0x80000000 | 15,   13,   14,   16,
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,

       0        // eod
};

void Segmentation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Segmentation *_t = static_cast<Segmentation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_seedButton_clicked(); break;
        case 1: _t->on_resultButton_clicked(); break;
        case 2: _t->on_segmentButton_clicked(); break;
        case 3: _t->on_saveButton_clicked(); break;
        case 4: _t->on_rgbImageAction_triggered(); break;
        case 5: _t->on_depthImageAction_triggered(); break;
        case 6: _t->on_rgbFileAction_triggered(); break;
        case 7: _t->on_depthFileAction_triggered(); break;
        case 8: _t->on_imageList_currentItemChanged(); break;
        case 9: _t->showImageOnLabel((*reinterpret_cast< QLabel*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QImage(*)>(_a[3]))); break;
        case 10: { bool _r = _t->needDepth();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: _t->setDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->clearDir(); break;
        default: ;
        }
    }
}

const QMetaObject Segmentation::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Segmentation.data,
      qt_meta_data_Segmentation,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Segmentation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Segmentation::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Segmentation.stringdata0))
        return static_cast<void*>(const_cast< Segmentation*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Segmentation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
