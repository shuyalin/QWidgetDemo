/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *widget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(800, 480);
        widget = new QWidget(Form);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 800, 480));
        widget->setStyleSheet(QStringLiteral("background-color:rgb(255,152,146);"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 800, 68));
        widget_2->setMinimumSize(QSize(800, 60));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(100, 50));
        pushButton->setMaximumSize(QSize(1677777, 16777215));
        pushButton->setFlat(true);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(112, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 50));
        label->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setPointSize(26);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(112, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(0, 70, 800, 411));
        widget_3->setMinimumSize(QSize(800, 411));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(160, 40));
        label_2->setMaximumSize(QSize(160, 40));
        QFont font1;
        font1.setPointSize(24);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(160, 40));
        label_3->setMaximumSize(QSize(160, 40));
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(160, 40));
        label_4->setMaximumSize(QSize(160, 40));
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Form", "quit", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "beauty ranking list of tik-tok", Q_NULLPTR));
        label_2->setText(QApplication::translate("Form", "xiaoliuzi", Q_NULLPTR));
        label_3->setText(QApplication::translate("Form", "jaingnaier", Q_NULLPTR));
        label_4->setText(QApplication::translate("Form", "tianqiu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
