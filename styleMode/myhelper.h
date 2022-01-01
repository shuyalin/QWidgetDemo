#ifndef MYHELPER_H
#define MYHELPER_H
#include <QApplication>
#include <QObject>
#include <QFile>
#include <QString>
#include <QDebug>
class myHelper:public QObject
{
    Q_OBJECT
public:
    myHelper();
    static void setStyle(const QString &styleName){
        QFile file(QString("%1").arg(styleName));
        if(!file.open(QFile::ReadOnly))
            qDebug()<<"open file errolr";
        QString qss = QLatin1String(file.readAll());
        qApp->setStyleSheet(qss);
    }
};
#endif // MYHELPER_H
