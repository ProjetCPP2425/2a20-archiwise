#include "chantierdelegate.h"
#include <QApplication>
#include <QAbstractItemModel>

ChantierDelegate::ChantierDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

void ChantierDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    QStyleOptionViewItem opt = option;
    initStyleOption(&opt, index);

    // On récupère toute la ligne (modèle)
    const QAbstractItemModel *model = index.model();

    // Supposons les colonnes : 0:ID, 1:NOM, 2:ADRESSE, 3:DATE DEBUT, 4:DATE FIN PREVUE, 5:DATE FIN REELLE
    // 6:STATUT, 7:BUDGET INIT, 8:COUT REEL, 9:PROGRESSION

    QDate dateFinPrevue = model->index(index.row(), 4).data().toDate();
    double budgetInitial = model->index(index.row(), 7).data().toDouble();
    double coutReel = model->index(index.row(), 8).data().toDouble();
    int progression = model->index(index.row(), 9).data().toInt();

    bool estEnRetard = (progression < 100 && dateFinPrevue.isValid() && dateFinPrevue < QDate::currentDate());
    bool depassementBudget = (coutReel > budgetInitial && budgetInitial > 0);

    if (estEnRetard || depassementBudget) {
        painter->fillRect(opt.rect, QColor(255, 102, 102)); // Rouge clair
    }

    QStyledItemDelegate::paint(painter, opt, index);
}
