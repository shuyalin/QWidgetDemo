#ifndef WIDGETWINDOW_H
#define WIDGETWINDOW_H

#include <QWidget>
#include <QStandardItem>
#include <QScrollBar>
#include "customlistview.h"
#include "customscrollbar.h"


typedef struct  {
    QString name;
    QString phone;
    QString time;
}ContactInfo;
Q_DECLARE_METATYPE(ContactInfo)

class WidgetWindowPrivate;
class WidgetWindow
        : private QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(WidgetWindow)
public:
    explicit WidgetWindow(QWidget *parent = NULL);
    ~WidgetWindow();
protected:
    void resizeEvent(QResizeEvent* event);

private:
    Q_DECLARE_PRIVATE(WidgetWindow)
    WidgetWindowPrivate* const d_ptr;
};

#endif // WIDGETWINDOW_H
