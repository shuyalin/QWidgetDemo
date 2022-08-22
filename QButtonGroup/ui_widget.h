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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn7;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(781, 488);
        Widget->setMinimumSize(QSize(100, 100));
        Widget->setMaximumSize(QSize(166766, 16777215));
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn1 = new QPushButton(widget);
        btn1->setObjectName(QStringLiteral("btn1"));
        btn1->setMinimumSize(QSize(0, 60));
        btn1->setMaximumSize(QSize(60, 16777215));
        btn1->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(btn1);

        btn2 = new QPushButton(widget);
        btn2->setObjectName(QStringLiteral("btn2"));
        btn2->setMinimumSize(QSize(0, 60));
        btn2->setMaximumSize(QSize(60, 16777215));
        btn2->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(btn2);

        btn3 = new QPushButton(widget);
        btn3->setObjectName(QStringLiteral("btn3"));
        btn3->setMinimumSize(QSize(0, 60));
        btn3->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(btn3);

        btn4 = new QPushButton(widget);
        btn4->setObjectName(QStringLiteral("btn4"));
        btn4->setMinimumSize(QSize(0, 60));
        btn4->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(btn4);

        btn5 = new QPushButton(widget);
        btn5->setObjectName(QStringLiteral("btn5"));
        btn5->setMinimumSize(QSize(0, 60));
        btn5->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(btn5);

        btn6 = new QPushButton(widget);
        btn6->setObjectName(QStringLiteral("btn6"));
        btn6->setMinimumSize(QSize(0, 60));
        btn6->setMaximumSize(QSize(60, 16777215));
        btn6->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(btn6);

        btn7 = new QPushButton(widget);
        btn7->setObjectName(QStringLiteral("btn7"));
        btn7->setMinimumSize(QSize(0, 60));
        btn7->setMaximumSize(QSize(60, 16777215));
        btn7->setStyleSheet(QLatin1String("background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #D2E3F5,stop:1 #CADDF3);\n"
""));

        horizontalLayout_2->addWidget(btn7);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(Widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(100, 100));
        widget_2->setMaximumSize(QSize(1667266, 120));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_5 = new QPushButton(widget_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(100, 100));
        pushButton_5->setMaximumSize(QSize(100, 100));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/ViewPaperWidgetBluetoothPress.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/Images/ViewPaperWidgetBluetoothNormal.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_5->setIcon(icon);
        pushButton_5->setIconSize(QSize(100, 100));
        pushButton_5->setCheckable(true);

        horizontalLayout->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(100, 100));
        pushButton_4->setMaximumSize(QSize(100, 100));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/ViewPaperWidgetAssistPress.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/Images/ViewPaperWidgetAssistNormal.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_4->setIcon(icon1);
        pushButton_4->setIconSize(QSize(100, 100));
        pushButton_4->setCheckable(true);

        horizontalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(100, 100));
        pushButton_3->setMaximumSize(QSize(100, 100));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/ViewPaperWidgetAUXPress.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QStringLiteral(":/Images/ViewPaperWidgetAUXNormal.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(100, 100));
        pushButton_3->setCheckable(true);

        horizontalLayout->addWidget(pushButton_3);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(100, 100));
        pushButton->setMaximumSize(QSize(100, 100));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Images/ViewPaperWidgetRadioPress.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QStringLiteral(":/Images/ViewPaperWidgetRadioNormal.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton->setIcon(icon3);
        pushButton->setIconSize(QSize(100, 100));
        pushButton->setCheckable(true);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(100, 100));
        pushButton_2->setMaximumSize(QSize(100, 100));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Images/ViewPaperWidgetSDPress.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QStringLiteral(":/Images/ViewPaperWidgetSDNormal.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_2->setIcon(icon4);
        pushButton_2->setIconSize(QSize(100, 100));
        pushButton_2->setCheckable(true);

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addWidget(widget_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        btn1->setText(QString());
        btn2->setText(QString());
        btn3->setText(QString());
        btn4->setText(QString());
        btn5->setText(QString());
        btn6->setText(QString());
        btn7->setText(QString());
        pushButton_5->setText(QString());
        pushButton_4->setText(QString());
        pushButton_3->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
