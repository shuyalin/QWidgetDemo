
//m.h文件内容
#ifndef M_H
#define M_H
#include<QWidget>
#include <QApplication>
#include <QTableView>
#include <QAbstractItemModel>
#include <iostream>
using namespace std;
class D:public QAbstractItemModel{  //继承抽象类QAbstractItemModel
    public:
    int col,rw;   		//表格模型的列数和行数
    QList<QVariant> s1;	//这是模型管理的数据
    QList<int> rol;    	//存储数据的角色
    //读者可把以一两项单独封装在一个类(比如xxxItem)中进行管理，Qt内置模型就是这样处理的
//构造函数表示创建一个i行j列的表格模型
    D(int i, int j):rw(i),col(j){	for(int k=0;k<col*rw;k++){ s1<<QVariant();	rol<<-1;} }
//①、返回表格模型的行数
int rowCount(const QModelIndex &parent = QModelIndex ()) const{return rw;	}
//②、返回表格模型的列数
int columnCount(const QModelIndex &parent =QModelIndex ()) const{return col;}
//③、返回表格模型的父索引，因为所有单元格都是顶级节点，所以使用无效节点作为父节点
QModelIndex parent(const QModelIndex &index) const{      return QModelIndex();}
//④、为每个单元格创建一个唯一的索引
QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex ()) const
{
    cout<<"index"<<endl;          //测试语句
    		//其他模型可能需要判断传递进来的索引是否有效。
    		//if(!hasIndex(row,column,parent))return QModelIndex();
/*本示例仅需简单的为传递进来的单元格创建一个索引即可，注意第3个参数的使用(请参阅createIndex()的原型)，由此处可见，第3个参数其实质就是指指向模型实际所管理的数据。*/
            return createIndex(row, column, (void*)&(s1.at(row*column+column)));
}
//⑤、返回视图上显示的数据，该函数会被视图多次调用(注：其他虚函数同样会被Qt调用多次)
QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const
{
    //测试用，读者可看到每次调用时Qt内部传递进来的role(角色)的值。
    cout<<"data="<<role<<endl;
    		int i=index.row()*col+index.column();  //单元格所在数据s1中的位置
//以下对不同角色返回的数据会被视图使用，以正确的显示在其单元格中。
/*对于QListView和QTreeView必须对所在节点设置大小，否则这两个视图不会显示任何内容(因为节点大小为0）*/
    		//if(role==Qt::SizeHintRole)return QSize(55,55);
/*设置角色CheckStateRole的数据。本示例返回一个无效的QVariant作为该角色的数据， 若返回有效值，会使单元格的左侧显示一个复选框。*/
    		if(role==Qt::CheckStateRole)return QVariant();
    		//设置单元格中数据的对齐方式。本示例为左侧垂直居中对齐
            //if(role==Qt::TextAlignmentRole)   return (Qt::AlignLeft|Qt::AlignVCenter);
   		//设置角色DecorationRole(图片)的数据
    		if(role==Qt::DecorationRole)
        		//若用户设置了DecorationRole角色的数据，则返回用户为该单元格设置的数据。
        		if(rol.at(i)==Qt::DecorationRole)          return s1.at(i);
//若用户为角色EditRole或DisplayRole角色设置了数据，则返回用户为该单元格设置的数据。
    		if(role==Qt::EditRole|role==Qt::DisplayRole)
if(rol.at(i)==Qt::EditRole|rol.at(i)==Qt::DisplayRole)	return s1.at(i);
//其余角色使用无效数据
            return QVariant();
}	//data()结束
//⑥、重载setData以使用户可以向模型中添加数据
  	bool setData(const QModelIndex &index,const QVariant &value, int role=Qt :: EditRole)
  	{/*使用数据value和角色role分别替换列表s1和rol中原有的值，使用replace便于下一个示例(拖放)的使用。*/
  		s1.replace(index.row()*col+index.column(),value);
  		rol.replace(index.row()*col+index.column(),role);
     	emit dataChanged(index, index);    	//数据改变后，需要发送此信号。
        return true;
    }
};			//返回true，表示数据设置成功。
#endif // M_H

