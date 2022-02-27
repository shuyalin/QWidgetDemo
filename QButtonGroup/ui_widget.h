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
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn7;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(834, 562);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn1 = new QPushButton(widget);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setMinimumSize(QSize(0, 60));
        btn1->setMaximumSize(QSize(60, 16777215));
        btn1->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(btn1);

        btn2 = new QPushButton(widget);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setMinimumSize(QSize(0, 60));
        btn2->setMaximumSize(QSize(60, 16777215));
        btn2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(btn2);

        btn3 = new QPushButton(widget);
        btn3->setObjectName(QString::fromUtf8("btn3"));
        btn3->setMinimumSize(QSize(0, 60));
        btn3->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(btn3);

        btn4 = new QPushButton(widget);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        btn4->setMinimumSize(QSize(0, 60));
        btn4->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(btn4);

        btn5 = new QPushButton(widget);
        btn5->setObjectName(QString::fromUtf8("btn5"));
        btn5->setMinimumSize(QSize(0, 60));
        btn5->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(btn5);

        btn6 = new QPushButton(widget);
        btn6->setObjectName(QString::fromUtf8("btn6"));
        btn6->setMinimumSize(QSize(0, 60));
        btn6->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(btn6);

        btn7 = new QPushButton(widget);
        btn7->setObjectName(QString::fromUtf8("btn7"));
        btn7->setMinimumSize(QSize(0, 60));
        btn7->setMaximumSize(QSize(60, 16777215));
        btn7->setStyleSheet(QString::fromUtf8("background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #D2E3F5,stop:1 #CADDF3);\n"
""));

        horizontalLayout_2->addWidget(btn7);


        horizontalLayout->addWidget(widget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        btn1->setText(QString());
        btn2->setText(QString());
        btn3->setText(QString());
        btn4->setText(QString());
        btn5->setText(QString());
        btn6->setText(QString());
        btn7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
