#ifndef SAVELOG_H
#define SAVELOG_H
#include <QObject>
#include <QScopedPointer>
#include <QMutex>
#include <QFile>
#include <QDate>
#include <QTextStream>
#include <QDir>
#include <QApplication>
#include <QDebug>

//消息类型
enum MsgType {
    MsgType_Debug = 0x0001,
    MsgType_Info = 0x0002,
    MsgType_Warning = 0x0004,
    MsgType_Critical = 0x0008,
    MsgType_Fatal = 0x0010,
};
class SaveLog:public QObject
{
    Q_OBJECT
public:
    SaveLog(QObject *parent = 0);
    static SaveLog *getInstance();
    void openFile(QString &fileName);
    void saveMessage(QString &message);
    void start();
    void stop();
    void save(const QString &content);
    MsgType getMsgType();
private:
    static QScopedPointer<SaveLog> self;
    QFile *file;
    QString fileName;
    MsgType msgType;
    QString path;
    QString name;
};

#endif // SAVELOG_H
