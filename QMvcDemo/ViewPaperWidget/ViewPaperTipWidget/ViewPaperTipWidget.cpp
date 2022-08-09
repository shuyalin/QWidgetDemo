#include "ViewPaperTipWidget.h"
#include "AutoConnect/AutoConnect.h"
#include  "uihelper.h"
#include <QPainter>
#include <QPixmap>
#include <QDebug>

class ViewPaperTipWidgetPrivate
{
public:
    ViewPaperTipWidgetPrivate(ViewPaperTipWidget* parent);
    ~ViewPaperTipWidgetPrivate();
    void initializeParent();
    void initializeBasic();
private:
    Q_DECLARE_PUBLIC(ViewPaperTipWidget)
    ViewPaperTipWidget* const q_ptr;
    QPixmap* m_VisibleTip;
    QPixmap* m_InvisibleTip;
    QPixmap* m_Viewpaper0;
    QPixmap* m_ViewPaper1;
    QPixmap* m_ViewPaper2;
    bool m_Reload;
};

ViewPaperTipWidget::ViewPaperTipWidget(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new ViewPaperTipWidgetPrivate(this))
{
}

ViewPaperTipWidget::~ViewPaperTipWidget()
{
    if (NULL != d_ptr) {
        delete d_ptr;
    }
}

void ViewPaperTipWidget::styleChange()
{
    Q_D(ViewPaperTipWidget);
    d->m_Reload = true;
}

void ViewPaperTipWidget::resizeEvent(QResizeEvent *event)
{
    UiHelper::instance()->geometryFit(0, 0, 800, 40, this);
}

void ViewPaperTipWidget::paintEvent(QPaintEvent *event)
{
    Q_D(ViewPaperTipWidget);
    QPainter painter(this);
    if (NULL != d->m_Viewpaper0) {
        int x = 800  * 0.5 - 12 * 2;
        int y = (40 - 11) * 0.5;
        painter.drawPixmap(x * SCALED_FACTOR_X, y * SCALED_FACTOR_Y, *d->m_Viewpaper0);
    }
    if (NULL != d->m_ViewPaper1) {
        int x = 800 * 0.5 + 12;
        int y = (40 - 11) * 0.5;
        painter.drawPixmap(x * SCALED_FACTOR_X, y * SCALED_FACTOR_Y, *d->m_ViewPaper1);
    }
    if (NULL != d->m_ViewPaper2) {
        int x = 800 * 0.5 + 12 + 36;
        int y = (40 - 11) * 0.5;
        painter.drawPixmap(x * SCALED_FACTOR_X, y * SCALED_FACTOR_Y, *d->m_ViewPaper2);
    }
}


ViewPaperTipWidgetPrivate::ViewPaperTipWidgetPrivate(ViewPaperTipWidget *parent)
    : q_ptr(parent)
{
    m_VisibleTip = NULL;
    m_InvisibleTip = NULL;
    m_Viewpaper0 = NULL;
    m_ViewPaper1 = NULL;
    m_ViewPaper2 = NULL;
    m_Reload = false;
    initializeParent();
    initializeBasic();
}

ViewPaperTipWidgetPrivate::~ViewPaperTipWidgetPrivate()
{
    if (NULL != m_VisibleTip) {
        delete m_VisibleTip;
        m_VisibleTip = NULL;
    }
    if (NULL != m_InvisibleTip) {
        delete m_InvisibleTip;
        m_InvisibleTip = NULL;
    }
}

void ViewPaperTipWidgetPrivate::initializeParent()
{
    Q_Q(ViewPaperTipWidget);
    q->setVisible(true);
}

void ViewPaperTipWidgetPrivate::initializeBasic()
{
    m_VisibleTip = new QPixmap(QString(":/Images/ViewPaperTipWidgetVisible.png"));
    m_Viewpaper0 = m_VisibleTip;
    m_InvisibleTip = new QPixmap(QString(":/Images/ViewPaperTipWidgetInvisible.png"));
    m_ViewPaper1 = m_InvisibleTip;
    m_ViewPaper2 = m_InvisibleTip;
    Q_Q(ViewPaperTipWidget);
}
