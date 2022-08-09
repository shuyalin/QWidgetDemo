#ifndef VIEWPAPERTipWidget_H
#define VIEWPAPERTipWidget_H

#include <QWidget>

class ViewPaperTipWidgetPrivate;
class ViewPaperTipWidget
        : private QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ViewPaperTipWidget)
public:
    explicit ViewPaperTipWidget(QWidget *parent = NULL);
    ~ViewPaperTipWidget();
protected:
    void styleChange();
    void resizeEvent(QResizeEvent* event);
    void paintEvent(QPaintEvent* event);
private:
    Q_DECLARE_PRIVATE(ViewPaperTipWidget)
    ViewPaperTipWidgetPrivate* const d_ptr;
};

#endif // VIEWPAPERTipWidget_H
