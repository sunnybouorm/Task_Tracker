/****************************************************************************
** Meta object code from reading C++ file 'Task_Setup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GUI/Task_Setup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Task_Setup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Task_Setup_Dialog_t {
    QByteArrayData data[13];
    char stringdata[292];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Task_Setup_Dialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Task_Setup_Dialog_t qt_meta_stringdata_Task_Setup_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "Task_Setup_Dialog"
QT_MOC_LITERAL(1, 18, 26), // "addTask_pushButton_clicked"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 29), // "on_addTask_pushButton_clicked"
QT_MOC_LITERAL(4, 76, 33), // "on_addCategory_pushButton_cli..."
QT_MOC_LITERAL(5, 110, 36), // "on_deleteSelected_pushButton_..."
QT_MOC_LITERAL(6, 147, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(7, 168, 16), // "QAbstractButton*"
QT_MOC_LITERAL(8, 185, 6), // "button"
QT_MOC_LITERAL(9, 192, 30), // "on_taskName_comboBox_activated"
QT_MOC_LITERAL(10, 223, 4), // "arg1"
QT_MOC_LITERAL(11, 228, 36), // "on_taskName_comboBox_editText..."
QT_MOC_LITERAL(12, 265, 26) // "on_edit_pushButton_clicked"

    },
    "Task_Setup_Dialog\0addTask_pushButton_clicked\0"
    "\0on_addTask_pushButton_clicked\0"
    "on_addCategory_pushButton_clicked\0"
    "on_deleteSelected_pushButton_clicked\0"
    "on_buttonBox_clicked\0QAbstractButton*\0"
    "button\0on_taskName_comboBox_activated\0"
    "arg1\0on_taskName_comboBox_editTextChanged\0"
    "on_edit_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Task_Setup_Dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    1,   58,    2, 0x08 /* Private */,
       9,    1,   61,    2, 0x08 /* Private */,
      11,    1,   64,    2, 0x08 /* Private */,
      12,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,

       0        // eod
};

void Task_Setup_Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Task_Setup_Dialog *_t = static_cast<Task_Setup_Dialog *>(_o);
        switch (_id) {
        case 0: _t->addTask_pushButton_clicked(); break;
        case 1: _t->on_addTask_pushButton_clicked(); break;
        case 2: _t->on_addCategory_pushButton_clicked(); break;
        case 3: _t->on_deleteSelected_pushButton_clicked(); break;
        case 4: _t->on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 5: _t->on_taskName_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_taskName_comboBox_editTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_edit_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Task_Setup_Dialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Task_Setup_Dialog::addTask_pushButton_clicked)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Task_Setup_Dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Task_Setup_Dialog.data,
      qt_meta_data_Task_Setup_Dialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Task_Setup_Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Task_Setup_Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Task_Setup_Dialog.stringdata))
        return static_cast<void*>(const_cast< Task_Setup_Dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Task_Setup_Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Task_Setup_Dialog::addTask_pushButton_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
