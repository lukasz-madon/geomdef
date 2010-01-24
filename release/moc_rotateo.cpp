/****************************************************************************
** Meta object code from reading C++ file 'rotateo.h'
**
** Created: Sun 24. Jan 01:29:16 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../rotateo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rotateo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rotateo[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,    9,    8,    8, 0x05,
      42,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,    8,    8,    8, 0x08,
      94,   88,    8,    8, 0x08,
     122,   88,    8,    8, 0x08,
     150,   88,    8,    8, 0x08,
     176,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rotateo[] = {
    "rotateo\0\0x,y,z\0CloseSignalOK(int,int,int)\0"
    "CloseSignalCancel()\0on_pushButton_3_clicked()\0"
    "value\0on_dial_3_valueChanged(int)\0"
    "on_dial_2_valueChanged(int)\0"
    "on_dial_valueChanged(int)\0"
    "on_pushButton_clicked()\0"
};

const QMetaObject rotateo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_rotateo,
      qt_meta_data_rotateo, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rotateo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rotateo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rotateo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rotateo))
        return static_cast<void*>(const_cast< rotateo*>(this));
    return QDialog::qt_metacast(_clname);
}

int rotateo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: CloseSignalOK((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: CloseSignalCancel(); break;
        case 2: on_pushButton_3_clicked(); break;
        case 3: on_dial_3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_dial_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: on_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: on_pushButton_clicked(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void rotateo::CloseSignalOK(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rotateo::CloseSignalCancel()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
