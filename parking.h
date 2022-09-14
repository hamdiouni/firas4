#ifndef PARKING_H
#define PARKING_H


#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class parking
{
    QString abonnement,reservation,prix;
    int idp,idc;

public:
    parking(){};
    parking(int,int,QString, QString, QString);


    QString getab(){return abonnement;}
    QString getr(){return reservation;}

    void setnab(QString a){abonnement=a;}
    void setr(QString r){reservation=r;}
    void setprixx(int p){this->prix=p;}
    bool ajouter();
    QSqlQueryModel*afficher();
    QSqlQueryModel * afficheroncombo();
    bool supprimer(int );
    bool modifier(int,int,QString, QString, QString);
    QSqlQueryModel * statistic();
    QSqlQueryModel *tri();
     void genererPDFr();
};
#endif // PARKING_H
