#include "mainwindow.h"
#include "chantier.h"
#include "chantierdelegate.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
#include <QPieSeries>
#include <QChart>
#include <QChartView>
#include <QIcon>
#include<QTimer>

#include <QFile>
#include <QProcess>
#include <QMessageBox>
#include<QCalendarWidget>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , temperatureManager(new SerialTemperatureManager(this))
{
    ui->setupUi(this);

    ui->tableView->setItemDelegate(new ChantierDelegate(this));


    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    setWindowIcon(QIcon(":/icon/logo.jpg"));
    ui->tableView->setModel(c.afficher());
    button_hajjouni();


    detecterChantiersEnRetard();
    ui->datedebut->setDate(QDate::currentDate());
}

MainWindow::~MainWindow()
{
    delete ui;
}







void MainWindow::on_pushButton_ajout_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_clicked()
{
    QString nomchantier = ui->nom->text().trimmed();
    QString adresse = ui->adresse->text().trimmed();


    QDate datedebut = ui->datedebut->date();


    QDate datefinprevu = ui->datefin->date(); // Will be replaced by prediction
    QDate datefinreelle = ui->datefinr->date();
    QString statut = ui->statut->text().trimmed();

    bool ok1, ok2, ok3;
    double budgetinitial = ui->budget->text().toDouble(&ok1);
    double coutreel = ui->coutr->text().toDouble(&ok2);
    int progression = ui->prog->text().toInt(&ok3);
    double temperature =ui->temp->text().toDouble();

    if (nomchantier.isEmpty() || adresse.isEmpty() || statut.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    if (!ok1 || budgetinitial < 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Le budget initial doit être un nombre positif.");
        return;
    }

    if (!ok2 || coutreel < 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Le coût réel doit être un nombre positif.");
        return;
    }

    if (!ok3 || progression < 0 || progression > 100) {
        QMessageBox::warning(this, "Erreur de saisie", "La progression doit être comprise entre 0 et 100.");
        return;
    }

    QString statutLower = statut.toLower();
    if (statutLower != "terminé" && statutLower != "en cours" && statutLower != "en retard") {
        QMessageBox::warning(this, "Erreur de saisie", "Le statut doit être 'terminé', 'en cours' ou 'en retard'.");
        return;
    }

    QDate dateParDefaut(2000, 1, 1);

    if (statutLower == "terminé") {
        if (datefinreelle == dateParDefaut) {
            QMessageBox::warning(this, "Erreur de saisie", "Veuillez renseigner la date de fin réelle pour un chantier terminé.");
            return;
        }
        if (datefinreelle < datedebut) {
            QMessageBox::warning(this, "Erreur de saisie", "La date de fin réelle doit être après la date de début.");
            return;
        }
    }

    if ((statutLower == "en cours" || statutLower == "en retard") && datefinreelle != dateParDefaut) {
        QMessageBox::warning(this, "Erreur de saisie", "La date de fin réelle doit être vide si le chantier n'est pas terminé.");
        return;
    }

    // ⏱️ Prédiction automatique de la date de fin prévue
    QString pythonScript = QCoreApplication::applicationDirPath() + "/predict_duration.py";
    QString pythonPath = "C:/Users/hajjo/AppData/Local/Programs/Python/Python312/python.exe"; // à adapter si besoin

    if (!QFile::exists(pythonScript)) {
        QMessageBox::critical(this, "Erreur", "Script Python introuvable : " + pythonScript);
        return;
    }

    QStringList arguments;
    arguments << pythonScript
              << QString::number(budgetinitial)
              << QString::number(progression)
              << statutLower;

    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.remove("PYTHONHOME");
    env.remove("PYTHONPATH");

    QProcess process;
    process.setProcessEnvironment(env);
    process.setWorkingDirectory(QCoreApplication::applicationDirPath());
    process.start(pythonPath, arguments);

    if (!process.waitForStarted() || !process.waitForFinished(10000)) {
        QMessageBox::warning(this, "Erreur", "Le script de prédiction a échoué.");
        return;
    }

    QString output = QString::fromUtf8(process.readAllStandardOutput()).trimmed();
    QString error = QString::fromUtf8(process.readAllStandardError()).trimmed();

    if (!error.isEmpty()) {
        QMessageBox::critical(this, "Erreur Python", error);
        return;
    }

    QStringList result = output.split("|");
    if (result.size() == 2) {
        int jours = result[0].trimmed().toInt();
        double confiance = result[1].trimmed().toDouble();
        QDate estimation = QDate::currentDate().addDays(jours);
        datefinprevu = estimation;

        QMessageBox::information(this, "📊 Prédiction IA",
                                 QString("📅 Fin estimée du chantier : %1\n"
                                         "🔍 Confiance du modèle : %2%")
                                     .arg(estimation.toString("dd/MM/yyyy"))
                                     .arg(confiance * 100.0, 0, 'f', 2));

    } else {
        QMessageBox::warning(this, "Erreur", "Réponse inattendue du script Python :\n" + output);
        return;
    }

    // Création de l'objet chantier avec la date de fin prédite
    chantier c(0, nomchantier, adresse, datedebut, datefinprevu, datefinreelle, statut, budgetinitial, coutreel, progression,temperature);

    if (c.ajouter()) {
        ui->tableView->setModel(c.afficher());
        button_hajjouni();

        QVector<QString> alertes = c.verifierAlertes();
        if (!alertes.isEmpty()) {
            QString msg = "🔔 Alerte(s) détectée(s) :\n\n" + alertes.join("\n");
            QMessageBox::warning(this, "Alertes chantier", msg);
        }

        // Reset form and change page
        ui->nom->clear();
        ui->adresse->clear();
        ui->datedebut->setDate(QDate::currentDate());
        ui->datefin->setDate(QDate::currentDate());
        ui->datefinr->setDate(QDate(2000, 1, 1));
        ui->statut->clear();
        ui->budget->clear();
        ui->coutr->clear();
        ui->prog->clear();
        ui->temp->clear();

        ui->stackedWidget->setCurrentIndex(0);

        QMessageBox::information(this, "Succès", "Ajout effectué avec succès !");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'ajout du chantier !");
    }
}





void MainWindow::button_hajjouni()
{

    // Add buttons after setting the model
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
            chantier c;

            c.set_id(ui->tableView->model()->index(row, 0).data().toInt());
            c.set_nomchantier(ui->tableView->model()->index(row, 1).data().toString());
            c.set_adresse(ui->tableView->model()->index(row, 2).data().toString());

            QString dateString = ui->tableView->model()->index(row, 3).data().toString();
            QStringList parts = dateString.split("T"); // Split at "T" to separate date and time parts
            QString datePart = parts[0]; // Extract the date part
            QDate date = QDate::fromString(datePart, "yyyy-MM-dd");
            if (date.isValid()) {
                qDebug() << "Parsed date:" << date;
                c.set_datedebut(date);
            } else {
                qDebug() << "Error: Invalid date format!";
                // You may need to handle this error case appropriately
            }

            QString dateString1 = ui->tableView->model()->index(row, 4).data().toString();
            QStringList parts1 = dateString1.split("T"); // Split at "T" to separate date and time parts
            QString datePart1 = parts1[0]; // Extract the date part
            QDate date1 = QDate::fromString(datePart1, "yyyy-MM-dd");
            if (date1.isValid()) {
                qDebug() << "Parsed date:" << date1;
                c.set_datefinprevu(date1);
            } else {
                qDebug() << "Error: Invalid date format!";
                // You may need to handle this error case appropriately
            }

            QString dateString2 = ui->tableView->model()->index(row, 5).data().toString();
            QStringList parts2 = dateString2.split("T"); // Split at "T" to separate date and time parts
            QString datePart2 = parts2[0]; // Extract the date part
            QDate date2 = QDate::fromString(datePart2, "yyyy-MM-dd");
            if (date2.isValid()) {
                qDebug() << "Parsed date:" << date2;
                c.set_datefinreelle(date2);
            } else {
                qDebug() << "Error: Invalid date format!";
                // You may need to handle this error case appropriately
            }
            c.set_statut(ui->tableView->model()->index(row, 6).data().toString());
            c.set_budgetinitial(ui->tableView->model()->index(row, 7).data().toFloat());
            c.set_coutreel(ui->tableView->model()->index(row, 8).data().toFloat());
            c.set_progression(ui->tableView->model()->index(row, 9).data().toInt());
            c.set_temperature(ui->tableView->model()->index(row, 10).data().toFloat());

            on_modifier_chantier_clicked(c);
        });

        connect(delete_button, &QPushButton::clicked, [this, row]() {
            on_delete_chantier_clicked(ui->tableView->model()->index(row, 0).data().toInt());
        });

        ui->tableView->setIndexWidget(ui->tableView->model()->index(row, 11), update_button);
        ui->tableView->setIndexWidget(ui->tableView->model()->index(row, 12), delete_button);
    }
}


