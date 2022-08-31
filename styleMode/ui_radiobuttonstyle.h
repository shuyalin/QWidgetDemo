/********************************************************************************
** Form generated from reading UI file 'radiobuttonstyle.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RADIOBUTTONSTYLE_H
#define UI_RADIOBUTTONSTYLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_radioButtonStyle
{
public:
    QGridLayout *gridLayout;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;
    QRadioButton *radioButton4;

    void setupUi(QWidget *radioButtonStyle)
    {
        if (radioButtonStyle->objectName().isEmpty())
            radioButtonStyle->setObjectName(QStringLiteral("radioButtonStyle"));
        radioButtonStyle->resize(436, 315);
        gridLayout = new QGridLayout(radioButtonStyle);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        radioButton1 = new QRadioButton(radioButtonStyle);
        radioButton1->setObjectName(QStringLiteral("radioButton1"));
        radioButton1->setMinimumSize(QSize(100, 40));
        radioButton1->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(radioButton1, 0, 1, 1, 1);

        radioButton2 = new QRadioButton(radioButtonStyle);
        radioButton2->setObjectName(QStringLiteral("radioButton2"));
        radioButton2->setMinimumSize(QSize(100, 40));
        radioButton2->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(radioButton2, 0, 0, 1, 1);

        radioButton3 = new QRadioButton(radioButtonStyle);
        radioButton3->setObjectName(QStringLiteral("radioButton3"));
        radioButton3->setMinimumSize(QSize(100, 40));
        radioButton3->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(radioButton3, 1, 0, 1, 1);

        radioButton4 = new QRadioButton(radioButtonStyle);
        radioButton4->setObjectName(QStringLiteral("radioButton4"));
        radioButton4->setMinimumSize(QSize(100, 40));
        radioButton4->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(radioButton4, 1, 1, 1, 1);


        retranslateUi(radioButtonStyle);

        QMetaObject::connectSlotsByName(radioButtonStyle);
    } // setupUi

    void retranslateUi(QWidget *radioButtonStyle)
    {
        radioButtonStyle->setWindowTitle(QApplication::translate("radioButtonStyle", "Form", Q_NULLPTR));
        radioButton1->setText(QApplication::translate("radioButtonStyle", "two", Q_NULLPTR));
        radioButton2->setText(QApplication::translate("radioButtonStyle", "one", Q_NULLPTR));
        radioButton3->setText(QApplication::translate("radioButtonStyle", "three", Q_NULLPTR));
        radioButton4->setText(QApplication::translate("radioButtonStyle", "four", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class radioButtonStyle: public Ui_radioButtonStyle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RADIOBUTTONSTYLE_H
