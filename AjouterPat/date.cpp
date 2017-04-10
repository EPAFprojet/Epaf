#include "date.h"
#include <ctime>
#include <iostream>
#include <QMessageBox>
//-----------------Constructeurs--------------------//
Date::Date()
{
    mA = getCurrentYear();
    mM = getCurrentMonth();
    mJ = getCurrentDay();
}

Date::Date(int j,int m,int a)
{
    mA = getCurrentYear();
    mM = getCurrentMonth();
    mJ = 1;

    setAnnee(a);
    setMois(m);
    setJour(j);
}

Date::Date(int j)
{
    mA = getCurrentYear();
    mM = getCurrentMonth();

    mJ = 1;
    setJour(j);
}

Date::Date(int j, int m)
{
    mA = getCurrentYear();
    mM = getCurrentMonth();
    mJ = 1;

    setMois(m);
    setJour(j);
}
//-----------------SET--------------------//
bool Date::setJour(int j)
{
    //~~~~~~~~~Gestion année bisextile~~~~~~~~~~~~//
    bool anneeBi = false;
    if ((mA % 4) == 0)
        anneeBi = true;
    //~~~~~~~Gestion nombre de jour par mois~~~~~~//
    int jourMax = 0;
    switch(mM)
    {
        case 1: jourMax = 31; break;
        case 2:
            {
                if (anneeBi) jourMax = 29;
                else jourMax = 28;
                break;
            }
        case 3:jourMax = 31; break;
        case 4:jourMax = 30; break;
        case 5:jourMax = 31; break;
        case 6:jourMax = 30; break;
        case 7:jourMax = 31; break;
        case 8:jourMax = 30; break;
        case 9:jourMax = 31; break;
        case 10:jourMax = 30; break;
        case 11:jourMax = 31; break;
        case 12:jourMax = 30; break;
    }
    if (j < 1 || j > jourMax)
    {

        return false;
    }
    else //JOUR VALIDE
    {
        mJ = j;
        return true;
    }

}

bool Date::setMois(int m)
{
    if (m < 1 || m > 12)
    {
        QMessageBox::critical(this, "Erreur:Mois invalide", "Le mois entré est invalide.")
        return false;
    }
    else //MOIS VALIDE
    {
        mM = m;
        return true;
    }
}

bool Date::setAnnee(int a)
{
    if (a < MIN_ANNEE || a > MAX_ANNEE)
    {
        QMessageBox::critical(this,"Erreur:Année invalide", "L'année entrée est invalide.")
        return false;
    }
    else //ANNÉE VALIDE
    {
        mA = a;
        return true;
    }
}
