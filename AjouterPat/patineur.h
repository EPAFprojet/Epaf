#ifndef PATINEUR_H
#define PATINEUR_H
#include<QString>
#include "Date.h"
class Patineur
{

public:
    Patineur();

public:

    void setPatNom(QString nom);
    void setPatPrenom(QString prenom);
    void setDateNaissance(Date naissance);
    void setCourriel(QString courriel);
    void setAdresse(QString adresse);
    void setVille(QString ville);
    void setProvince(QString province);
    void setCodePostal(QString codePostal);
    void setParentResponsable(QString parent);
    void setNumTel(QString numTel);
    void setCondiMed(QString condiMed);
    void setPaiementStatus(bool paiement);

    void patToBD();

private:
    int mPatNum = NULL; //Num auto
    QString mPatNom;
    QString mPatPrenom;
    Date mDateNaissance; //Passer le ui->label de la date dans la classe pour vérifications.
    QString mCourriel;
    QString mAdresse;
    QString mVille;
    QString mProvince;
    QString mCodePostal;
    QString mParentResponsable;
    QString mNumTel;
    QString mCondiMed;
    bool payer;
};

#endif // PATINEUR_H
