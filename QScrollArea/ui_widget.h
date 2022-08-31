/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <customscrollarea.h>
#include <frmnavi.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    CustomScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    CustomScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_4;
    QVBoxLayout *verticalLayout;
    frmNavi *widget_11;
    frmNavi *widget_10;
    frmNavi *widget_9;
    frmNavi *widget_8;
    frmNavi *widget_7;
    frmNavi *widget_6;
    frmNavi *widget_5;
    frmNavi *widget;
    frmNavi *widget_2;
    frmNavi *widget_3;
    frmNavi *widget_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(974, 711);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        scrollArea = new CustomScrollArea(Widget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 473, 691));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        scrollArea_2 = new CustomScrollArea(Widget);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QStringLiteral("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 473, 691));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_11 = new frmNavi(scrollAreaWidgetContents_4);
        widget_11->setObjectName(QStringLiteral("widget_11"));

        verticalLayout->addWidget(widget_11);

        widget_10 = new frmNavi(scrollAreaWidgetContents_4);
        widget_10->setObjectName(QStringLiteral("widget_10"));

        verticalLayout->addWidget(widget_10);

        widget_9 = new frmNavi(scrollAreaWidgetContents_4);
        widget_9->setObjectName(QStringLiteral("widget_9"));

        verticalLayout->addWidget(widget_9);

        widget_8 = new frmNavi(scrollAreaWidgetContents_4);
        widget_8->setObjectName(QStringLiteral("widget_8"));

        verticalLayout->addWidget(widget_8);

        widget_7 = new frmNavi(scrollAreaWidgetContents_4);
        widget_7->setObjectName(QStringLiteral("widget_7"));

        verticalLayout->addWidget(widget_7);

        widget_6 = new frmNavi(scrollAreaWidgetContents_4);
        widget_6->setObjectName(QStringLiteral("widget_6"));

        verticalLayout->addWidget(widget_6);

        widget_5 = new frmNavi(scrollAreaWidgetContents_4);
        widget_5->setObjectName(QStringLiteral("widget_5"));

        verticalLayout->addWidget(widget_5);

        widget = new frmNavi(scrollAreaWidgetContents_4);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(widget);

        widget_2 = new frmNavi(scrollAreaWidgetContents_4);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(widget_2);

        widget_3 = new frmNavi(scrollAreaWidgetContents_4);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(widget_3);

        widget_4 = new frmNavi(scrollAreaWidgetContents_4);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(widget_4);

        scrollArea_2->setWidget(scrollAreaWidgetContents_4);

        horizontalLayout->addWidget(scrollArea_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
