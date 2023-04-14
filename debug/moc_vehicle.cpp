/****************************************************************************
** Meta object code from reading C++ file 'vehicle.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../vehicle.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vehicle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_Vehicle_t {
    uint offsetsAndSizes[20];
    char stringdata0[8];
    char stringdata1[5];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[13];
    char stringdata5[11];
    char stringdata6[12];
    char stringdata7[9];
    char stringdata8[10];
    char stringdata9[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Vehicle_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Vehicle_t qt_meta_stringdata_Vehicle = {
    {
        QT_MOC_LITERAL(0, 7),  // "Vehicle"
        QT_MOC_LITERAL(8, 4),  // "move"
        QT_MOC_LITERAL(13, 0),  // ""
        QT_MOC_LITERAL(14, 11),  // "moveForward"
        QT_MOC_LITERAL(26, 12),  // "moveBackward"
        QT_MOC_LITERAL(39, 10),  // "strafeLeft"
        QT_MOC_LITERAL(50, 11),  // "strafeRight"
        QT_MOC_LITERAL(62, 8),  // "turnLeft"
        QT_MOC_LITERAL(71, 9),  // "turnRight"
        QT_MOC_LITERAL(81, 4)   // "fire"
    },
    "Vehicle",
    "move",
    "",
    "moveForward",
    "moveBackward",
    "strafeLeft",
    "strafeRight",
    "turnLeft",
    "turnRight",
    "fire"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Vehicle[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x0a,    1 /* Public */,
       3,    0,   63,    2, 0x09,    2 /* Protected */,
       4,    0,   64,    2, 0x09,    3 /* Protected */,
       5,    0,   65,    2, 0x09,    4 /* Protected */,
       6,    0,   66,    2, 0x09,    5 /* Protected */,
       7,    0,   67,    2, 0x09,    6 /* Protected */,
       8,    0,   68,    2, 0x09,    7 /* Protected */,
       9,    0,   69,    2, 0x09,    8 /* Protected */,

 // slots: parameters
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

Q_CONSTINIT const QMetaObject Vehicle::staticMetaObject = { {
    QMetaObject::SuperData::link<GameObject::staticMetaObject>(),
    qt_meta_stringdata_Vehicle.offsetsAndSizes,
    qt_meta_data_Vehicle,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Vehicle_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Vehicle, std::true_type>,
        // method 'move'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveForward'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveBackward'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'strafeLeft'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'strafeRight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'turnLeft'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'turnRight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'fire'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Vehicle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Vehicle *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->move(); break;
        case 1: _t->moveForward(); break;
        case 2: _t->moveBackward(); break;
        case 3: _t->strafeLeft(); break;
        case 4: _t->strafeRight(); break;
        case 5: _t->turnLeft(); break;
        case 6: _t->turnRight(); break;
        case 7: _t->fire(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Vehicle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Vehicle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Vehicle.stringdata0))
        return static_cast<void*>(this);
    return GameObject::qt_metacast(_clname);
}

int Vehicle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GameObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
