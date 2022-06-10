#ifndef SOCIAL_H
#define SOCIAL_H

#include <QMainWindow>

#include "bankaccount.h"

namespace Ui {
  class Social;
}

class Social : public QMainWindow
{
  Q_OBJECT

public:
  explicit Social(QWidget *parent = nullptr);
  ~Social();

private slots:
  void on_pushButton_deposit_clicked();

  void on_pushButton_comunalka_clicked();

  void on_pushButton_bankomat_clicked();

  void on_pushButton_perekaz_clicked();

  void on_pushButton_na_rahunok_clicked();

private:
  Ui::Social *ui;
};

#endif // SOCIAL_H
