#ifndef MUITEMDELEGATE_H
#define MUITEMDELEGATE_H

#include <QStyledItemDelegate>

class MuItemDelegate : public QStyledItemDelegate
{
public:
    MuItemDelegate(QObject *parent = nullptr);

    // painting
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const override;
};

#endif // MUITEMDELEGATE_H
