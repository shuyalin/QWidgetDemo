/********************************************************************************
** Form generated from reading UI file 'testwidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWIDGET_H
#define UI_TESTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *testWidget)
    {
        if (testWidget->objectName().isEmpty())
            testWidget->setObjectName(QString::fromUtf8("testWidget"));
        testWidget->resize(782, 96);
        horizontalLayout = new QHBoxLayout(testWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(testWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(testWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(testWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        retranslateUi(testWidget);

        QMetaObject::connectSlotsByName(testWidget);
    } // setupUi

    void retranslateUi(QWidget *testWidget)
    {
        testWidget->setWindowTitle(QApplication::translate("testWidget", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("testWidget", "i", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("testWidget", "love", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("testWidget", "huyulin", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class testWidget: public Ui_testWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWIDGET_H
