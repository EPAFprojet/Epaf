#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void isTraiteur();
    void isCombine();

    void callMainMenu();
    void callAjouterPat();
    void callAjouterCoach();
    void callAccesRapide();
    void callRecherche();
    void callListeCoach();
    void callListeRepas();
    void callListeRepasJour();
    void callGestionGroupe();
    void callRecus();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
