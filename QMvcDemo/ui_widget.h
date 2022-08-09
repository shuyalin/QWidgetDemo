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
#include <QtWidgets/QLabel>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QLabel *label;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1024, 600);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QStringLiteral("background-color: rgb(138, 226, 52);"));
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(380, 160, 200, 60));
        label->setMinimumSize(QSize(200, 60));
        label->setStyleSheet(QLatin1String("border: 3px solid rgb(211, 215, 207);\n"
"border-radius:8px;\n"
"font-size:28px;\n"
"color:rgb(211, 215, 207);\n"
""));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 222));
        widget_3->setMaximumSize(QSize(16777215, 222));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb(114, 159, 207);"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(widget_3);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));

        horizontalLayout_2->addWidget(stackedWidget);


        verticalLayout->addWidget(widget_3);


        horizontalLayout->addWidget(widget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
