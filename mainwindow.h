#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"client.h"
#include"statj.h"
#include"parking.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_stats_clicked();

    void on_modifier_clicked();

    void on_tri_clicked();

    void on_supprimer_2_clicked();

    void on_ajouter_2_clicked();

    void on_modifier_2_clicked();

    void on_tri_2_clicked();

    void on_stats_2_clicked();

    void on_lead_2_textChanged(const QString &arg1);

    void on_button_tri_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_stats_3_clicked();

    void on_ajouter_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    CLIENT Etmp;
    statj *stat_j;
    parking etmp2;





};
#endif // MAINWINDOW_H
