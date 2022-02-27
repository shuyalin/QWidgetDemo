#include "savelog.h"

#define QDATE qPrintable(QDate::currentDate().toString("yyyy-MM-dd"))
#define QDATETIMS qPrintable(QDateTime::currentDateTime().toString("yyyy-MM-dd-HH-mm-ss"))



QScopedPointer<SaveLog> SaveLog::self;
//日志重定向
void Log(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    //加锁,防止多线程中qdebug太频繁导致崩溃
    static QMutex mutex;
    QMutexLocker locker(&mutex);
    QString content;

    //这里可以根据不同的类型加上不同的头部用于区分
    int msgType = SaveLog::getInstance()->getMsgType();
    switch (type) {
        case QtDebugMsg:
            if ((msgType & MsgType_Debug) == MsgType_Debug) {
                content = QString("Debug %1").arg(msg);
            }
            break;
#if (QT_VERSION >= QT_VERSION_CHECK(5,5,0))
        case QtInfoMsg:
            if ((msgType & MsgType_Info) == MsgType_Info) {
                content = QString("Infox %1").arg(msg);
            }
            break;
#endif
        case QtWarningMsg:
            if ((msgType & MsgType_Warning) == MsgType_Warning) {
                content = QString("Warnx %1").arg(msg);
            }
            break;
        case QtCriticalMsg:
            if ((msgType & MsgType_Critical) == MsgType_Critical) {
                content = QString("Error %1").arg(msg);
            }
            break;
        case QtFatalMsg:
            if ((msgType & MsgType_Fatal) == MsgType_Fatal) {
                content = QString("Fatal %1").arg(msg);
            }
            break;
    }

    //没有内容则返回
    if (content.isEmpty()) {
        return;
    }
    //还可以将数据转成html内容分颜色区分
    //将内容传给函数进行处理
    SaveLog::getInstance()->save(content);
}

SaveLog::SaveLog(QObject *parent):QObject(parent)
{
    file = new QFile(this);
    path = qApp->applicationDirPath();
    path.append("/syllog");
    fileName = "";
}
SaveLog *SaveLog::getInstance()
{
    if(self.isNull()){
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self.isNull()){
            self.reset(new SaveLog);
        }
    }
    return self.data();
}
void SaveLog::openFile(QString &fileName)
{
    if(this->fileName != fileName){
        this->fileName = fileName;
        if(file->isOpen()){
            file->close();
        }
        file->setFileName(this->fileName);
        file->open(QIODevice::WriteOnly | QIODevice::Append | QFile::Text);
    }
}

//安装日志钩子,输出调试信息到文件,便于调试
void SaveLog::start()
{
#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
    qInstallMessageHandler(Log);
#else
    qInstallMsgHandler(Log);
#endif
}

//卸载日志钩子
void SaveLog::stop()
{
#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
    qInstallMessageHandler(0);
#else
    qInstallMsgHandler(0);
#endif
}
MsgType SaveLog::getMsgType()
{
    return this->msgType;
}
void SaveLog::save(const QString &content)
{
    //目录不存在则先新建目录
    QDir dir(path);
    if (!dir.exists()) {
        dir.mkdir(path);
    }

    //日期改变了才会触发
    QString fileName = QString("%1/%2_log_%3.txt").arg(path).arg(name).arg(QDATE);
    openFile(fileName);

    //用文本流的输出速度更快
    QTextStream stream(file);
    stream << content << "\n";
}
