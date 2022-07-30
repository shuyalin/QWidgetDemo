#ifndef MULTIMEDIALISTVIEW_H
#define MULTIMEDIALISTVIEW_H

#include "CustomListView.h"
#include <QScopedPointer>

#define MLV_DATA_RESERVE_SIZE 7
class MultimediaListViewData{
public:
    QString text;
    int reserve[MLV_DATA_RESERVE_SIZE];
};

class MultimediaListViewPrivate;
class MultimediaListView : public CustomListView
{
    Q_OBJECT
    Q_DISABLE_COPY(MultimediaListView)
public:
    explicit MultimediaListView(QWidget* parent = NULL);
    ~MultimediaListView();
    void clearListView();
    void appendListView(QString path);
    void appendListViewData(MultimediaListViewData &data);
    void setCurrentIndex(const QModelIndex &index);
    void setCurrentIndex1(const int index);
    int getListViewRowCount();
    MultimediaListViewData getListViewCurrentData(const int index);
    void removeItem(const int index);
private:
    friend class MultimediaListViewPrivate;
    QScopedPointer<MultimediaListViewPrivate> m_Private;
};

#endif // MULTIMEDIALISTVIEW_H
