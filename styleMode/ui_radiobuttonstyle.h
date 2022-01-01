/********************************************************************************
** Form generated from reading UI file 'radiobuttonstyle.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RADIOBUTTONSTYLE_H
#define UI_RADIOBUTTONSTYLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

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
            radioButtonStyle->setObjectName(QString::fromUtf8("radioButtonStyle"));
        radioButtonStyle->resize(436, 315);
        gridLayout = new QGridLayout(radioButtonStyle);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        radioButton1 = new QRadioButton(radioButtonStyle);
        radioButton1->setObjectName(QString::fromUtf8("radioButton1"));
        radioButton1->setMinimumSize(QSize(100, 40));
        radioButton1->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(radioButton1, 0, 1, 1, 1);

        radioButton2 = new QRadioButton(radioButtonStyle);
        radioButton2->setObjectName(QString::fromUtf8("radioButton2"));
        radioButton2->setMinimumSize(QSize(100, 40));
        radioButton2->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(radioButton2, 0, 0, 1, 1);

        radioButton3 = new QRadioButton(radioButtonStyle);
        radioButton3->setObjectName(QString::fromUtf8("radioButton3"));
        radioButton3->setMinimumSize(QSize(100, 40));
        radioButton3->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(radioButton3, 1, 0, 1, 1);

        radioButton4 = new QRadioButton(radioButtonStyle);
        radioButton4->setObjectName(QString::fromUtf8("radioButton4"));
        radioButton4->setMinimumSize(QSize(100, 40));
        radioButton4->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(radioButton4, 1, 1, 1, 1);


        retranslateUi(radioButtonStyle);

        QMetaObject::connectSlotsByName(radioButtonStyle);
    } // setupUi

    void retranslateUi(QWidget *radioButtonStyle)
    {
        radioButtonStyle->setWindowTitle(QApplication::translate("radioButtonStyle", "Form", 0, QApplication::UnicodeUTF8));
        radioButton1->setText(QApplication::translate("radioButtonStyle", "two", 0, QApplication::UnicodeUTF8));
        radioButton2->setText(QApplication::translate("radioButtonStyle", "one", 0, QApplication::UnicodeUTF8));
        radioButton3->setText(QApplication::translate("radioButtonStyle", "three", 0, QApplication::UnicodeUTF8));
        radioButton4->setText(QApplication::translate("radioButtonStyle", "four", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class radioButtonStyle: public Ui_radioButtonStyle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RADIOBUTTONSTYLE_H
