
//m.cpp文件内容
#include "m.h"
int main(int argc, char *argv[]){    
    QApplication aa(argc,argv);
    D *d=new D(3,3);   					//创建一个3行3列的表格模型
    QTableView *pv2=new QTableView;   	//使用表格视图来显示以上模型管理的数据
/*读者也可使用以下视图来显示模型d中的数据，但要去掉data()中对if(role==Qt::SizeHintRole)的注释，还要注意，若使用树形视图显示，有可能会使程序崩溃，因为本示例未完整的实现树形模型结构*/
    //QListView *pv2=new QListView;
//QTreeView *pv2=new QTreeView;

//向模型中添加数据
    d->setData(d->index(0,0,QModelIndex()),"111",Qt::DisplayRole);
    d->setData(d->index(1,0,QModelIndex()),222);
    d->setData(d->index(1,1,QModelIndex()),333);
    d->setData(d->index(2,1,QModelIndex()),QIcon("F:/1i.png"),Qt::DecorationRole);
    pv2->setModel(d);
    pv2->resize(333,222);
    pv2->show();
    return aa.exec();
}
