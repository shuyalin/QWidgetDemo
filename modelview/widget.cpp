#include "widget.h"
#include "ui_widget.h"
#include <QDir>
#include <QModelIndex>
#include <QByteArray>
#include <QBuffer>
#include <QTextStream>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_edit.setParent(this);
    m_edit.move(10, 10);
    m_edit.resize(500, 300);

    connect(&m_fsm, SIGNAL(directoryLoaded(QString)), this, SLOT(onDirectoryLoaded(QString)));
    //This signal is emitted when the gatherer thread has finished to load the path.

    m_fsm.setRootPath(QDir::currentPath()); // 为模型设置数据源
    // 有感：所谓模型其实不过是一系列数据操作的封装
}

Widget::~Widget()
{
    delete ui;
}
//目录加载完毕后槽函数调用
void Widget::onDirectoryLoaded(const QString& path)
{
    QModelIndex root = m_fsm.index(path, 0);  //Returns the model index for the given path and column.
    QByteArray array;
    QBuffer buffer(&array);

    if( buffer.open(QIODevice::WriteOnly) )
    {
        QTextStream out(&buffer);

        out << m_fsm.isDir(root) << endl;
        out << m_fsm.data(root).toString() << endl; // 模型通过模型索引拿数据
        out << root.data().toString() << endl;      // 可以直接通过索引取数据

        out << &m_fsm << endl;
        out << root.model() << endl;         // Returns a pointer to the model containing the item that this index refers to.
        out << m_fsm.filePath(root) << endl; // Returns the path of the item stored in the model under the index given
        out << m_fsm.fileName(root) << endl; // Returns the path of the item stored in the model under the index given.
        out << endl;

        // Returns the number of rows under the given parent
        for(int i=0; i<m_fsm.rowCount(root); i++)
        {
            QModelIndex ci = m_fsm.index(i, 0, root); // 第i行第0列数据的索引

            out << ci.data().toString() << endl;      // 索引关联数据
        }

        out.flush();
        buffer.close();
    }

    if( buffer.open(QIODevice::ReadOnly) )
    {
        QTextStream in(&buffer);

        m_edit.insertPlainText(in.readAll());

        buffer.close();
    }
}
