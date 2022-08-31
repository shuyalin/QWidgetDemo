#include "widget.h"
#include "ui_widget.h"
#include "CustomItemDelegate.h"
#include "CustomScrollBar.h"
#include "CustomListView.h"
#include <QStandardItemModel>
#include <QStyleOptionViewItem>
#include <QPainter>

class BluetoothContactDelegate : public CustomItemDelegate
{
    Q_DISABLE_COPY(BluetoothContactDelegate)
public:
    explicit BluetoothContactDelegate(QObject* parent = NULL);
    ~BluetoothContactDelegate();
protected:
    void paint(QPainter* painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const;
protected slots:
    void onPressIndexChanged(const QModelIndex &index);
private:
    QModelIndex m_PressIndex;
    QScopedPointer<QPixmap> m_Rules;
    QScopedPointer<QPixmap> m_Icon;
    QScopedPointer<QPixmap> m_Press;
};


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initItem()
{
    list <<"1111"<<"2222"<<"3333"<<"4444"<<"5555"<<"6666";
    m_CustomListView = new CustomListView(this);
    m_CustomScrollBar = new CustomScrollBar(this);
    m_CustomListView->setStyleSheet("QScrollBar:vertical{"
    "width: " + QString::number(int(47 * 1.28)) + "px;"
    "background: transparent;"
    "margin: 0px, 0px, 0px, 0px;"
    "padding: 0px, 0px, 0px, 0px;"
    "}"
    "QScrollBar::handle:vertical{"
    "border-top-right-radius: " + QString::number(int(10 * 1.28)) + "px;"
    "border-bottom-right-radius: " + QString::number(int(10 * 1.28)) + "px;"
     "min-height: " + QString::number(int(47 * 1.28)) + "px;"
     "background: rgba(0, 162, 255, 191);"
    "}"
    "QScrollBar::add-line:vertical{"
    "height: 0px;"
    "width: 0px;"
    "}"
    "QScrollBar::sub-line:vertical{"
    "height: 0px;"
    "width: 0px;"
    "}"
    "QScrollBar::add-page:vertical{"
    "margin-left: " + QString::number(int(18 * 1.28)) + "px;"
    "margin-right: " + QString::number(int(18 * 1.28)) + "px;"
    "background: rgba(42, 42, 42, 191);"
    "}"
    "QScrollBar::sub-page:vertical{"
    "margin-left: " + QString::number(int(18 * 1.28)) + "px;"
    "margin-right: " + QString::number(int(18 * 1.28)) + "px;"
    "background: rgba(42, 42, 42, 191);"
    "}"
     );
    m_ContactDelegate = new BluetoothContactDelegate(this);
    m_StandardItemModel = new QStandardItemModel(this);
    m_CustomListView->setVerticalScrollBar(m_CustomScrollBar);
    m_CustomListView->setItemDelegate(m_ContactDelegate);
    m_CustomListView->setModel(m_StandardItemModel);
    QStandardItem* root = m_StandardItemModel->invisibleRootItem();
    for (int i = 0; i < list.size(); ++i) {
        QStandardItem* item = new QStandardItem();
        item->setSizeHint(QSize((696)  * 1.28, 55 * 1.25));
        item->setData(qVariantFromValue(list.at(i)), Qt::DisplayRole);
        root->setChild(root->rowCount(), 0, item);
    }
    m_CustomListView->setVisible(true);
}
BluetoothContactDelegate::BluetoothContactDelegate(QObject *parent)
    : CustomItemDelegate(parent)
{
    QString path(":/Images/BluetoothContactListViewRules.png");
    if (QFile::exists(path)) {
        m_Rules.reset(new QPixmap(path));
    }
    path = QString(":/Images/BluetoothListViewAvatar.png");
    if (QFile::exists(path)) {
        m_Icon.reset(new QPixmap(path));
    }
    path = QString(":/Images/BluetoothContactListViewItemPress.png");
    if (QFile::exists(path)) {
        m_Press.reset(new QPixmap(path));
    }
}

BluetoothContactDelegate::~BluetoothContactDelegate()
{
}

void BluetoothContactDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (!m_Rules.isNull()) {
        painter->drawPixmap(0, option.rect.y() + option.rect.height() - 2, *m_Rules);
    }
    if (!m_Icon.isNull()) {
        int x = 149 * 1.28 - m_Icon->width();
        painter->drawPixmap(x * 0.5f, option.rect.y() + (option.rect.height() - m_Icon->height()) * 0.5f, *m_Icon);
    }
    if (m_PressIndex == index) {
        if (!m_Press.isNull()) {
            painter->drawPixmap(0, option.rect.y(), *m_Press);
        }
    }
    painter->setPen(Qt::white);
    QString text1("%1");
    text1 = text1.arg(index.row() + 1, 3, 10, QChar('0')) + QString(". ") + "hello";
    QRect textRect1 = option.rect.adjusted(119 * 1.28, 0, 149 * 1.28, 0);
    QFontMetrics fontMetrics(painter->font());
    text1 = fontMetrics.elidedText(text1, Qt::ElideRight, textRect1.width());
    painter->drawText(textRect1, Qt::AlignLeft | Qt::AlignVCenter, text1);
    QRect textRect2 = option.rect.adjusted(325 * 1.28, 0, 298 * 1.25, 0);
    painter->drawText(textRect2, Qt::AlignLeft | Qt::AlignVCenter, "text2");
}

void BluetoothContactDelegate::onPressIndexChanged(const QModelIndex &index)
{
    m_PressIndex = index;
}
