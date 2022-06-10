#ifndef STANDART_H
#define STANDART_H

#include <QMainWindow>

#include "bankaccount.h"

namespace Ui {
  class Standart;
}

class Standart : public QMainWindow
{
  Q_OBJECT

public:
  explicit Standart(QWidget *parent = nullptr);
  ~Standart();

private slots:
  void on_pushButton_comunalka_clicked();

  void on_pushButton_bankomat_clicked();

  void on_pushButton_perekaz_clicked();

  void on_pushButton_na_rahunok_clicked();

private:
  Ui::Standart *ui;
};

#endif // STANDART_H
