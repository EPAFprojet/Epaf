#ifndef PATINAGEARTISTIQUE_H
#define PATINAGEARTISTIQUE_H
#include<QString>

class PatinageArtistique
{
public:
    PatinageArtistique();

public:
    void setPatID(int id);
    void setNoClub(int club);
    void setNivDanse(QString danse);
    void setNivStyle(QString style);
    void setPAGroupe(QString groupe);

    void PAtoBD();

private:
    int mIDPat; // ID du patineur
    int mNumPa = NULL; //Numéro auto de patineur artistique.
    int mNoClub;
    QString mNivDanse;
    QString mNivHab;
    QString mNivStyle;
    QString mPAGroupe;


};

#endif // PATINAGEARTISTIQUE_H
