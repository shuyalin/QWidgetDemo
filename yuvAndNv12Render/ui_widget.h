/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *yuv420Btn;
    QPushButton *nv12Btn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1280, 900);
        yuv420Btn = new QPushButton(Widget);
        yuv420Btn->setObjectName(QString::fromUtf8("yuv420Btn"));
        yuv420Btn->setGeometry(QRect(190, 750, 300, 70));
        yuv420Btn->setStyleSheet(QString::fromUtf8("font-size:28px;\n"
"border-radius:35px;\n"
"background-color:rgb(255,152,146);"));
        nv12Btn = new QPushButton(Widget);
        nv12Btn->setObjectName(QString::fromUtf8("nv12Btn"));
        nv12Btn->setGeometry(QRect(600, 750, 300, 70));
        nv12Btn->setStyleSheet(QString::fromUtf8("font-size:28px;\n"
"border-radius:35px;\n"
"background-color:rgb(255,152,146);"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        yuv420Btn->setText(QApplication::translate("Widget", "YUV420", nullptr));
        nv12Btn->setText(QApplication::translate("Widget", "NV12", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