void MainWindow::on_modifier_chantier_clicked(chantier c)
{


    // Set values in UI
    ui->id1->setText(QString::number(c.get_id()));
    ui->id1->setHidden(true);
    ui->stackedWidget->setCurrentIndex(2);
    ui->nom1->setText(c.get_nomchantier());
    ui->adresse1->setText(c.get_adresse());

    QDate date = c.get_datedebut();
    QString datestring = date.toString("yyyy-MM-dd");
    ui->dated1->setDate(QDate::fromString(datestring, "yyyy-MM-dd"));
    qDebug() << "Date fin réelle:" << datestring;

    ui->datef1->setDate(c.get_datefinprevu());
    ui->datefr1->setDate(c.get_datefinreelle());

    ui->statut1->setText(c.get_statut());
    ui->budget1->setText(QString::number(c.get_budgetinitial()));
    ui->cout1->setText(QString::number(c.get_coutreel()));
    ui->prog1->setValue(c.get_progression());
    ui->temp1->setText(QString::number(c.get_temperature()));
    // Switch to Modification Page (Page 2)
    ui->stackedWidget->setCurrentIndex(2);
}





void MainWindow::on_delete_chantier_clicked(int id){
    chantier ch = c.getchantierById(id);
    if (ch.get_id()==-1){
        QMessageBox::critical(this, "Error", "This ID doesn't exist!");
    }else{
        bool test=ch.supprimer(id);

        if (test){
            ui->tableView->setModel(ch.afficher());
            button_hajjouni();

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
    // ✅ Récupération de l'ID du chantier en modification

    int id = ui->id1->text().toInt();
    // ✅ Récupération des données depuis l'interface
    QString nomchantier = ui->nom1->text().trimmed();
    QString adresse = ui->adresse1->text().trimmed();
    QDate datedebut = ui->dated1->date();
    QDate datefinprevu = ui->datef1->date();
    QDate datefinreelle = ui->datefr1->date();
    QString statut = ui->statut1->text().trimmed();
    QString statutLower = statut.toLower();

    // ✅ Validation des champs numériques
    bool ok1, ok2;
    double budgetinitial = ui->budget1->text().toDouble(&ok1);
    double coutreel = ui->cout1->text().toDouble(&ok2);
    int progression = ui->prog1->value();
    double temperature = ui->temp1->text().toDouble();

    // ✅ Validation des champs obligatoires
    if (nomchantier.isEmpty() || adresse.isEmpty() || statut.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    if (!ok1 || budgetinitial < 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Le budget initial doit être un nombre positif.");
        return;
    }

    if (!ok2 || coutreel < 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Le coût réel doit être un nombre positif.");
        return;
    }

    if (progression < 0 || progression > 101) {
        QMessageBox::warning(this, "Erreur de saisie", "La progression doit être comprise entre 0 et 100.");
        return;
    }


    // ✅ Statut : contrôle strict
    if (statutLower != "terminé" && statutLower != "en cours" && statutLower != "en retard") {
        QMessageBox::warning(this, "Erreur de saisie", "Le statut doit être 'terminé', 'en cours' ou 'en retard'.");
        return;
    }

    // ✅ Cas spéciaux selon le statut
    QDate dateParDefaut(2000, 1, 1);

    if (statutLower == "terminé") {
        if (datefinreelle == dateParDefaut) {
            QMessageBox::warning(this, "Erreur de saisie", "Veuillez renseigner la date de fin réelle pour un chantier terminé.");
            return;
        }
        if (datefinreelle < datedebut) {
            QMessageBox::warning(this, "Erreur de saisie", "La date de fin réelle doit être après la date de début.");
            return;
        }
    }

    if ((statutLower == "en cours" || statutLower == "en retard") && datefinreelle != dateParDefaut) {
        QMessageBox::warning(this, "Erreur de saisie", "La date de fin réelle doit être vide si le chantier n'est pas terminé.");
        return;
    }





    // 🔮 PREDICTION IA DE LA DATE DE FIN PREVUE
    QString pythonScript = QCoreApplication::applicationDirPath() + "/predict_duration.py";
    QString pythonPath = "C:/Users/hajjo/AppData/Local/Programs/Python/Python312/python.exe"; // adapter si nécessaire

    if (!QFile::exists(pythonScript)) {
        QMessageBox::critical(this, "Erreur", "Script Python introuvable : " + pythonScript);
        return;
    }

    QStringList arguments;
    arguments << pythonScript
              << QString::number(budgetinitial)
              << QString::number(progression)
              << statutLower;

    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.remove("PYTHONHOME");
    env.remove("PYTHONPATH");

    QProcess process;
    process.setProcessEnvironment(env);
    process.setWorkingDirectory(QCoreApplication::applicationDirPath());
    process.start(pythonPath, arguments);

    if (!process.waitForStarted() || !process.waitForFinished(10000)) {
        QMessageBox::warning(this, "Erreur", "Le script de prédiction a échoué.");
        return;
    }

    QString output = QString::fromUtf8(process.readAllStandardOutput()).trimmed();
    QString error = QString::fromUtf8(process.readAllStandardError()).trimmed();

    if (!error.isEmpty()) {
        QMessageBox::critical(this, "Erreur Python", error);
        return;
    }

    QStringList result = output.split("|");
    if (result.size() == 2) {
        int jours = result[0].trimmed().toInt();
        double confiance = result[1].trimmed().toDouble();
        QDate estimation = QDate::currentDate().addDays(jours);
        datefinprevu = estimation;

        QMessageBox::information(this, "📊 Prédiction IA",
                                 QString("📅 Fin estimée du chantier : %1\n"
                                         "🔍 Confiance du modèle : %2%")
                                     .arg(estimation.toString("dd/MM/yyyy"))
                                     .arg(confiance * 100.0, 0, 'f', 2));

    } else {
        QMessageBox::warning(this, "Erreur", "Réponse inattendue du script Python :\n" + output);
        return;
    }








    // ✅ Enregistrement des modifications
    bool test = c.modifier(id, nomchantier, adresse, datedebut, datefinprevu,
                           datefinreelle, statut, budgetinitial, coutreel, progression,temperature);

    if (test) {
        QMessageBox::information(this, "Succès", "Chantier mis à jour avec succès !");
        QSqlQueryModel *newModel = c.afficher();
        ui->tableView->setModel(newModel);
        button_hajjouni();

        chantier chantierModifie(id, nomchantier, adresse, datedebut, datefinprevu,
                                 datefinreelle, statut, budgetinitial, coutreel, progression,temperature);
        QVector<QString> alertes = chantierModifie.verifierAlertes();

        if (!alertes.isEmpty()) {
            QString msg = "⚠️ Alerte(s) détectée(s) :\n\n" + alertes.join("\n");
            QMessageBox::warning(this, "Alertes chantier", msg);
        }


        ui->stackedWidget->setCurrentIndex(0);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la mise à jour");
    }
}



void MainWindow::on_pushButton_8_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}





void MainWindow::on_recherche_input_textChanged(const QString &arg1)
{
    QSqlQueryModel *searchModel = c.search(arg1);

    if (searchModel!=nullptr) {
        ui->tableView->setModel(searchModel);
        button_hajjouni();
    } else{
        QMessageBox::critical(this, "Error", "Search failed. No results found.");
    }
}


void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if (arg1=="id"){
        ui->tableView->setModel(c.sort("id"));
        button_hajjouni();
    }else if (arg1=="Nom du chantier"){
        ui->tableView->setModel(c.sort("nomchantier"));
        button_hajjouni();
    }else if (arg1=="Adresse du chantier"){
        ui->tableView->setModel(c.sort("adresse"));
        button_hajjouni();
    }else if (arg1=="Date debut"){
        ui->tableView->setModel(c.sort("datedebut"));
        button_hajjouni();
    }else if (arg1=="date fin relle"){
        ui->tableView->setModel(c.sort("datefinreelle"));
        button_hajjouni();
    }else if (arg1=="Budget"){
        ui->tableView->setModel(c.sort("budgetinitial"));
        button_hajjouni();
    }else if (arg1=="Cout reel"){
        ui->tableView->setModel(c.sort("coutreel"));
        button_hajjouni();
    }else if (arg1=="Progression"){
        ui->tableView->setModel(c.sort("progression"));
        button_hajjouni();
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if (c.exportToPdf()==true) {
        QMessageBox::information(this, "Done", "PDF exported successfully!");
    } else {
        QMessageBox::critical(this, "Error", "Failed to export PDF!");
    }
}


void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    chantier myChantier;
    QSqlQueryModel *model = myChantier.getEventStatistics();
    qreal tot = 0;
    QMap<QString, qreal> typeCounts;

    if (model) {
        // [Keep your existing data processing code...]
        // Calculate totals and populate typeCounts
        for (int i = 0; i < model->rowCount(); ++i) {
            QString gouvernorat = model->data(model->index(i, 0)).toString();
            qreal count = model->data(model->index(i, 1)).toDouble();
            typeCounts.insert(gouvernorat, count);
            tot += count; // Accumulate total count
        }
        // Create series with enhanced styling
        QPieSeries *seriesC = new QPieSeries();
        seriesC->setPieSize(0.7);  // Make pie smaller to fit legend
        seriesC->setLabelsVisible(true);
        seriesC->setLabelsPosition(QPieSlice::LabelOutside);

        QMapIterator<QString, qreal> it(typeCounts);
        while (it.hasNext()) {
            it.next();
            qreal percentage = (it.value() / tot) * 100;
            QString label = it.key() + " (" + QString::number(percentage, 'f', 2) + "%)";
            QPieSlice *slice = seriesC->append(label, it.value());

            // Custom slice styling
            slice->setLabelVisible(true);
            slice->setLabelArmLengthFactor(0.2);
            slice->setLabelFont(QFont("Arial", 8, QFont::Bold));
            slice->setLabelColor(Qt::white);
            slice->setBorderWidth(2);
        }

        // Enhanced chart styling
        QChart *chartC = new QChart();
        chartC->addSeries(seriesC);
        chartC->setTitle("Statistique des Événements");
        chartC->setTitleFont(QFont("Arial", 12, QFont::Bold));
        chartC->setTitleBrush(QBrush(Qt::white));
        chartC->setTheme(QChart::ChartThemeDark);

        // Background styling
        QLinearGradient backgroundGradient;
        backgroundGradient.setStart(QPointF(0, 0));
        backgroundGradient.setFinalStop(QPointF(0, 1));
        backgroundGradient.setColorAt(0.0, QRgb(0x2E86C1));  // Blue
        backgroundGradient.setColorAt(1.0, QRgb(0x0F3460));  // Dark blue
        backgroundGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        chartC->setBackgroundBrush(backgroundGradient);

        // Legend styling
        chartC->legend()->setVisible(true);
        chartC->legend()->setAlignment(Qt::AlignRight);
        chartC->legend()->setFont(QFont("Arial", 9));
        chartC->legend()->setLabelColor(Qt::white);
        chartC->legend()->setMarkerShape(QLegend::MarkerShapeCircle);

        // Chart view setup
        QChartView *chartViewC = new QChartView(chartC);
        chartViewC->setRenderHint(QPainter::Antialiasing);
        chartViewC->setFixedSize(750, 750);

        // Scene setup
        QGraphicsScene *scene = new QGraphicsScene();
        scene->setBackgroundBrush(QBrush(QColor(0x0F3460)));  // Dark blue background
        scene->addWidget(chartViewC);

        // Final display
        QPixmap pixmap(scene->sceneRect().size().toSize());
        pixmap.fill(Qt::transparent);
        QPainter painter(&pixmap);
        scene->render(&painter);
        ui->label_stat->setPixmap(pixmap);
        ui->label_stat->setAlignment(Qt::AlignCenter);

        delete model;
    }
}




void MainWindow::detecterChantiersEnRetard()
{
    QAbstractItemModel* model = ui->tableView->model();
    int rowCount = model->rowCount();
    QDate aujourdHui = QDate::currentDate();

    for (int row = 0; row < rowCount; ++row) {
        QDate dateFinPrevu = model->index(row, 4).data().toDate();   // Colonne DATEFINPREVU
        int progression = model->index(row, 9).data().toInt();       // Colonne PROGRESSION

        if (dateFinPrevu < aujourdHui && progression < 100) {
            // Marquer comme en retard visuellement
            for (int col = 0; col < model->columnCount(); ++col) {
                ui->tableView->model()->setData(
                    model->index(row, col),
                    QBrush(Qt::red),
                    Qt::ForegroundRole
                    );
            }
        }
    }
}




void MainWindow::on_pushButton_ajout_2_clicked()
{
    // Récupération du chantier sélectionné depuis la table
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Aucun chantier", "Veuillez sélectionner un chantier.");
        return;
    }

    int row = index.row();
    QAbstractItemModel* model = ui->tableView->model();

    // Extraction des informations de la ligne sélectionnée
    QString nom = model->data(model->index(row, 1)).toString();
    QDate datedebut = model->data(model->index(row, 3)).toDate();
    QDate datefinprevu = model->data(model->index(row, 4)).toDate();

    // Création d'une boîte de dialogue avec calendrier
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("📅 Durée du chantier : " + nom);

    QCalendarWidget* calendar = new QCalendarWidget(dialog);
    calendar->setGridVisible(true);

    // 🟨 Format jaune pour toute la durée du chantier
    QTextCharFormat jaune;
    jaune.setBackground(Qt::yellow);
    jaune.setForeground(Qt::black);

    for (QDate d = datedebut; d <= datefinprevu; d = d.addDays(1)) {
        calendar->setDateTextFormat(d, jaune);
    }

    // 🔴 Format rouge pour la date de fin prévue (appliqué par-dessus le jaune)
    QTextCharFormat rouge;
    rouge.setBackground(Qt::red);
    rouge.setForeground(Qt::white);
    calendar->setDateTextFormat(datefinprevu, rouge);

    // Affichage
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    layout->addWidget(calendar);
    dialog->setLayout(layout);
    dialog->exec();
}





void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    if (!index.isValid())
        return;

    // Récupérer l'ID du chantier sélectionné
    int chantierId = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toInt();

    // Démarrer l'écoute Arduino pour ce chantier
    temperatureManager->startListening("COM3", chantierId);

    QMessageBox::information(this, "Température", QString("⏳ Écoute de la température pour le chantier ID : %1").arg(chantierId));

}

