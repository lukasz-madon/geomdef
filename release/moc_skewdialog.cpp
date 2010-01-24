/****************************************************************************
** Meta object code from reading C++ file 'skewdialog.h'
**
** Created: Sun 24. Jan 01:29:22 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../skewdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'skewdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_skewdialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   12,   11,   11, 0x05,
      49,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      69,   11,   11,   11, 0x08,
      93,   11,   11,   11, 0x08,
     125,  119,   11,   11, 0x08,
     153,  119,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_skewdialog[] = {
    "skewdialog\0\0angleX,angleY\0"
    "CloseSignalOK(int,int)\0CloseSignalCancel()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0value\0"
    "on_dial_2_valueChanged(int)\0"
    "on_dial_valueChanged(int)\0"
};

const QMetaObject skewdialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_skewdialog,
      qt_meta_data_skewdialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &skewdialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *skewdialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *skewdialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_skewdialog))
        return static_cast<void*>(const_cast< skewdialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int skewdialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: CloseSignalOK((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: CloseSignalCancel(); break;
        case 2: on_pushButton_clicked(); break;
        case 3: on_pushButton_2_clicked(); break;
        case 4: on_dial_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: on_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void skewdialog::CloseSignalOK(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void skewdialog::CloseSignalCancel()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
