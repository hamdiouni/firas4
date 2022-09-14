#include "parking.h"
#include<QPainter>
#include<QPdfWriter>
parking::parking(int idp,int idc,QString abonnement,QString reservation,QString prix)
{

    this->idp=idp;
    this->idc=idc;
    this->abonnement=abonnement;
    this->reservation=reservation;
    this->prix=prix;
}
bool parking::ajouter()
{

    QSqlQuery query;


  query.prepare("INSERT INTO parking (idp,idc,abonnement,reservation,prix) "
                "VALUES (:idp, :idc, :abonnement, :reservation, :prix)");
  query.bindValue(":idp", idp);
  query.bindValue(":idc", idc);
  query.bindValue(":abonnement",abonnement);
  query.bindValue(":reservation",reservation);
query.bindValue(":prix",prix);
     return query.exec();


}
QSqlQueryModel*parking::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from parking");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("idp"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("idc"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("abonnement"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("reclamation"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));


return model;
}
bool parking::supprimer(int idp)
{
    QSqlQuery query;

    query.prepare("delete from parking where idp= :idp");
    query.bindValue(":idp",idp);
    return query.exec();
}
bool parking::modifier(int idp,int idc,QString abonnement,QString reservation,QString prix)
{
    QSqlQuery query;


         query.prepare("update parking set idc=:idc, abonnement=:abonnement, reservation=:reservation , prix=:prix "
                       "where idp=:idp");

         query.bindValue(":idp", idp);
         query.bindValue(":idc", idc);
         query.bindValue(":abonnement",abonnement);
         query.bindValue(":reservation",reservation);
         query.bindValue(":prix",prix);
        return query.exec();

}
QSqlQueryModel * parking ::afficheroncombo()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CLIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));

        return model;
}
void  parking::genererPDFr(){
                     QPdfWriter pdf("C:\\Users\\21621\\OneDrive\\Bureau\\firas QT\\firas4\\pdf.pdf");
                     QPainter painter(&pdf);
                    int i = 4000;
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial", 50));
                         painter.drawText(1100,1200,"Liste Des parking");
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial", 15));
                         painter.drawRect(100,100,7300,2600);
                         painter.drawRect(0,3000,9600,500);
                         painter.setFont(QFont("Arial", 9));
                         painter.drawText(200,3300,"idp ");
                         painter.drawText(1300,3300,"idp");
                         painter.drawText(2400,3300,"abonnement");
                            painter.drawText(3500,3300,"reclamation");
                            painter.drawText(4600,3300,"prix");


                         QSqlQuery query;
                         query.prepare("select * from parking");
                         query.exec();
                         while (query.next())
                         {
                             painter.drawText(200,i,query.value(0).toString());
                             painter.drawText(1300,i,query.value(1).toString());
                             painter.drawText(2400,i,query.value(2).toString());
                             painter.drawText(3500,i,query.value(3).toString());
                             painter.drawText(4600,i,query.value(3).toString());



                            i = i + 500;
                         }}

QSqlQueryModel * parking::statistic()
{
    QSqlQueryModel * model=new QSqlQueryModel();
       model->setQuery("select NATIONALITÉ,(count(abonnement)*100/ (select count(*)from parking)) as pourcentage from parking group by abonnement");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("abonnement"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("percentage"));

       return model;


}
QSqlQueryModel* parking::tri()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT* FROM parking ORDER BY prix  ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("client"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("abonnement"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("reservation"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));






    return model;
}

