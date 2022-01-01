/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widgetLeft;
    QVBoxLayout *verticalLayout;
    QPushButton *btnRadio;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(844, 584);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widgetLeft = new QWidget(Widget);
        widgetLeft->setObjectName(QString::fromUtf8("widgetLeft"));
        widgetLeft->setMinimumSize(QSize(140, 0));
        widgetLeft->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(widgetLeft);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnRadio = new QPushButton(widgetLeft);
        btnRadio->setObjectName(QString::fromUtf8("btnRadio"));
        btnRadio->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(btnRadio);

        pushButton_2 = new QPushButton(widgetLeft);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widgetLeft);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widgetLeft);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widgetLeft);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(widgetLeft);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(widgetLeft);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(pushButton_7);

        pushButton_10 = new QPushButton(widgetLeft);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(pushButton_10);

        pushButton_9 = new QPushButton(widgetLeft);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(pushButton_9);

        pushButton_8 = new QPushButton(widgetLeft);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(pushButton_8);


        horizontalLayout->addWidget(widgetLeft);

        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        btnRadio->setText(QApplication::translate("Widget", "QRadioButton", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Widget", "QRadioButton", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Widget", "QRadioButton", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Widget", "QRadioButton", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Widget", "QRadioButton", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("Widget", "QRadioButton", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("Widget", "QRadioButton", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("Widget", "QRadioButton", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("Widget", "QRadioButton", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("Widget", "QRadioButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
