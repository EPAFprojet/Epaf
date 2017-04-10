#ifndef PATINEUR_H
#define PATINEUR_H
#include<QString>
#include "Date.h"
class Patineur
{
public:
    Patineur();
public slots:
    void setPatNom();
private:
    int mPatNum;
    QString mPatNom;
    QString mPatPrenom;
    Date mDateNaissance;
    QString mCourriel;
    QString mAdresse;
    QString mVille;
    QString mProvince;
    QString mCodePostal;
    QString mParentResponsable;
    QString mNumTel; //(autre format?!)
    QString mCondiMed;
};

#endif // PATINEUR_H
