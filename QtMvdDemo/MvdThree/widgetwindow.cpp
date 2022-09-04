#include "widgetwindow.h"
#include <QStandardItemModel>
#include <QDebug>
#include "Widget.h"
#include "CustomItemDelegate.h"
#include <QPainter>
#include <QFile>

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

class WidgetWindowPrivate
{
public:
    class CustomString {
    public:
        explicit CustomString(const QString& string, const bool translate) {
            this->string = string;
            this->translate = translate;
        }
        ~CustomString() {}
        QString string;
        bool translate;
    };
    explicit WidgetWindowPrivate(WidgetWindow* parent);
    ~WidgetWindowPrivate();
    void initializeBasicWidget();
private:
    Q_DECLARE_PUBLIC(WidgetWindow)
    WidgetWindow* const q_ptr;
    int m_nListItemWidth;
    int m_nListItemHeight;
    CustomListView* m_CustomListView;
    QStandardItemModel* m_StandardItemModel;
    BluetoothContactDelegate* m_ContactDelegate;
    CustomScrollBar* m_CustomScrollBar;

    QList<ContactInfo> dataList;
};


WidgetWindow::WidgetWindow(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new WidgetWindowPrivate(this))
{
}

WidgetWindow::~WidgetWindow()
{
    if (NULL != d_ptr) {
        delete d_ptr;
    }
}

void WidgetWindow::resizeEvent(QResizeEvent *event)
{
    g_Widget->geometryFit(0, 0, 800, 480, this);
}


WidgetWindowPrivate::WidgetWindowPrivate(WidgetWindow *parent)
    : q_ptr(parent)
{
    m_CustomListView = NULL;
    m_StandardItemModel = NULL;
    m_ContactDelegate = NULL;
    m_CustomScrollBar = NULL;
    m_nListItemWidth = 890;
    m_nListItemHeight = 68;
    initializeBasicWidget();
}

WidgetWindowPrivate::~WidgetWindowPrivate()
{
}


void WidgetWindowPrivate::initializeBasicWidget()
{
    Q_Q(WidgetWindow);
    m_CustomListView = new CustomListView(q);
    m_CustomScrollBar = new CustomScrollBar(q);
    m_CustomListView->setStyleSheet("QScrollBar:vertical{"
                                    "width: " + QString::number(int(47 * g_Widget->widthScalabilityFactor())) + "px;"
                                    "background: transparent;"
                                    "margin: 0px, 0px, 0px, 0px;"
                                    "padding: 0px, 0px, 0px, 0px;"
                                "}"
                                "QScrollBar::handle:vertical{"
                                    "border-top-right-radius: " + QString::number(int(10 * g_Widget->widthScalabilityFactor())) + "px;"
                                    "border-bottom-right-radius: " + QString::number(int(10 * g_Widget->widthScalabilityFactor())) + "px;"
                                    "min-height: " + QString::number(int(47 * g_Widget->heightScalabilityFactor())) + "px;"
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
                                    "margin-left: " + QString::number(int(18 * g_Widget->widthScalabilityFactor())) + "px;"
                                    "margin-right: " + QString::number(int(18 * g_Widget->widthScalabilityFactor())) + "px;"
                                    "background: rgba(42, 42, 42, 191);"
                                "}"
                                "QScrollBar::sub-page:vertical{"
                                    "margin-left: " + QString::number(int(18 * g_Widget->widthScalabilityFactor())) + "px;"
                                    "margin-right: " + QString::number(int(18 * g_Widget->widthScalabilityFactor())) + "px;"
                                    "background: rgba(42, 42, 42, 191);"
                                "}"
        );
    m_ContactDelegate = new BluetoothContactDelegate(q);
    m_StandardItemModel = new QStandardItemModel(q);
    m_CustomListView->setVerticalScrollBar(m_CustomScrollBar);
    m_CustomListView->setItemDelegate(m_ContactDelegate);
    m_CustomListView->setModel(m_StandardItemModel);
    g_Widget->geometryFit(175, 54, 596, 328, m_CustomListView);
    m_CustomListView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);


    for(int i = 0;i < 40;i++){
        ContactInfo info;
        info.name = QString("LiuyifeiLove%1").arg(i);
        info.phone = QString("180775997%1").arg(i);
        info.time = QString("2022-10-10 22:22:%1").arg(i);
        dataList << info;
    }

    QStandardItem* root = m_StandardItemModel->invisibleRootItem();
    for (int i = 0; i < dataList.size(); ++i){
        QStandardItem* item = new QStandardItem();
        item->setSizeHint(QSize(m_nListItemWidth, m_nListItemHeight));
        item->setData(QVariant::fromValue(dataList.at(i)), Qt::DisplayRole);
        root->setChild(root->rowCount(), 0, item);
    }
    m_CustomListView->setVisible(true);
}


BluetoothContactDelegate::BluetoothContactDelegate(QObject *parent)
    : CustomItemDelegate(parent)
{
    QString path(":/images/BluetoothContactListViewRules.png");
    if (QFile::exists(path)){
        m_Rules.reset(new QPixmap(path));
    }

    path = QString(":/images/BluetoothListViewAvatar.png");
    if (QFile::exists(path)){
        m_Icon.reset(new QPixmap(path));
    }

    path = QString(":/images/BluetoothContactListViewItemPress.png");
    if (QFile::exists(path)){
        m_Press.reset(new QPixmap(path));
    }
}

BluetoothContactDelegate::~BluetoothContactDelegate()
{
}

void BluetoothContactDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (!m_Rules.isNull()){
        painter->drawPixmap(0, option.rect.y() + option.rect.height() - 2, 953,2,*m_Rules);
    }

    if (!m_Icon.isNull()){
        int x = 149 * g_Widget->widthScalabilityFactor() - m_Icon->width();
        qDebug()<<"wwwwwwwwwwwwwwwwww "<<x * 0.5f<<" "<<option.rect.y() + (option.rect.height() - m_Icon->height()) * 0.5f;

        painter->drawPixmap(x * 0.5f, option.rect.y() + (option.rect.height() - m_Icon->height()) * 0.5f, 30,30,*m_Icon);
    }

    if (m_PressIndex == index){
        if (!m_Press.isNull()){
            painter->drawPixmap(0, option.rect.y(), 890,68,*m_Press);
        }
    }

    painter->setPen(Qt::green);

    QVariant variant = index.data(Qt::DisplayRole);
    ContactInfo data = variant.value<ContactInfo>();
    QString text1("%1");
    if(data.name.size() > 8){
        text1 = text1.arg(index.row()+1) + QString(" ") + data.name.left(8);
    }else{
        text1 = text1.arg(index.row()+1) + QString(" ") + data.name;
    }
    QRect textRect1 = option.rect.adjusted(119 * g_Widget->widthScalabilityFactor(), 0, 149 * g_Widget->widthScalabilityFactor(), 0);
    QFontMetrics fontMetrics(painter->font());
    text1 = fontMetrics.elidedText(text1, Qt::ElideRight, textRect1.width());
    painter->drawText(textRect1, Qt::AlignLeft | Qt::AlignVCenter, text1);

    QString text2 = data.phone;
    QRect textRect2 = option.rect.adjusted(325 * g_Widget->widthScalabilityFactor(), 0, 298 * g_Widget->widthScalabilityFactor(), 0);
    text2 = fontMetrics.elidedText(text2, Qt::ElideRight, textRect2.width());
    painter->drawText(textRect2, Qt::AlignLeft | Qt::AlignVCenter, text2);
}

void BluetoothContactDelegate::onPressIndexChanged(const QModelIndex &index)
{
    m_PressIndex = index;
}
