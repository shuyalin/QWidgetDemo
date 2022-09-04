/********************************************************************************
** Form generated from reading UI file 'customlistwidgetitem.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMLISTWIDGETITEM_H
#define UI_CUSTOMLISTWIDGETITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomListWidgetItem
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *pushButton;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;

    void setupUi(QWidget *CustomListWidgetItem)
    {
        if (CustomListWidgetItem->objectName().isEmpty())
            CustomListWidgetItem->setObjectName(QStringLiteral("CustomListWidgetItem"));
        CustomListWidgetItem->resize(400, 200);
        horizontalLayout = new QHBoxLayout(CustomListWidgetItem);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(CustomListWidgetItem);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 60));
        widget_2->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 60));
        pushButton->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);


        verticalLayout->addWidget(widget_3);


        horizontalLayout->addWidget(widget);


        retranslateUi(CustomListWidgetItem);

        QMetaObject::connectSlotsByName(CustomListWidgetItem);
    } // setupUi

    void retranslateUi(QWidget *CustomListWidgetItem)
    {
        CustomListWidgetItem->setWindowTitle(QApplication::translate("CustomListWidgetItem", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("CustomListWidgetItem", "<html><head/><body><p><span style=\" font-size:24pt; color:#8ae234;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CustomListWidgetItem", "btn", Q_NULLPTR));
        label_2->setText(QApplication::translate("CustomListWidgetItem", "<html><head/><body><p><span style=\" font-size:48pt; color:#729fcf;\">shuyalin</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CustomListWidgetItem: public Ui_CustomListWidgetItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMLISTWIDGETITEM_H
