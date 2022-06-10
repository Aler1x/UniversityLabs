#ifndef VIP_H
#define VIP_H

#include <QMainWindow>

#include "bankaccount.h"

namespace Ui {
  class VIP;
}

class VIP : public QMainWindow
{
  Q_OBJECT

public:
  explicit VIP(QWidget *parent = nullptr);
  ~VIP();

private slots:
  void on_pushButton_deposit_clicked();

  void on_pushButton_comunalka_clicked();

  void on_pushButton_bankomat_clicked();

  void on_pushButton_perekaz_clicked();

  void on_pushButton_na_rahunok_clicked();

  void on_pushButton_credit_clicked();

  void on_pushButton_credit_3_clicked();

  void on_pushButton_credit_4_clicked();

private:
  Ui::VIP *ui;
};

#endif // VIP_H
