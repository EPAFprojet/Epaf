#ifndef POWERSKATING_H
#define POWERSKATING_H
#include<QString>

class PowerSkating
{
public:
    PowerSkating();  

public:
    void setPowGroupe(QString groupe);
    void setNiveau(QString niv);

    void powToBD();

private:
    int mPatID; //ID du patineur
    int mPowNum = NULL; //Numéro pow, AUTO, peut être envoyé en nul.
    QString mGroupe;
    QString mNiveau;

};

#endif // POWERSKATING_H
