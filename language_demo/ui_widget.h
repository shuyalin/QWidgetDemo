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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QWidget *widget_Top;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *btnSetting;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *btnHome;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnPageTwp;
    QSpacerItem *horizontalSpacer_5;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *page_2;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QPushButton *back;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *chinese;
    QPushButton *pushButton_5;
    QPushButton *english;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 480);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(true);
        widget_Top = new QWidget(widget);
        widget_Top->setObjectName(QStringLiteral("widget_Top"));
        widget_Top->setGeometry(QRect(0, 0, 798, 70));
        widget_Top->setMinimumSize(QSize(0, 70));
        horizontalLayout = new QHBoxLayout(widget_Top);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(145, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSetting = new QToolButton(widget_Top);
        btnSetting->setObjectName(QStringLiteral("btnSetting"));
        btnSetting->setMinimumSize(QSize(35, 35));
        btnSetting->setCursor(QCursor(Qt::OpenHandCursor));
        btnSetting->setStyleSheet(QStringLiteral(""));
        btnSetting->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnSetting->setAutoRaise(true);

        horizontalLayout->addWidget(btnSetting);

        horizontalSpacer_2 = new QSpacerItem(40, 0, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_title = new QLabel(widget_Top);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setMinimumSize(QSize(150, 0));
        label_title->setMaximumSize(QSize(16777215, 40));
        label_title->setStyleSheet(QStringLiteral("border-image: url(:/images/title.png);"));
        label_title->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_title);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btnHome = new QToolButton(widget_Top);
        btnHome->setObjectName(QStringLiteral("btnHome"));
        btnHome->setMinimumSize(QSize(35, 35));
        btnHome->setCursor(QCursor(Qt::OpenHandCursor));
        btnHome->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnHome->setAutoRaise(true);

        horizontalLayout->addWidget(btnHome);

        horizontalSpacer_4 = new QSpacerItem(145, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        btnPageTwp = new QPushButton(widget_Top);
        btnPageTwp->setObjectName(QStringLiteral("btnPageTwp"));

        horizontalLayout->addWidget(btnPageTwp);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 70, 800, 300));
        stackedWidget->setMinimumSize(QSize(800, 300));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        widget_2 = new QWidget(page);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 800, 300));
        widget_2->setMinimumSize(QSize(800, 300));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(100, 100));
        pushButton->setMaximumSize(QSize(100, 100));
        QFont font;
        font.setPointSize(21);
        pushButton->setFont(font);

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(100, 100));
        pushButton_2->setMaximumSize(QSize(100, 100));
        pushButton_2->setFont(font);

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(100, 100));
        pushButton_3->setMaximumSize(QSize(100, 100));
        pushButton_3->setFont(font);

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(100, 100));
        pushButton_4->setMaximumSize(QSize(100, 100));
        pushButton_4->setFont(font);

        horizontalLayout_2->addWidget(pushButton_4);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setMinimumSize(QSize(800, 300));
        widget_3 = new QWidget(page_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(0, 0, 800, 300));
        widget_3->setMinimumSize(QSize(800, 300));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(100, 30));
        label_2->setMaximumSize(QSize(100, 30));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(100, 30));
        label->setMaximumSize(QSize(100, 30));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        back = new QPushButton(widget_3);
        back->setObjectName(QStringLiteral("back"));
        back->setFont(font);

        gridLayout->addWidget(back, 2, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(0, 379, 800, 80));
        widget_4->setMinimumSize(QSize(800, 80));
        widget_4->setMaximumSize(QSize(1000, 560));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        chinese = new QPushButton(widget_4);
        chinese->setObjectName(QStringLiteral("chinese"));
        chinese->setMinimumSize(QSize(100, 30));
        chinese->setMaximumSize(QSize(100, 30));

        horizontalLayout_3->addWidget(chinese);

        pushButton_5 = new QPushButton(widget_4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(100, 0));
        pushButton_5->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(pushButton_5);

        english = new QPushButton(widget_4);
        english->setObjectName(QStringLiteral("english"));
        english->setMinimumSize(QSize(100, 30));
        english->setMaximumSize(QSize(100, 30));

        horizontalLayout_3->addWidget(english);


        verticalLayout->addWidget(widget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        btnSetting->setText(QApplication::translate("Widget", "setting", Q_NULLPTR));
        label_title->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:18pt;\">MainPage</span></p></body></html>", Q_NULLPTR));
        btnHome->setText(QApplication::translate("Widget", "FirstPage", Q_NULLPTR));
        btnPageTwp->setText(QApplication::translate("Widget", "secondPage", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "one", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "two", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Widget", "three", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Widget", "four", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:18pt;\">six</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:18pt;\">five</span></p></body></html>", Q_NULLPTR));
        back->setText(QApplication::translate("Widget", "back", Q_NULLPTR));
        chinese->setText(QApplication::translate("Widget", "chinese", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Widget", "new page", Q_NULLPTR));
        english->setText(QApplication::translate("Widget", "english", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
