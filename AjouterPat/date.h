#ifndef DATE_H
#define DATE_H
#include<QString>


const int MAX_ANNEE = 3000;
const int MIN_ANNEE = 1600;

const QString nomMois[12] = {
    "Janvier",
    "Fevrier",
    "Mars",
    "Avril",
    "Mai",
    "Juin",
    "Juillet",
    "Aout",
    "Septembre",
    "Octobre",
    "Novembre",
    "Decembre" };

class Date
{
private:

    int mJ; //jour
    int mM; //mois
    int mA; //année
    int JourParMois[12] = {31,28,31,30,31,30,31,30,31,30,31,30};

public:

    Date();
    Date(int j);
    Date(int j, int m);
    Date(int j,int m,int a);

    bool setJour(int j);
    bool setMois(int m);
    bool setAnnee(int a);

    int getJour();
    int getMois();
    int getAnnee();

    void ajouterJour(unsigned int nbJour);

    static int getCurrentDay();
    static int getCurrentMonth();
    static int getCurrentYear();

};

#endif // DATE_H
