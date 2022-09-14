#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include"QMainWindow"
#include<QPrinter>
#include<QPrintDialog>
#include <QFileDialog>
#include <QtDebug>
#include <QFile>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox_2->setModel(etmp2.afficheroncombo());
    ui->listclient->setModel(Etmp.afficher());
    ui->listparking->setModel(etmp2.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;



}


void MainWindow::on_ajouter_clicked()
{  ui->comboBox_2->setModel(etmp2.afficheroncombo());
    int idd=ui->leid->text().toInt();
    QString n=ui->lenom->text();
     int nu=ui->lenum->text().toInt();
    QString em=ui->lemail->text();
    QString ad=ui->lead->text();




    CLIENT c( n,  em, ad, idd, nu);
    bool test=c.ajouter();
        if(test)
        {
            ui->listclient->setModel(Etmp.afficher());

            QMessageBox::information(nullptr,QObject::tr("ok"),
                    QObject::tr("ajout effectué\n""click concel to exit."),QMessageBox::Cancel);
        }
            else
                QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                      QObject::tr("ajout non effectué.\n""click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_supprimer_clicked()
{
    int ID=ui->leid2->text().toInt();
    bool test=Etmp.supprimer(ID);
    if(test)
    {
        ui->listclient->setModel(Etmp.afficher());


        QMessageBox::information(nullptr,QObject::tr("database is open "),QObject::tr("delete successful.\n"
                                                                                      "click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("data is not open"),QObject::tr("delete failed.\n"
                                                                                  "click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_stats_clicked()
{
    stat_j=new statj(this);
    stat_j->show();
}

void MainWindow::on_modifier_clicked()
{
    int idd=ui->leid->text().toInt();
    QString n=ui->lenom->text();
     int nu=ui->lenum->text().toInt();
    QString em=ui->lemail->text();
    QString ad=ui->lead->text();




    CLIENT a( n,  em, ad, idd, nu);
    bool test=a.modifier(idd);
        if(test)
        {
            ui->listclient->setModel(Etmp.afficher());

            QMessageBox::information(nullptr,QObject::tr("ok"),
                    QObject::tr("ajout effectué\n""click concel to exit."),QMessageBox::Cancel);
        }
            else
                QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                      QObject::tr("ajout non effectué.\n""click cancel to exit."),QMessageBox::Cancel);
}



void MainWindow::on_supprimer_2_clicked()
{


    bool test=etmp2.supprimer(ui->leid2_2->text().toInt());
    if(test)
    {
        ui->listparking->setModel(etmp2.afficher());


        QMessageBox::information(nullptr,QObject::tr("database is open "),QObject::tr("delete successful.\n"
                                                                                      "click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("data is not open"),QObject::tr("delete failed.\n"
                                                                                  "click cancel to exit."),QMessageBox::Cancel);

}
void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
     ui->comboBox_2->currentText();
}

void MainWindow::on_ajouter_2_clicked()
{

    parking p(ui->leid_2->text().toInt(),ui->comboBox_2->currentText().toInt(),ui->ab->currentText(),ui->re->currentText(),ui->pr->currentText());
       bool test= p.ajouter();
          ui->listparking->setModel(etmp2.afficher());
       ui->comboBox_2->setModel(p.afficheroncombo());
       }

void MainWindow::on_modifier_2_clicked()
{
int idp=ui->leid_2->text().toInt();
int idc=ui->comboBox_2->currentText().toInt();
QString ab=ui->ab->currentText();
QString re=ui->re->currentText();
QString pr=ui->pr->currentText();

bool test=etmp2.modifier(idp,  idc, ab, re, pr);
    if(test)
    {
        ui->listparking->setModel(etmp2.afficher());

        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("ajout effectué\n""click concel to exit."),QMessageBox::Cancel);
    }
        else
            QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                  QObject::tr("ajout non effectué.\n""click cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_tri_2_clicked()
{

}

void MainWindow::on_stats_2_clicked()
{
    stat_j=new statj(this);
    stat_j->show();
}

void MainWindow::on_lead_2_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
    if(ui->comboBox->currentText()=="ID"
            ){
        query->prepare("SELECT * FROM CLIENT WHERE ID LIKE'"+arg1+"%'");//
query->exec();
    model->setQuery(*query);
ui->listclient->setModel(model);


    }
    else {
        if(ui->comboBox->currentText()=="NOM"){
            query->prepare("SELECT * FROM CLIENT WHERE NOM LIKE'"+arg1+"%'");//+tri
    query->exec();
        model->setQuery(*query);
    ui->listclient->setModel(model);
        }
        else{
            if(ui->comboBox->currentText()=="NUM")
                query->prepare("SELECT * FROM CLIENT WHERE NUM LIKE'"+arg1+"%'");//+tri
        query->exec();
            model->setQuery(*query);
        ui->listclient->setModel(model);
            }

        }
}

void MainWindow::on_button_tri_clicked()
{
    QString colone=ui->colone_tri->currentText();
        QString ordre=ui->ordre_tri->currentText();
        CLIENT c;
        ui->listclient->setModel(c.tri(colone,ordre));
}



void MainWindow::on_stats_3_clicked()
{
    ui->comboBox_2->setModel(etmp2.afficheroncombo());
    ui->listclient->setModel(Etmp.afficher());

}

void MainWindow::on_ajouter_3_clicked()
{
    ui->listparking->setModel(etmp2.afficher());
}

void MainWindow::on_pushButton_clicked()
{
    etmp2.genererPDFr();
}

void MainWindow::on_pushButton_2_clicked()
{
    QPrinter  printer;
        printer.setPrinterName("test");
        QPrintDialog dialog(&printer,this);
        if (dialog.exec()==QDialog::Rejected) return;
}

void MainWindow::on_pushButton_3_clicked()
{
    QTableView *table;
               table = ui->listparking;

               QString filters("CSV files (.csv);;All files (.*)");
               QString defaultFilter("CSV files (*.csv)");
               QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                  filters, &defaultFilter);
               QFile file(fileName);

               QAbstractItemModel *model =  table->model();
               if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                   QTextStream data(&file);
                   QStringList strList;
                   for (int i = 0; i < model->columnCount(); i++) {
                       if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                           strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                       else
                           strList.append("");
                   }
                   data << strList.join(";") << "\n";
                   for (int i = 0; i < model->rowCount(); i++) {
                       strList.clear();
                       for (int j = 0; j < model->columnCount(); j++) {

                           if (model->data(model->index(i, j)).toString().length() > 0)
                               strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                           else
                               strList.append("");
                       }
                       data << strList.join(";") + "\n";
                   }
                   file.close();
                   QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
               }
}
