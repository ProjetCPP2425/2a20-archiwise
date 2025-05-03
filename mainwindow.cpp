#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "projet.h"
#include <QMessageBox>
#include <QPieSeries>
#include <QChart>
#include <QChartView>
#include <QIcon>
#include <QQuickItem>
#include <QFileDialog>
#include <QProcess>
#include <QPixmap>
#include <QMessageBox>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::database();

    // Connexion à Arduino
    int ret = A.connect_arduino();

    switch(ret){
    case (0):
        qDebug() << "Arduino connecté au port: " << A.getarduino_port_name();
        break;
    case (1):
        qDebug() << "Arduino détecté mais pas ouvert.";
        break;
    case (-1):
        qDebug() << "Arduino non disponible.";
    }

    // Dans MainWindow.cpp (après connect_arduino())
    if (ret == 0) {
        connect(A.getserial(), &QSerialPort::readyRead, this, &MainWindow::detecterBadge);
    } else {
        qDebug() << "Impossible de connecter le signal readyRead : Arduino non ouvert.";
    }

    // 🛠 HERE inside constructor
    setWindowIcon(QIcon(":/img/logo.jpg"));
    ui->tableView->setModel(ptmp.afficher());
    button_doudi();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajmateriel_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::on_ajouterClient_clicked()
{
    QString nom = ui->nom->text().trimmed();
    QString description = ui->description->text().trimmed();
    QString chefDeProject = ui->chefDeProject->text().trimmed();
    QDate dateDebut = ui->dateDebut->date();
    QDate dateFinPrevu = ui->dateFinPrevu->date();
    float budget = ui->budget->value();
    QString statut = ui->statut->text().trimmed();
    QString adresse = ui->lineEdit_adresse->text();
    QString upload = cheminImageValide;

    if (!imageEstValide) {
        QMessageBox::critical(this, "Erreur", "L'image n'est pas validée comme un plan. Veuillez réessayer.");
        return;
    }

    // Expression régulière pour valider les noms (lettres et espaces uniquement)
    QRegularExpression regex("^[a-zA-ZÀ-ÿ\\s]+$");

    // 1. Vérification des champs obligatoires
    if (nom.isEmpty() || description.isEmpty() || chefDeProject.isEmpty() || statut.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Les champs Nom, Description, Chef de Projet et Statut sont obligatoires.");
        return;
    }

    // 2. Vérification des formats de texte
    if (!regex.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom ne doit contenir que des lettres et des espaces.");
        return;
    }

    if (!regex.match(chefDeProject).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom du chef de projet ne doit contenir que des lettres et des espaces.");
        return;
    }

    if (!regex.match(statut).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le statut ne doit contenir que des lettres et des espaces.");
        return;
    }

    // 3. Vérification du budget
    if (budget <= 0) {
        QMessageBox::warning(this, "Erreur", "Le budget doit être un nombre positif.");
        return;
    }

    // 4. Vérification de la cohérence des dates
    if (dateFinPrevu < dateDebut) {
        QMessageBox::warning(this, "Erreur", "La date de fin prévue doit être postérieure à la date de début.");
        return;
    }

    // Création de l'objet Projet et ajout
    Projet A(0, nom, description, chefDeProject, dateDebut, dateFinPrevu, budget, statut, adresse, upload);

    if (A.ajouter()) {
        ui->tableView->setModel(A.afficher());
        button_doudi();
        QMessageBox::information(this, "Succès", "Le projet a été ajouté avec succès.");

        // ✅ Réinitialisation des champs
        ui->nom->clear();
        ui->description->clear();
        ui->chefDeProject->clear();
        ui->statut->clear();
        ui->budget->setValue(0);
        ui->lineEdit_adresse->clear();
        ui->dateDebut->setDate(QDate::currentDate());
        ui->dateFinPrevu->setDate(QDate::currentDate());

        cheminImageValide.clear();
        imageEstValide = false;
        ui->imageLabel->clear();

        // ✅ Retour à la page principale
        ui->stackedWidget->setCurrentIndex(0);
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout du projet a échoué.");
    }
}


