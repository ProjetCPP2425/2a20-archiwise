#ifndef CUSTOMSORTPROXYMODEL_H
#define CUSTOMSORTPROXYMODEL_H

#include <QSortFilterProxyModel>

class CustomSortProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit CustomSortProxyModel(QObject *parent = nullptr)
        : QSortFilterProxyModel(parent) {}

protected:
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    // ... (votre code existant)

private slots:
    void on_btnTrier_clicked();

private:
    void chargerDonnees();
    CustomSortProxyModel *proxyModel; // Ajoutez ce membre
};
