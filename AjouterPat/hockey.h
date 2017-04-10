#ifndef HOCKEY_H
#define HOCKEY_H
#include<QString>

class Hockey
{
public:
    Hockey();
public slots:
public :
    void setIDpat(int patID);
    void setEquipe(QString equipe);
    void setCategorie(QString cat);
    void setPosition(QString position);
    void setLateralite(QString lat);
    void setHockGroupe(QString groupe);
    void setTraiteur(bool traiteur);
    void setCombine(bool combine);
    void setLieuCombine(QString lieuCombine);

    void hocToBD();

private:
    int mIDpat; //Le numéro du patineur
    int mHockNum = NULL; //NUM AUTO
    QString mEquipe;
    QString mCategorie;
    QString mPosition;
    QString mLateralite;
    QString mHockGroupe;
    bool mTraiteur;
    bool mCombine;
    QString mLieuComb;
};

#endif // HOCKEY_H
