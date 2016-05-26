/****************************************************************************
** Meta object code from reading C++ file 'tphandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Application/Sources/tphandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tphandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TpHandler_t {
    QByteArrayData data[11];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TpHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TpHandler_t qt_meta_stringdata_TpHandler = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TpHandler"
QT_MOC_LITERAL(1, 10, 9), // "checkData"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 13), // "doHeaderStart"
QT_MOC_LITERAL(4, 35, 10), // "doHeaderId"
QT_MOC_LITERAL(5, 46, 18), // "doHeaderDataLength"
QT_MOC_LITERAL(6, 65, 10), // "doBodySize"
QT_MOC_LITERAL(7, 76, 10), // "doBodyData"
QT_MOC_LITERAL(8, 87, 11), // "doFooterSqc"
QT_MOC_LITERAL(9, 99, 11), // "doFooterCrc"
QT_MOC_LITERAL(10, 111, 12) // "doFooterStop"

    },
    "TpHandler\0checkData\0\0doHeaderStart\0"
    "doHeaderId\0doHeaderDataLength\0doBodySize\0"
    "doBodyData\0doFooterSqc\0doFooterCrc\0"
    "doFooterStop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TpHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

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

       0        // eod
};

void TpHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TpHandler *_t = static_cast<TpHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkData(); break;
        case 1: _t->doHeaderStart(); break;
        case 2: _t->doHeaderId(); break;
        case 3: _t->doHeaderDataLength(); break;
        case 4: _t->doBodySize(); break;
        case 5: _t->doBodyData(); break;
        case 6: _t->doFooterSqc(); break;
        case 7: _t->doFooterCrc(); break;
        case 8: _t->doFooterStop(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TpHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TpHandler.data,
      qt_meta_data_TpHandler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TpHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TpHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TpHandler.stringdata0))
        return static_cast<void*>(const_cast< TpHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int TpHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
