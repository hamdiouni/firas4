#include "client.h"

CLIENT::CLIENT(QString n, QString em,QString ad,int id,int nu)
{

    this->NOM=n;
    this->EMAIL=em;
    this->ADRESSE=ad;
    this->ID=id;
    this->NUM=nu;


   ;

}
bool CLIENT::ajouter()
{
QSqlQuery query;
QString res= QString::number(ID);
query.prepare("INSERT INTO client(id,nom,num,email,adresse)""VALUES(:idd,:n,:nu,:em,:ad)");
query.bindValue(0,res);
query.bindValue(1,NOM);
query.bindValue(2,NUM);
query.bindValue(3,EMAIL);
query.bindValue(4,ADRESSE);





return query.exec();
}
QSqlQueryModel*CLIENT::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from client");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("num"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));


return model;
}
bool CLIENT::supprimer(int ID)
{
QSqlQuery query;
QString res=QString::number(ID);
query.prepare("delete from client where ID= :id");
query.bindValue(":id",res);
return query.exec();
}
bool CLIENT::modifier(int ID)
{
     QSqlQuery query;
     QString r1= QString::number(ID);

    query.prepare("UPDATE client SET id=:idd ,nom=:n,num=:nu,email=:em,adresse=:ad WHERE id=:idd");
    query.bindValue(":idd",r1);
    query.bindValue(1,NOM);
    query.bindValue(2,NUM);
    query.bindValue(3,EMAIL);
    query.bindValue(4,ADRESSE);



    return query.exec();

}
QSqlQueryModel * CLIENT::statistic()
{
    QSqlQueryModel * model=new QSqlQueryModel();
       model->setQuery("select NATIONALITÉ,(count(nom)*100/ (select count(*)from client)) as pourcentage from client group by nom");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("percentage"));

       return model;


}
QSqlQueryModel* CLIENT::tri(QString colone,QString ordre)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from client order by "+colone+" "+ordre+"");
    return model;
}

