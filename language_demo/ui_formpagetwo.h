/********************************************************************************
** Form generated from reading UI file 'formpagetwo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPAGETWO_H
#define UI_FORMPAGETWO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormPageTwo
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *FormPageTwo)
    {
        if (FormPageTwo->objectName().isEmpty())
            FormPageTwo->setObjectName(QStringLiteral("FormPageTwo"));
        FormPageTwo->resize(800, 300);
        gridLayout = new QGridLayout(FormPageTwo);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(FormPageTwo);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(400, 150));
        label->setMaximumSize(QSize(400, 150));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(400, 150));
        label_2->setMaximumSize(QSize(400, 150));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 0, 1, 1, 2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(400, 150));
        label_3->setMaximumSize(QSize(400, 150));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 1, 0, 1, 2);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(400, 150));
        label_4->setMaximumSize(QSize(400, 150));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 1, 2, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(FormPageTwo);

        QMetaObject::connectSlotsByName(FormPageTwo);
    } // setupUi

    void retranslateUi(QWidget *FormPageTwo)
    {
        FormPageTwo->setWindowTitle(QApplication::translate("FormPageTwo", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("FormPageTwo", "name", Q_NULLPTR));
        label_2->setText(QApplication::translate("FormPageTwo", "shuyalin", Q_NULLPTR));
        label_3->setText(QApplication::translate("FormPageTwo", "sex", Q_NULLPTR));
        label_4->setText(QApplication::translate("FormPageTwo", "man", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormPageTwo: public Ui_FormPageTwo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPAGETWO_H
