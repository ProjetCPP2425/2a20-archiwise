#ifndef CHANTIERDELEGATE_H
#define CHANTIERDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QDate>

class ChantierDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ChantierDelegate(QObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;
};

#endif // CHANTIERDELEGATE_H
