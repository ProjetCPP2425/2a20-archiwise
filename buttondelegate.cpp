#include "ButtonDelegate.h"
#include <QPushButton>
#include <QApplication>
#include <QMouseEvent>
#include <QPainter>

ButtonDelegate::ButtonDelegate(QObject *parent) : QStyledItemDelegate(parent) {}

void ButtonDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QStyledItemDelegate::paint(painter, option, index);

    // Configuration des styles
    QString editStyle = "color: rgb(0, 0, 0); background-color: #4CAF50; border-radius: 10px; padding: 2px;";
    QString deleteStyle = "color: rgb(0, 0, 0); background-color: #F44336; border-radius: 10px; padding: 2px;";

    // Dessiner le bouton Modifier (vert)
    QRect editRect = QRect(option.rect.left() + 5, option.rect.top() + 5, 80, option.rect.height() - 10);
    painter->save();
    painter->setPen(Qt::black);
    painter->setBrush(QColor("#4CAF50"));
    painter->drawRoundedRect(editRect, 10, 10);
    painter->drawText(editRect, Qt::AlignCenter, "Modifier");
    painter->restore();

    // Dessiner le bouton Supprimer (rouge)
    QRect deleteRect = QRect(option.rect.left() + 95, option.rect.top() + 5, 80, option.rect.height() - 10);
    painter->save();
    painter->setPen(Qt::black);
    painter->setBrush(QColor("#F44336"));
    painter->drawRoundedRect(deleteRect, 10, 10);
    painter->drawText(deleteRect, Qt::AlignCenter, "Supprimer");
    painter->restore();
}

bool ButtonDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) {
    if (event->type() == QEvent::MouseButtonRelease) {
        QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);
        if (!mouseEvent) return false;

        QRect editRect = QRect(option.rect.left() + 5, option.rect.top() + 5, 80, option.rect.height() - 10);
        QRect deleteRect = QRect(option.rect.left() + 95, option.rect.top() + 5, 80, option.rect.height() - 10);

        if (editRect.contains(mouseEvent->pos())) {
            emit editClicked(index.row());
            return true;
        } else if (deleteRect.contains(mouseEvent->pos())) {
            emit deleteClicked(index.row());
            return true;
        }
    }
    return QStyledItemDelegate::editorEvent(event, model, option, index);
}
