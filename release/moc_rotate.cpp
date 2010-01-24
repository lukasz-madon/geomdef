/****************************************************************************
** Meta object code from reading C++ file 'rotate.h'
**
** Created: Sun 24. Jan 01:29:11 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../rotate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rotate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rotate[] = {

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
      14,    8,    7,    7, 0x05,
      33,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,    7,    7,    7, 0x0a,
      69,    7,    7,    7, 0x0a,
      90,   84,    7,    7, 0x08,
     116,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rotate[] = {
    "rotate\0\0angle\0CloseSignalOK(int)\0"
    "CloseSignalCancel()\0rotateSlot(int)\0"
    "rotateOKSlot()\0value\0on_dial_valueChanged(int)\0"
    "on_pushButton_clicked()\0"
};

const QMetaObject rotate::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_rotate,
      qt_meta_data_rotate, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rotate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rotate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rotate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rotate))
        return static_cast<void*>(const_cast< rotate*>(this));
    return QDialog::qt_metacast(_clname);
}

int rotate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: CloseSignalOK((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: CloseSignalCancel(); break;
        case 2: rotateSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: rotateOKSlot(); break;
        case 4: on_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: on_pushButton_clicked(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void rotate::CloseSignalOK(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rotate::CloseSignalCancel()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
