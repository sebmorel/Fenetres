/****************************************************************************
** Meta object code from reading C++ file 'fenetres.h'
**
** Created: Wed 7. Nov 11:57:15 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fenetres.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fenetres.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_CDialog[] = {
    "CDialog\0"
};

void CDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CDialog,
      qt_meta_data_CDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CDialog))
        return static_cast<void*>(const_cast< CDialog*>(this));
    if (!strcmp(_clname, "CAbstractDialog"))
        return static_cast< CAbstractDialog*>(const_cast< CDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_CMainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      29,   12,   12,   12, 0x08,
      40,   12,   12,   12, 0x08,
      60,   53,   12,   12, 0x08,
     108,  103,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CMainWindow[] = {
    "CMainWindow\0\0donneesRecues()\0connecte()\0"
    "deconnecte()\0erreur\0"
    "erreurSocket(QAbstractSocket::SocketError)\0"
    "etat\0stateSocket(QAbstractSocket::SocketState)\0"
};

void CMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CMainWindow *_t = static_cast<CMainWindow *>(_o);
        switch (_id) {
        case 0: _t->donneesRecues(); break;
        case 1: _t->connecte(); break;
        case 2: _t->deconnecte(); break;
        case 3: _t->erreurSocket((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->stateSocket((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CMainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CMainWindow,
      qt_meta_data_CMainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CMainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CMainWindow))
        return static_cast<void*>(const_cast< CMainWindow*>(this));
    if (!strcmp(_clname, "CAbstractDialog"))
        return static_cast< CAbstractDialog*>(const_cast< CMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
static const uint qt_meta_data_CMessageBox[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_CMessageBox[] = {
    "CMessageBox\0"
};

void CMessageBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CMessageBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CMessageBox::staticMetaObject = {
    { &QMessageBox::staticMetaObject, qt_meta_stringdata_CMessageBox,
      qt_meta_data_CMessageBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CMessageBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CMessageBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CMessageBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CMessageBox))
        return static_cast<void*>(const_cast< CMessageBox*>(this));
    return QMessageBox::qt_metacast(_clname);
}

int CMessageBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMessageBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
