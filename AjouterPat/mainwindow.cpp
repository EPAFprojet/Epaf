#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QtSql>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("MarcoServ");
    db.setUserName("EPAF");
    db.setPassword("");
    if (!db.open())
    {
        QMessageBox::critical(0,QObject::tr("database error"), db.lastError().text());
    }
    //------------------------------------------Set up des combos box:groupes-------------------------------------\\


    ui->IDEdit->setEnabled(false);
    ui->retourBouton->hide();
    ui->Lieulabel->hide();
    ui->LieulineEdit->hide();
    ui->ValiderpushButton->setStyleSheet("background-color: green");
    ui->traiteurWid->hide();
    ui->traiteurTitre->hide();
    QObject::connect(ui->traiteurCheck,SIGNAL(toggled(bool)), this, SLOT(isTraiteur()));
    QObject::connect(ui->CombinecheckBox, SIGNAL(toggled(bool)),this, SLOT(isCombine()));
    QObject::connect(ui->retourBouton, SIGNAL(clicked(bool)),this, SLOT(callMainMenu()));
    QObject::connect(ui->ConnectpushButton,SIGNAL(clicked(bool)),this,SLOT(callMainMenu()));
    QObject::connect(ui->ajouterPatpushButton,SIGNAL(clicked(bool)),this, SLOT(callAjouterPat()));
    QObject::connect(ui->ajouterCoachpushButton,SIGNAL(clicked(bool)),this, SLOT(callAjouterCoach()));
    QObject::connect(ui->accesRapidepushButton,SIGNAL(clicked(bool)),this, SLOT(callAccesRapide()));
    QObject::connect(ui->recherchepushButton,SIGNAL(clicked(bool)),this, SLOT(callRecherche()));
    QObject::connect(ui->listeCoachpushButton,SIGNAL(clicked(bool)),this, SLOT(callListeCoach()));
    QObject::connect(ui->listeRepasGroupeJourpushButton,SIGNAL(clicked(bool)),this, SLOT(callListeRepasJour()));
    QObject::connect(ui->listeRepaspushButton,SIGNAL(clicked(bool)),this, SLOT(callListeRepas()));
    QObject::connect(ui->gererListeGroupepushButton,SIGNAL(clicked(bool)), this,SLOT(callGestionGroupe()));
    QObject::connect(ui->creationRecuspushButton,SIGNAL(clicked(bool)),this, SLOT (callRecus()));
}

void MainWindow::isTraiteur()
{
    if (ui->traiteurCheck->isChecked())
    {
        ui->traiteurWid->show();
        ui->traiteurTitre->show();
    }
    else
    {
        ui->traiteurWid->hide();
        ui->traiteurTitre->hide();
    }
}

void MainWindow::isCombine()
{
    if (ui->CombinecheckBox->isChecked())
    {
        ui->Lieulabel->show();
        ui->LieulineEdit->show();
    }
    else
    {
        ui->Lieulabel->hide();
        ui->LieulineEdit->hide();
    }
}

//--------------------------CHANGEMENT DE PAGE------------------------//
void MainWindow::callMainMenu()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->retourBouton->hide();
}
void MainWindow::callAjouterPat()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->retourBouton->show();
}
void MainWindow::callAjouterCoach()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->retourBouton->show();
}
void MainWindow::callAccesRapide()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->retourBouton->show();
}
void MainWindow::callRecherche()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->retourBouton->show();
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    query.exec("SELECT * FROM patineur");
    model->setQuery(query);
    ui->recherchetableView->setModel(model);
}
void MainWindow::callListeCoach()
{
    ui->stackedWidget->setCurrentIndex(7);
    ui->retourBouton->show();
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    query.exec("SELECT * FROM coach");
    model->setQuery(query);
    ui->coachtableView->setModel(model);
}
void MainWindow::callListeRepas()
{
    //Changer requête
    ui->stackedWidget->setCurrentIndex(8);
    ui->retourBouton->show();
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    query.exec("");
    model->setQuery(query);
    ui->listeRepastableView->setModel(model);
}
void MainWindow::callListeRepasJour()
{
    //Changer requête
    ui->stackedWidget->setCurrentIndex(9);
    ui->retourBouton->show();
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    query.exec("SELECT patineur.PAT_nom, patineur.PAT_prenom, hockey.HOC_traitLundi,hockey.HOC_traitMardi, hockey.HOC_traitMercredi, hockey.HOC_traitJeudi FROM hockey, patineur WHERE hockey.HOC_traiteur = 1 AND hockey.HOC_PAT_num = patineur.PAT_num");
    model->setQuery(query);
    ui->listeRepasGroupeJourtableView->setModel(model);
}
void MainWindow::callGestionGroupe()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->retourBouton->show();
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    query.exec("SELECT * from groupe");
    model->setQuery(query);
    ui->rechercheGroupetableView->setModel(model);
}
void MainWindow::callRecus()
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->retourBouton->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