void MainWindow::button_doudi()
{
    for (int row = 0; row < ui->tableView->model()->rowCount(); ++row) {
        QPushButton *update_button = new QPushButton("Update", this);
        update_button->setStyleSheet("QPushButton {"
                                     "background-color:#437FF7;border-radius :5px; "
                                     "color : #fff;"
                                     "}");
        QPushButton *delete_button = new QPushButton("Delete", this);
        delete_button->setStyleSheet("QPushButton {"
                                     "background-color:#ef1f22;border-radius :5px; "
                                     "color : #fff;"
                                     "}");

        connect(update_button, &QPushButton::clicked, [this, row]() {
            Projet p;

            p.set_id(ui->tableView->model()->index(row, 0).data().toInt());
            p.set_nom(ui->tableView->model()->index(row, 1).data().toString());
            p.set_description(ui->tableView->model()->index(row, 2).data().toString());
            p.set_chefDeProjet(ui->tableView->model()->index(row, 3).data().toString());

            QString dateString = ui->tableView->model()->index(row, 4).data().toString();
            QStringList parts = dateString.split("T"); // Split at "T" to separate date and time parts
            QString datePart = parts[0]; // Extract the date part
            QDate date = QDate::fromString(datePart, "yyyy-MM-dd");
            if (date.isValid()) {
                qDebug() << "Parsed date:" << date;
                p.set_dateDebut(date);
            } else {
                qDebug() << "Error: Invalid date format!";
                // You may need to handle this error case appropriately
            }

            QString dateString1 = ui->tableView->model()->index(row, 5).data().toString();
            QStringList parts1 = dateString1.split("T"); // Split at "T" to separate date and time parts
            QString datePart1 = parts1[0]; // Extract the date part
            QDate date1 = QDate::fromString(datePart1, "yyyy-MM-dd");
            if (date1.isValid()) {
                qDebug() << "Parsed date:" << date1;
                p.set_dateFinPrevu(date1);
            } else {
                qDebug() << "Error: Invalid date format!";
                // You may need to handle this error case appropriately
            }


            p.set_budget(ui->tableView->model()->index(row, 6).data().toFloat());
            p.set_statut(ui->tableView->model()->index(row, 7).data().toString());
            p.set_adresse(ui->tableView->model()->index(row, 8).data().toString());
            p.set_upload(ui->tableView->model()->index(row, 9).data().toString());



            on_modifier_projet_clicked(p);
        });

        connect(delete_button, &QPushButton::clicked, [this, row]() {
            on_delete_projet_clicked(ui->tableView->model()->index(row, 0).data().toInt());
        });

        ui->tableView->setIndexWidget(ui->tableView->model()->index(row, 10), update_button);
        ui->tableView->setIndexWidget(ui->tableView->model()->index(row, 11), delete_button);
    }
}
void MainWindow::on_modifier_projet_clicked(Projet p) {
    if (p.get_id() == -1) {
        QMessageBox::critical(this, "Erreur", "Cet ID n'existe pas !");
        return;
    }


    // Fill the modification form (Page 2)
    ui->lineEdit_nom_2->setText(p.get_nom());
    ui->lineEdit_description_2->setText(p.get_description());
    ui->lineEdit_chef_2->setText(p.get_chefDeProjet());
    ui->dateEdit_inscription_4->setDate(p.get_dateDebut());
    ui->dateEdit_inscription_2->setDate(p.get_dateFinPrevu());
    ui->lineEdit_budget_2->setValue(p.get_budget());
    ui->lineEdit_status_2->setText(p.get_statut());
    ui->lineEdit_adresse_2->setText(p.get_adresse());

    // Passage à la page de modification
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_delete_projet_clicked(int id){
    Projet p=ptmp.getprojetById(id);
    if (p.get_id()==-1){
        QMessageBox::critical(this, "Error", "This ID doesn't exist!");
    }else{
        bool test=ptmp.supprimer(id);

        if (test){
            ui->tableView->setModel(ptmp.afficher());
            button_doudi();

            QMessageBox::information(nullptr, QObject::tr("DONE"),
                                     QObject::tr("An event's been deleted.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }else
            QMessageBox::critical(nullptr, QObject::tr("FAIL"),
                                  QObject::tr("Error.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        ui->stackedWidget->setCurrentIndex(0);}

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_modifier_clicked()
{
    int id = ui->tableView->model()->index(ui->tableView->currentIndex().row(), 0).data().toInt();
    QString nom = ui->lineEdit_nom_2->text().trimmed();
    QString description = ui->lineEdit_description_2->text().trimmed();
    QString chefDeProject = ui->lineEdit_chef_2->text().trimmed();
    QDate dateDebut = ui->dateEdit_inscription_4->date();
    QDate dateFinPrevu = ui->dateEdit_inscription_2->date();
    float budget = ui->lineEdit_budget_2->value();
    QString statut = ui->lineEdit_status_2->text().trimmed();
    QString adresse =ui->lineEdit_adresse_2->text();

    // Expression régulière pour valider les noms (lettres et espaces uniquement)
    QRegularExpression regex("^[a-zA-ZÀ-ÿ\\s]+$");

    // 1. Vérification des champs obligatoires
    if (nom.isEmpty() || description.isEmpty() || chefDeProject.isEmpty() || statut.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Les champs Nom, Description, Chef de Projet et Statut sont obligatoires.");
        return;
    }

    // 2. Vérification des formats de texte
    if (!regex.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom ne doit contenir que des lettres et des espaces.");
        return;
    }

    if (!regex.match(chefDeProject).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom du chef de projet ne doit contenir que des lettres et des espaces.");
        return;
    }

    if (!regex.match(statut).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le statut ne doit contenir que des lettres et des espaces.");
        return;
    }

    // 3. Vérification du budget
    if (budget <= 0) {
        QMessageBox::warning(this, "Erreur", "Le budget doit être un nombre positif.");
        return;
    }

    // 4. Vérification de la cohérence des dates
    if (dateFinPrevu < dateDebut) {
        QMessageBox::warning(this, "Erreur", "La date de fin prévue doit être postérieure à la date de début.");
        return;
    }
    QString upload = ui->imageLabel->text();  // Ou autre champ contenant l'image uploadée
    Projet A(id, nom, description, chefDeProject, dateDebut, dateFinPrevu, budget, statut, adresse, upload);

    if (A.modifier()) {
        ui->tableView->setModel(A.afficher());
        button_doudi();
        QMessageBox::information(this, "Succès", "Le projet a été modifiée avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "La modification du projet a échoué.");
    }

    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_tri_currentTextChanged(const QString &arg1)
{
    if (arg1=="ID"){
        ui->tableView->setModel(ptmp.sort("id"));
        button_doudi();
    }else if (arg1=="NOM"){
        ui->tableView->setModel(ptmp.sort("nom"));
        button_doudi();
    }else if (arg1=="lieu"){
        ui->tableView->setModel(ptmp.sort("lieu"));
        button_doudi();
    }else if (arg1=="age"){
        ui->tableView->setModel(ptmp.sort("age"));
        button_doudi();
    }else if (arg1=="date"){
        ui->tableView->setModel(ptmp.sort("date_event"));
        button_doudi();
    }else if (arg1=="dure"){
        ui->tableView->setModel(ptmp.sort("dure"));
        button_doudi();
    }else if (arg1=="type"){
        ui->tableView->setModel(ptmp.sort("type"));
        button_doudi();
    }else if (arg1=="prix"){
        ui->tableView->setModel(ptmp.sort("prix_inscrit"));
        button_doudi();
    }else if (arg1=="adresse"){
        ui->tableView->setModel(ptmp.sort("adresse"));
        button_doudi();
    }

}


void MainWindow::on_recherche_label_textChanged(const QString &arg1)
{
    QSqlQueryModel *searchModel = ptmp.search(arg1);

    if (searchModel!=nullptr) {
        ui->tableView->setModel(searchModel);
        button_doudi();
    } else{
        QMessageBox::critical(this, "Error", "Search failed. No results found.");
    }
}




void MainWindow::on_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    Projet stat;
    QSqlQueryModel *model = stat.getEventStatistics();
    qreal tot = 0;
    QMap<QString, qreal> typeCounts;
    QMapIterator<QString, qreal> it(typeCounts);

    if (model) {
        // Calculate totals and populate typeCounts
        for (int i = 0; i < model->rowCount(); ++i) {
            QString gouvernorat = model->data(model->index(i, 0)).toString();
            qreal count = model->data(model->index(i, 1)).toDouble();
            typeCounts.insert(gouvernorat, count);
            tot += count; // Accumulate total count
        }

        // Create series based on typeCounts
        QPieSeries *seriesC = new QPieSeries();
        QMapIterator<QString, qreal> it(typeCounts);
        while (it.hasNext()) {
            it.next();
            qreal percentage = (it.value() / tot) * 100;
            QString label = it.key() + " (" + QString::number(percentage, 'f', 2) + "%)";
            seriesC->append(label, it.value());

        }

        QChart *chartC = new QChart();
        chartC->addSeries(seriesC);
        chartC->setTitle("Statistique des Event");
        chartC->setTheme(QChart::ChartThemeLight);
        chartC->legend()->setVisible(true);
        chartC->legend()->setAlignment(Qt::AlignRight);

        QChartView *chartViewC = new QChartView(chartC);
        chartC->setBackgroundBrush(QBrush(QColor(87, 169, 209)));

        QGraphicsScene *scene = new QGraphicsScene();
        scene->addWidget(chartViewC);

        QColor colors(87, 169, 209);
        QBrush brush(colors);
        scene->setBackgroundBrush(brush);

        chartViewC->setFixedSize(700, 700);
        scene->setSceneRect(QRectF(chartViewC->rect()));

        QPixmap pixmap(scene->sceneRect().size().toSize());
        pixmap.fill(Qt::transparent);
        QPainter painter(&pixmap);
        chartViewC->render(&painter);


        ui->label_stat->setPixmap(pixmap);

        delete model;
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if (ptmp.exportToPdf()==true) {
        QMessageBox::information(this, "Done", "PDF exported successfully!");
    } else {
        QMessageBox::critical(this, "Error", "Failed to export PDF!");
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_map_clicked()
{
    QItemSelectionModel *selectionModel = ui->tableView->selectionModel();
    QModelIndexList selectedIndexes = selectionModel->selectedIndexes();

    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView->model());

    if (model) {
        QSet<int> selectedRows;

        foreach(const QModelIndex &selectedIndex, selectedIndexes) {
            int row = selectedIndex.row();
            if (!selectedRows.contains(row)) {
                // Access data from the fifth column of the selected row
                QModelIndex fifthColumnIndex = model->index(row, 8);
                QVariant cellData = model->data(fifthColumnIndex);

                // Split the data by comma and trim any whitespace
                QStringList parties = cellData.toString().split(",", Qt::SkipEmptyParts);
                if (parties.size() >= 2) {
                    ui->quickWidget_Map_View->setSource(QUrl(QStringLiteral("qrc:/img/QmlMap.qml")));
                    ui->quickWidget_Map_View->show();

                    auto obje = ui->quickWidget_Map_View->rootObject();
                    if (obje) {
                        QString premierePartie = parties[0].trimmed();
                        QString deuxiemePartie = parties[1].trimmed();
                        double lat = premierePartie.toDouble();
                        double lon = deuxiemePartie.toDouble();

                        qDebug() << "Coordinates:" << lat << lon;

                        QVariant latVar(lat);
                        QVariant lonVar(lon);

                        QMetaObject::invokeMethod(static_cast<QObject*>(obje), "setCenterPosition",
                                                  Q_ARG(QVariant, latVar),
                                                  Q_ARG(QVariant, lonVar));

                        QMetaObject::invokeMethod(static_cast<QObject*>(obje), "setLocationMarking",
                                                  Q_ARG(QVariant, latVar),
                                                  Q_ARG(QVariant, lonVar));
                    }



                } else {
                    qDebug() << "La chaîne ne contient pas suffisamment de parties séparées par des virgules.";
                }
                selectedRows.insert(row);
            }
        }
    }

    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_uploadButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Choisir une image", "", "Images (*.png *.jpg *.jpeg)");
    if (filePath.isEmpty())
        return;

    // Affichage dans l'interface
    QPixmap image(filePath);
    ui->imageLabel->setPixmap(image.scaled(ui->imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // Reset des variables IA
    imageEstValide = false;
    cheminImageValide = "";

    qDebug() << "Image uploadée :" << filePath;

    // Lancement du script Python
    QProcess *pythonProcess = new QProcess(this);
    QString scriptPath = "C:/Users/ahdbe/OneDrive/Desktop/dataset/predict_plan.py";  // chemin absolu du script
    QStringList arguments;
    arguments << scriptPath << filePath;

    connect(pythonProcess, &QProcess::finished, this, [=](int exitCode, QProcess::ExitStatus exitStatus) {
        QString outputFull = QString::fromUtf8(pythonProcess->readAllStandardOutput());
        QStringList lines = outputFull.split("\n", Qt::SkipEmptyParts);
        QString output = lines.last().trimmed().toLower();

        qDebug() << "Sortie finale du modèle (filtrée):" << output;

        if (output == "valid") {
            imageEstValide = true;
            cheminImageValide = filePath;
            QMessageBox::information(this, "Image validée", "✅ Cette image est reconnue comme un plan.");
        } else {
            imageEstValide = false;
            cheminImageValide = "";
            QMessageBox::warning(this, "Image rejetée", "❌ Cette image n'est pas reconnue comme un plan.");
            ui->imageLabel->clear();
        }

        pythonProcess->deleteLater();
    });

    connect(pythonProcess, &QProcess::readyReadStandardError, this, [=]() {
        qDebug() << "Erreur Python :" << pythonProcess->readAllStandardError();
    });

    pythonProcess->start("python", arguments);
}
void MainWindow::detecterBadge() {
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Erreur", "Base de données non connectée !");
        return;
    }

    if (!A.getserial()->isOpen()) {
        qDebug() << "Erreur : Port Arduino non ouvert !";
        return;
    }

    QByteArray data = A.read_from_arduino();
    qDebug() << "Données brutes reçues :" << data.toHex();

    QString idCarte = QString(data).trimmed();
    qDebug() << "ID Carte après trim :" << idCarte;

    if (idCarte.isEmpty()) {
        qDebug() << "Aucune donnée valide reçue.";
        return;
    }

    QSqlQuery query(db);
    query.prepare("SELECT \"NOM\" FROM \"EMPLOYES\" WHERE \"ID_CARTE\" = :id");
    query.bindValue(":id", idCarte);

    if (!query.exec()) {
        qDebug() << "Erreur SQL :" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Problème de base de données : " + query.lastError().text());
        return;
    }

    if (query.next()) {
        QString nomEmploye = query.value(0).toString();
        QMessageBox::information(this, "Succès", "Employé : " + nomEmploye);

        // Envoyer au LCD
        QString message = "Employé: " + nomEmploye + "\n";
        A.write_to_arduino(message.toUtf8());
    } else {
        qDebug() << "Aucun employé trouvé pour ID :" << idCarte;
        QMessageBox::warning(this, "Inconnu", "Carte non enregistrée.");

        // Envoyer au LCD
        QString message = "Carte Inconnue\n";
        A.write_to_arduino(message.toUtf8());
    }
}
