/****************************************************************************
** Meta object code from reading C++ file 'statemachine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Application/Sources/statemachine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'statemachine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Statemachine_t {
    QByteArrayData data[10];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Statemachine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Statemachine_t qt_meta_stringdata_Statemachine = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Statemachine"
QT_MOC_LITERAL(1, 13, 7), // "onEnter"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "State_t"
QT_MOC_LITERAL(4, 30, 5), // "state"
QT_MOC_LITERAL(5, 36, 12), // "onTransition"
QT_MOC_LITERAL(6, 49, 12), // "Transition_t"
QT_MOC_LITERAL(7, 62, 10), // "transition"
QT_MOC_LITERAL(8, 73, 6), // "onExit"
QT_MOC_LITERAL(9, 80, 8) // "onCyclic"

    },
    "Statemachine\0onEnter\0\0State_t\0state\0"
    "onTransition\0Transition_t\0transition\0"
    "onExit\0onCyclic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Statemachine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,
       8,    1,   40,    2, 0x06 /* Public */,
       9,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void Statemachine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Statemachine *_t = static_cast<Statemachine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onEnter((*reinterpret_cast< State_t(*)>(_a[1]))); break;
        case 1: _t->onTransition((*reinterpret_cast< Transition_t(*)>(_a[1]))); break;
        case 2: _t->onExit((*reinterpret_cast< State_t(*)>(_a[1]))); break;
        case 3: _t->onCyclic((*reinterpret_cast< State_t(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Statemachine::*_t)(State_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Statemachine::onEnter)) {
                *result = 0;
            }
        }
        {
            typedef void (Statemachine::*_t)(Transition_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Statemachine::onTransition)) {
                *result = 1;
            }
        }
        {
            typedef void (Statemachine::*_t)(State_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Statemachine::onExit)) {
                *result = 2;
            }
        }
        {
            typedef void (Statemachine::*_t)(State_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Statemachine::onCyclic)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Statemachine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Statemachine.data,
      qt_meta_data_Statemachine,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Statemachine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Statemachine::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Statemachine.stringdata0))
        return static_cast<void*>(const_cast< Statemachine*>(this));
    return QObject::qt_metacast(_clname);
}

int Statemachine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Statemachine::onEnter(State_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Statemachine::onTransition(Transition_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Statemachine::onExit(State_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Statemachine::onCyclic(State_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
