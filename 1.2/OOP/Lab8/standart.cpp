#include "standart.h"
#include "ui_standart.h"

StandartBankAccount std1(15000);

Standart::Standart(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Standart)
{
  ui->setupUi(this);
  ui->statusbar->showMessage(std1.print());
}

Standart::~Standart()
{
  delete ui;
}

void Standart::on_pushButton_comunalka_clicked()
{
  double input = ui->lineEdit_comunalka->text().toDouble();
  std1.payForUtilities(input);
  ui->label_money->setText(QString::number(std1.getMoney()));
  std1.displayTransactionHistory(ui->tableWidget, (-input-(input*0.03)));
}


void Standart::on_pushButton_bankomat_clicked()
{
  double input = ui->lineEdit_bankomat->text().toDouble();
  std1.withdrawMoney(input);
  ui->label_money->setText(QString::number(std1.getMoney()));
  std1.displayTransactionHistory(ui->tableWidget, (-input-(input*0.03)));
}


void Standart::on_pushButton_perekaz_clicked()
{
  double input = ui->lineEdit_perekaz->text().toDouble();
  std1.transferMoney(input);
  ui->label_money->setText(QString::number(std1.getMoney()));
  std1.displayTransactionHistory(ui->tableWidget, (-input-(input*0.03)));
}


void Standart::on_pushButton_na_rahunok_clicked()
{
  double input = ui->lineEdit_na_rahunok->text().toDouble();
  std1.enterOnAccount(input);
  ui->label_money->setText(QString::number(std1.getMoney()));
  std1.displayTransactionHistory(ui->tableWidget, (input-(input*0.03)));
}

