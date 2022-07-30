#include "MultimediaListView.h"
#include "CustomItemDelegate.h"
#include "CustomScrollBar.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMetaType>
#include <QPainter>
#include <QFontMetrics>
#include <QFile>
#include <QPixmap>
#include <QVariant>
#include <QDebug>

class MultimediaVariant
{
public:
    MultimediaVariant();
    ~MultimediaVariant();
    QString m_Text;
    int reserve[MLV_DATA_RESERVE_SIZE];
};
Q_DECLARE_METATYPE(MultimediaVariant)

class MultimediaDelegate : public CustomItemDelegate
{
    Q_DISABLE_COPY(MultimediaDelegate)
public:
    explicit MultimediaDelegate(QObject* parent = NULL);
    ~MultimediaDelegate();
protected:
    void paint(QPainter* painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const;
protected slots:
    void onCurrentIndexChange(const QModelIndex &index);
    void onPressIndexChanged(const QModelIndex &index);
private:
    QModelIndex m_PressIndex;
    QModelIndex m_CurrentIndex;
    QScopedPointer<QPixmap> m_Rules;
    QScopedPointer<QPixmap> m_CheckPixmap;
    QScopedPointer<QPixmap> m_Press;
};

class MultimediaListViewPrivate
{
    Q_DISABLE_COPY(MultimediaListViewPrivate)
public:
    explicit MultimediaListViewPrivate(MultimediaListView* parent);
    ~MultimediaListViewPrivate();
    void initialize();
    QStandardItemModel* m_StandardItemModel;
    MultimediaDelegate* m_MultimediaDelegate;
    CustomScrollBar* m_CustomScrollBar;
private:
    MultimediaListView* m_Parent;
};

MultimediaListView::MultimediaListView(QWidget *parent)
    : CustomListView(parent)
    , m_Private(new MultimediaListViewPrivate(this))
{
}

MultimediaListView::~MultimediaListView()
{
}

void MultimediaListView::clearListView()
{
    m_Private->m_StandardItemModel->clear();
    verticalScrollBar()->setValue(0);
}

void MultimediaListView::appendListView(QString path)
{
    static int ii = 0;
    //QStandardItem* root = m_Private->m_StandardItemModel->invisibleRootItem();
    QStandardItem* item = new QStandardItem();
    item->setSizeHint(QSize((531)  * 1.28, 60 * 1.25));
    MultimediaVariant variant;
    variant.m_Text = path;
    item->setData(qVariantFromValue(variant), Qt::DisplayRole);
    //qDebug()<<"11111111111111 "<<root->rowCount();
    //root->setChild(root->rowCount(), 0, item);
    m_Private->m_StandardItemModel->setItem(ii,0,item);
    ii++;
}

void MultimediaListView::appendListViewData(MultimediaListViewData &data)
{
    QStandardItem* root = m_Private->m_StandardItemModel->invisibleRootItem();
    QStandardItem* item = new QStandardItem();
    item->setSizeHint(QSize((531)  * 1.28, 60 * 1.25));
    MultimediaVariant variant;
    variant.m_Text = data.text;
    memcpy(variant.reserve,data.reserve,MLV_DATA_RESERVE_SIZE*sizeof(int));
    item->setData(qVariantFromValue(variant), Qt::DisplayRole);
    root->setChild(root->rowCount(), 0, item);
}

void  MultimediaListView::removeItem(const int index)
{
    QStandardItem* root = m_Private->m_StandardItemModel->invisibleRootItem();

    if(index <= root->rowCount()) {
        root->removeRow(index);
    }
}

void MultimediaListView::setCurrentIndex(const QModelIndex &index)
{
    CustomListView::setCurrentIndex(index);
}

void MultimediaListView::setCurrentIndex1(const int index)
{
    CustomListView::setCurrentIndex(m_Private->m_StandardItemModel->index(index, 0, QModelIndex()));
}

int MultimediaListView::getListViewRowCount()
{
    QStandardItem* root = m_Private->m_StandardItemModel->invisibleRootItem();

    return root->rowCount();
}

MultimediaListViewData MultimediaListView::getListViewCurrentData(const int index)
{
    QStandardItem* root = m_Private->m_StandardItemModel->invisibleRootItem();
    QStandardItem* item = root->child(index);
    QVariant varient = item->data(Qt::DisplayRole);
    MultimediaVariant mediaVarient = varient.value<MultimediaVariant>();
    MultimediaListViewData data;
    data.text = mediaVarient.m_Text;
    memcpy(data.reserve,mediaVarient.reserve,MLV_DATA_RESERVE_SIZE*sizeof(int));

    return data;
}

MultimediaListViewPrivate::MultimediaListViewPrivate(MultimediaListView *parent)
    : m_Parent(parent)
{
    m_StandardItemModel = NULL;
    m_MultimediaDelegate = NULL;
    m_CustomScrollBar = NULL;
    initialize();
}

MultimediaListViewPrivate::~MultimediaListViewPrivate()
{
}

void MultimediaListViewPrivate::initialize()
{
    m_CustomScrollBar = new CustomScrollBar(m_Parent);
    m_CustomScrollBar->setVisible(false);
    m_CustomScrollBar->setStyleSheet("QScrollBar:vertical{"
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
    m_StandardItemModel = new QStandardItemModel(m_Parent);
    m_MultimediaDelegate = new MultimediaDelegate(m_Parent);
    m_Parent->setVerticalScrollBar(m_CustomScrollBar);
    m_Parent->setItemDelegate(m_MultimediaDelegate);
    m_Parent->setModel(m_StandardItemModel);
    m_Parent->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

MultimediaVariant::MultimediaVariant()
{
    m_Text.clear();
}

MultimediaVariant::~MultimediaVariant()
{
}

MultimediaDelegate::MultimediaDelegate(QObject *parent)
    : CustomItemDelegate(parent)
{
    QString path(":/images/MultimediaListViewRules.png");
    if (QFile::exists(path)) {
        m_Rules.reset(new QPixmap(path));
    }
    path = QString(":/images/MultimediaListViewItemPress.png");
    if (QFile::exists(path)) {
        m_Press.reset(new QPixmap(path));
    }
}

MultimediaDelegate::~MultimediaDelegate()
{
}

void MultimediaDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (!m_Rules.isNull()) {
        painter->drawPixmap(0, option.rect.y() + option.rect.height() - 2, *m_Rules);
    }
    MultimediaVariant variant = qvariant_cast<MultimediaVariant>(index.data(Qt::DisplayRole));
    QString text = QString::number(index.row() + 1) + QString(". ") + variant.m_Text;
    QRect textRect = option.rect.adjusted(75 * 1.28, 0, -75 * 1.28, 0);
    QFontMetrics fontMetrics(painter->font());
    text = fontMetrics.elidedText(text, Qt::ElideRight, textRect.width());
    if (m_CurrentIndex == index) {
        painter->setPen(QColor(0, 162, 255, 191));
    } else {
        painter->setPen(Qt::white);
    }
    if (m_PressIndex == index) {
        if (!m_Press.isNull()) {
            painter->drawPixmap(0, option.rect.y(), *m_Press);
        }
    }
    painter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, text);
}

void MultimediaDelegate::onCurrentIndexChange(const QModelIndex &index)
{
    m_CurrentIndex = index;
}

void MultimediaDelegate::onPressIndexChanged(const QModelIndex &index)
{
    m_PressIndex = index;
}
