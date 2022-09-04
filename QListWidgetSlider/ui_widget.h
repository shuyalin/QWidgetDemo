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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>
#include <mylistview.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    MyListView *listView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1038, 623);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        listWidget = new QListWidget(Widget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMaximumSize(QSize(400, 16777215));
        listWidget->setStyleSheet(QLatin1String("QListWidget::item{\n"
"width:400px;\n"
"height:80px;\n"
"background:green;\n"
"margin:20px,0px,0px,0px;\n"
"}"));

        horizontalLayout->addWidget(listWidget);

        listView = new MyListView(Widget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setMaximumSize(QSize(400, 16777215));

        horizontalLayout->addWidget(listView);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Widget", "11111", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Widget", "New Item", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Widget", "New Item", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("Widget", "New Item", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("Widget", "New Item", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("Widget", "aaaaaaa", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("Widget", "New Item", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem7 = listWidget->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("Widget", "New Item", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem8 = listWidget->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("Widget", "bbbbbbbbbb", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem9 = listWidget->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("Widget", "New Item", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem10 = listWidget->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("Widget", "New Item", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem11 = listWidget->item(11);
        ___qlistwidgetitem11->setText(QApplication::translate("Widget", "New Item", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem12 = listWidget->item(12);
        ___qlistwidgetitem12->setText(QApplication::translate("Widget", "New Item", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem13 = listWidget->item(13);
        ___qlistwidgetitem13->setText(QApplication::translate("Widget", "cccccccccccccc", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem14 = listWidget->item(14);
        ___qlistwidgetitem14->setText(QApplication::translate("Widget", "New Item", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem15 = listWidget->item(15);
        ___qlistwidgetitem15->setText(QApplication::translate("Widget", "New Item", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem16 = listWidget->item(16);
        ___qlistwidgetitem16->setText(QApplication::translate("Widget", "New Item", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem17 = listWidget->item(17);
        ___qlistwidgetitem17->setText(QApplication::translate("Widget", "New Item", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem18 = listWidget->item(18);
        ___qlistwidgetitem18->setText(QApplication::translate("Widget", "2222222222", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem19 = listWidget->item(19);
        ___qlistwidgetitem19->setText(QApplication::translate("Widget", "33333333333", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem20 = listWidget->item(20);
        ___qlistwidgetitem20->setText(QApplication::translate("Widget", "44444444444", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem21 = listWidget->item(21);
        ___qlistwidgetitem21->setText(QApplication::translate("Widget", "5555555555555", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem22 = listWidget->item(22);
        ___qlistwidgetitem22->setText(QApplication::translate("Widget", "6666666666", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem23 = listWidget->item(23);
        ___qlistwidgetitem23->setText(QApplication::translate("Widget", "77777777777777", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem24 = listWidget->item(24);
        ___qlistwidgetitem24->setText(QApplication::translate("Widget", "888888888888888", Q_NULLPTR));
        listWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
