#ifndef STATJ2_H
#define STATJ2_H

#include <QDialog>

namespace Ui {
class statj;
}

class statj : public QDialog
{
    Q_OBJECT

public:
    explicit statj(QWidget *parent = nullptr);
    ~statj();
    QList<qreal> stat_j2();
      QList <QString> stat_j_nom2();
private:
    Ui::statj *ui;
};

#endif // STATJ_H
