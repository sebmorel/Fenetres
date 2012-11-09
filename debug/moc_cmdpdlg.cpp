/****************************************************************************
** Meta object code from reading C++ file 'cmdpdlg.h'
**
** Created: Wed 7. Nov 11:57:03 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cmdpdlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cmdpdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CMdpDlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      27,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CMdpDlg[] = {
    "CMdpDlg\0\0onPushOKClicked()\0"
    "onPushCancelClicked()\0"
};

void CMdpDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CMdpDlg *_t = static_cast<CMdpDlg *>(_o);
        switch (_id) {
        case 0: _t->onPushOKClicked(); break;
        case 1: _t->onPushCancelClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CMdpDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CMdpDlg::staticMetaObject = {
    { &CDialog::staticMetaObject, qt_meta_stringdata_CMdpDlg,
      qt_meta_data_CMdpDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CMdpDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CMdpDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CMdpDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CMdpDlg))
        return static_cast<void*>(const_cast< CMdpDlg*>(this));
    return CDialog::qt_metacast(_clname);
}

int CMdpDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
