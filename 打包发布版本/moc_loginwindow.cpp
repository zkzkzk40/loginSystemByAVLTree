/****************************************************************************
** Meta object code from reading C++ file 'loginwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../loginSystem/loginwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_loginWindow_t {
    const uint offsetsAndSize[12];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_loginWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_loginWindow_t qt_meta_stringdata_loginWindow = {
    {
QT_MOC_LITERAL(0, 11), // "loginWindow"
QT_MOC_LITERAL(12, 19), // "on_loginBtn_clicked"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 22), // "on_registerBtn_clicked"
QT_MOC_LITERAL(56, 20), // "on_modifyBtn_clicked"
QT_MOC_LITERAL(77, 20) // "on_removeBtn_clicked"

    },
    "loginWindow\0on_loginBtn_clicked\0\0"
    "on_registerBtn_clicked\0on_modifyBtn_clicked\0"
    "on_removeBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_loginWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x08,    0 /* Private */,
       3,    0,   39,    2, 0x08,    1 /* Private */,
       4,    0,   40,    2, 0x08,    2 /* Private */,
       5,    0,   41,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void loginWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<loginWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_loginBtn_clicked(); break;
        case 1: _t->on_registerBtn_clicked(); break;
        case 2: _t->on_modifyBtn_clicked(); break;
        case 3: _t->on_removeBtn_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject loginWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_loginWindow.offsetsAndSize,
    qt_meta_data_loginWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_loginWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *loginWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *loginWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_loginWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int loginWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
