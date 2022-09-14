#include "statj2.h"
#include "ui_statj2.h"
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QSqlQuery>

statj::statj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statj)
{
    ui->setupUi(this);
    QPieSeries *series =new QPieSeries ;

    QList<qreal> list= stat_j2();
     QList<QString> list2=stat_j_nom2();

     for(int i=0 ;i<list.size();i++)
     {
          series->append(list2[i],list[i]);

     }
        QChart *chart =new QChart;
        chart->addSeries(series);
        chart->setTitle("stats des parking");
         QChartView *chartview= new QChartView(chart);
         chartview->setParent(ui->horizontalFrame1);

 }



statj::~statj()
{
    delete ui;
}
QList<qreal> statj::stat_j2()
{



    QList<qreal> list ;
    QSqlQuery query;
    query.prepare("select abonnement,count(abonnement) from parking group by abonnement");
    query.exec();
    while(query.next())
    {list.append(query.value(1).toInt());}

    return list;
}

QList<QString> statj::stat_j_nom2()
{QList<QString> list ;

  QSqlQuery query;
  query.prepare("select abonnement,count(abonnement) from parking group by abonnement");
  query.exec();
  while(query.next())
  {list.append(query.value(0).toString());}

return list;

}






