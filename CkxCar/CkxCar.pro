#-------------------------------------------------
#
# Project created by QtCreator 2022-07-20T22:11:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CkxCar
TEMPLATE = app

include (./BaseItem/BaseItem.pri)

INCLUDEPATH += ./BaseItem/
INCLUDEPATH += ./MainPage/
INCLUDEPATH += ./MainPage/RadioPage/
INCLUDEPATH += ./MainPage/BluePage/
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    MainPage/formmainpage.cpp \
    MainPage/formhomepage.cpp \
    MainPage/RadioPage/formradio.cpp \
    MainPage/BluePage/formblue.cpp \
    appevent.cpp \
    MainPage/formhomepageone.cpp

HEADERS += \
    MainPage/formmainpage.h \
    MainPage/formhomepage.h \
    MainPage/RadioPage/formradio.h \
    MainPage/BluePage/formblue.h \
    appevent.h \
    MainPage/formhomepageone.h

FORMS += \
    MainPage/formmainpage.ui \
    MainPage/formhomepage.ui \
    MainPage/RadioPage/formradio.ui \
    MainPage/BluePage/formblue.ui \
    MainPage/formhomepageone.ui

RESOURCES += \
    res.qrc
