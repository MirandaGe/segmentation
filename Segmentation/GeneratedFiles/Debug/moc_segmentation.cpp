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
    QByteArrayData data[14];
    char stringdata0[205];
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
QT_MOC_LITERAL(6, 107, 16), // "showImageOnLabel"
QT_MOC_LITERAL(7, 124, 7), // "QLabel*"
QT_MOC_LITERAL(8, 132, 5), // "label"
QT_MOC_LITERAL(9, 138, 7), // "imgPath"
QT_MOC_LITERAL(10, 146, 7), // "QImage&"
QT_MOC_LITERAL(11, 154, 8), // "objImage"
QT_MOC_LITERAL(12, 163, 31), // "on_imageList_currentItemChanged"
QT_MOC_LITERAL(13, 195, 9) // "needDepth"

    },
    "Segmentation\0on_seedButton_clicked\0\0"
    "on_resultButton_clicked\0"
    "on_segmentButton_clicked\0on_saveButton_clicked\0"
    "showImageOnLabel\0QLabel*\0label\0imgPath\0"
    "QImage&\0objImage\0on_imageList_currentItemChanged\0"
    "needDepth"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Segmentation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    3,   53,    2, 0x08 /* Private */,
      12,    0,   60,    2, 0x08 /* Private */,
      13,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QString, 0x80000000 | 10,    8,    9,   11,
    QMetaType::Void,
    QMetaType::Bool,

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
        case 4: _t->showImageOnLabel((*reinterpret_cast< QLabel*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QImage(*)>(_a[3]))); break;
        case 5: _t->on_imageList_currentItemChanged(); break;
        case 6: { bool _r = _t->needDepth();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLabel* >(); break;
            }
            break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
