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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *btnA;
    QPushButton *btnB;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 400);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnA = new QPushButton(Widget);
        btnA->setObjectName(QString::fromUtf8("btnA"));
        btnA->setMinimumSize(QSize(100, 60));
        btnA->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(btnA);

        btnB = new QPushButton(Widget);
        btnB->setObjectName(QString::fromUtf8("btnB"));
        btnB->setMinimumSize(QSize(0, 60));
        btnB->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(btnB);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        btnA->setText(QApplication::translate("Widget", "print----AAA", nullptr));
        btnB->setText(QApplication::translate("Widget", "print----BBB", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
