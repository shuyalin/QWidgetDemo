/****************************************************************************
** Meta object code from reading C++ file 'CustomListView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CustomListView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CustomListView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CustomListView_t {
    QByteArrayData data[9];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomListView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomListView_t qt_meta_stringdata_CustomListView = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CustomListView"
QT_MOC_LITERAL(1, 15, 19), // "onPressIndexChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "index"
QT_MOC_LITERAL(4, 42, 20), // "onCurrentIndexChange"
QT_MOC_LITERAL(5, 63, 19), // "listViewItemRelease"
QT_MOC_LITERAL(6, 83, 21), // "listViewItemLongPress"
QT_MOC_LITERAL(7, 105, 15), // "listViewRelease"
QT_MOC_LITERAL(8, 121, 9) // "onTimeout"

    },
    "CustomListView\0onPressIndexChanged\0\0"
    "index\0onCurrentIndexChange\0"
    "listViewItemRelease\0listViewItemLongPress\0"
    "listViewRelease\0onTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomListView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       5,    1,   50,    2, 0x06 /* Public */,
       6,    1,   53,    2, 0x06 /* Public */,
       7,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CustomListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CustomListView *_t = static_cast<CustomListView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onPressIndexChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->onCurrentIndexChange((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->listViewItemRelease((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->listViewItemLongPress((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->listViewRelease(); break;
        case 5: _t->onTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CustomListView::*_t)(const QModelIndex & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomListView::onPressIndexChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CustomListView::*_t)(const QModelIndex & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomListView::onCurrentIndexChange)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CustomListView::*_t)(const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomListView::listViewItemRelease)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CustomListView::*_t)(const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomListView::listViewItemLongPress)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CustomListView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CustomListView::listViewRelease)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject CustomListView::staticMetaObject = {
    { &QListView::staticMetaObject, qt_meta_stringdata_CustomListView.data,
      qt_meta_data_CustomListView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CustomListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomListView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CustomListView.stringdata0))
        return static_cast<void*>(const_cast< CustomListView*>(this));
    return QListView::qt_metacast(_clname);
}

int CustomListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CustomListView::onPressIndexChanged(const QModelIndex & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CustomListView::onCurrentIndexChange(const QModelIndex & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CustomListView::listViewItemRelease(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CustomListView::listViewItemLongPress(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CustomListView::listViewRelease()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
