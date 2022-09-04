<<<<<<< Updated upstream
/********************************************************************************
** Form generated from reading UI file 'frmnavi.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMNAVI_H
#define UI_FRMNAVI_H

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

class Ui_frmNavi
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;

    void setupUi(QWidget *frmNavi)
    {
        if (frmNavi->objectName().isEmpty())
            frmNavi->setObjectName(QStringLiteral("frmNavi"));
        frmNavi->resize(777, 102);
        verticalLayout = new QVBoxLayout(frmNavi);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(frmNavi);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(51, 16777215));
        label->setStyleSheet(QStringLiteral("border-image: url(:/images/AC_N.png);"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(50, 50));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/AC_P.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(60, 50));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb(52, 101, 164);"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);


        verticalLayout_2->addWidget(widget_3);


        verticalLayout->addWidget(widget);


        retranslateUi(frmNavi);

        QMetaObject::connectSlotsByName(frmNavi);
    } // setupUi

    void retranslateUi(QWidget *frmNavi)
    {
        frmNavi->setWindowTitle(QApplication::translate("frmNavi", "Form", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("frmNavi", "TextLabel", Q_NULLPTR));
        pushButton->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class frmNavi: public Ui_frmNavi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMNAVI_H
=======
>>>>>>> Stashed changes
