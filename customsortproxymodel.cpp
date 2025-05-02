
#include <QDate>

DateSortProxyModel::DateSortProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent) {}

bool DateSortProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    // Colonnes de date (7: début, 8: fin)
    if (left.column() == 7 || left.column() == 8) {
        QDate leftDate = sourceModel()->data(left, Qt::UserRole).toDate();
        QDate rightDate = sourceModel()->data(right, Qt::UserRole).toDate();
        return leftDate < rightDate;
    }

    // Colonne Expiring Soon (9)
    if (left.column() == 9) {
        return sourceModel()->data(left).toInt() < sourceModel()->data(right).toInt();
    }

    // Tri texte pour les autres colonnes
    return sourceModel()->data(left).toString().toLower()
           < sourceModel()->data(right).toString().toLower();
}
