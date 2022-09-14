#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class CLIENT
{
    QString NOM,EMAIL,ADRESSE;
    int ID,NUM;

public:
    CLIENT(){};
    CLIENT(QString, QString, QString,int,int);


    QString getnom(){return NOM;}
    QString getmail(){return EMAIL;}
    QString getad(){return ADRESSE;}
    int getid(){return ID;}
    int getnum(){return NUM;}

    void setnom(QString n){NOM=n;}
    void setmail(QString em){EMAIL=em;}
    void setad(QString ad){ADRESSE=ad;}
    void setid(int id){this->ID=id;}
    void setnum(int nu){this->NUM=nu;}
    bool ajouter();
    QSqlQueryModel*afficher();
    bool supprimer(int );
    bool modifier(int);
    QSqlQueryModel * statistic();
    QSqlQueryModel *tri(QString,QString);
};
#endif // CLIENT_H
