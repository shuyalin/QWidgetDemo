/****************************************************************************
** Meta object code from reading C++ file 'ViewPaperWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ViewPaperWidget/ViewPaperWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ViewPaperWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ViewPaperWidget_t {
    QByteArrayData data[5];
    char stringdata0[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ViewPaperWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ViewPaperWidget_t qt_meta_stringdata_ViewPaperWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ViewPaperWidget"
QT_MOC_LITERAL(1, 16, 15), // "onButtonRelease"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "index"
QT_MOC_LITERAL(4, 39, 16) // "horizontalOffset"

    },
    "ViewPaperWidget\0onButtonRelease\0\0index\0"
    "horizontalOffset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewPaperWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    3,

 // properties: name, type, flags
       4, QMetaType::Int, 0x00095103,

       0        // eod
};

void ViewPaperWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ViewPaperWidget *_t = static_cast<ViewPaperWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onButtonRelease((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ViewPaperWidget *_t = static_cast<ViewPaperWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->horizontalOffset(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ViewPaperWidget *_t = static_cast<ViewPaperWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setHorizontalOffset(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ViewPaperWidget::staticMetaObject = {
    { &QListView::staticMetaObject, qt_meta_stringdata_ViewPaperWidget.data,
      qt_meta_data_ViewPaperWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ViewPaperWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewPaperWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ViewPaperWidget.stringdata0))
        return static_cast<void*>(const_cast< ViewPaperWidget*>(this));
    return QListView::qt_metacast(_clname);
}

int ViewPaperWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_ViewPaperItemDelegate_t {
    QByteArrayData data[4];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ViewPaperItemDelegate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ViewPaperItemDelegate_t qt_meta_stringdata_ViewPaperItemDelegate = {
    {
QT_MOC_LITERAL(0, 0, 21), // "ViewPaperItemDelegate"
QT_MOC_LITERAL(1, 22, 13), // "buttonRelease"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 5) // "index"

    },
    "ViewPaperItemDelegate\0buttonRelease\0"
    "\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewPaperItemDelegate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,

       0        // eod
};

void ViewPaperItemDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ViewPaperItemDelegate *_t = static_cast<ViewPaperItemDelegate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->buttonRelease((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ViewPaperItemDelegate::*_t)(const unsigned int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ViewPaperItemDelegate::buttonRelease)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ViewPaperItemDelegate::staticMetaObject = {
    { &CustomItemDelegate::staticMetaObject, qt_meta_stringdata_ViewPaperItemDelegate.data,
      qt_meta_data_ViewPaperItemDelegate,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ViewPaperItemDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewPaperItemDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ViewPaperItemDelegate.stringdata0))
        return static_cast<void*>(const_cast< ViewPaperItemDelegate*>(this));
    return CustomItemDelegate::qt_metacast(_clname);
}

int ViewPaperItemDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CustomItemDelegate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ViewPaperItemDelegate::buttonRelease(const unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
