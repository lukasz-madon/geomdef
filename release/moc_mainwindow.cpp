/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun 24. Jan 01:29:06 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      23,   11,   11,   11, 0x08,
      32,   11,   11,   11, 0x08,
      42,   11,   11,   11, 0x08,
      57,   11,   11,   11, 0x08,
      73,   11,   11,   11, 0x08,
      87,   81,   11,   11, 0x08,
     111,   11,   11,   11, 0x08,
     145,  136,   11,   11, 0x08,
     181,   11,   11,   11, 0x08,
     224,  210,   11,   11, 0x08,
     245,   11,   11,   11, 0x08,
     263,   11,   11,   11, 0x08,
     274,   11,   11,   11, 0x08,
     287,   11,   11,   11, 0x08,
     300,   11,   11,   11, 0x08,
     308,   11,   11,   11, 0x08,
     315,   11,   11,   11, 0x08,
     327,   11,   11,   11, 0x08,
     342,   11,   11,   11, 0x08,
     353,   11,   11,   11, 0x08,
     363,   11,   11,   11, 0x08,
     375,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0loadFile()\0zoomIn()\0"
    "zoomOut()\0rotateDialog()\0rotateoDialog()\0"
    "skewd()\0angle\0rotateImageCloseOK(int)\0"
    "rotateImageCloseCancel()\0xp,yp,zp\0"
    "axisRotateImageCloseOK(int,int,int)\0"
    "axisRotateImageCloseCancel()\0angleX,angleY\0"
    "skewCloseOK(int,int)\0skewCloseCancel()\0"
    "saveFile()\0saveFileAs()\0clearImage()\0"
    "print()\0exit()\0loadImage()\0activateMenu()\0"
    "openHelp()\0openWeb()\0aboutInfo()\0"
    "closeEvent(QCloseEvent*)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: loadFile(); break;
        case 1: zoomIn(); break;
        case 2: zoomOut(); break;
        case 3: rotateDialog(); break;
        case 4: rotateoDialog(); break;
        case 5: skewd(); break;
        case 6: rotateImageCloseOK((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: rotateImageCloseCancel(); break;
        case 8: axisRotateImageCloseOK((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: axisRotateImageCloseCancel(); break;
        case 10: skewCloseOK((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: skewCloseCancel(); break;
        case 12: saveFile(); break;
        case 13: saveFileAs(); break;
        case 14: clearImage(); break;
        case 15: print(); break;
        case 16: exit(); break;
        case 17: loadImage(); break;
        case 18: activateMenu(); break;
        case 19: openHelp(); break;
        case 20: openWeb(); break;
        case 21: aboutInfo(); break;
        case 22: closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
