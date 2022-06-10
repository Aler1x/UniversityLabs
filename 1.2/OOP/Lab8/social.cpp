#include "social.h"
#include "ui_social.h"

SocialBankAccount ac1(15000);

Social::Social(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Social)
{
  ui->setupUi(this);
  ui->statusbar->showMessage(ac1.print());
}

Social::~Social()
{
  delete ui;
}

void Social::on_pushButton_deposit_clicked()
{
  ac1.defoultDeposit();
  ui->label_money->setText(QString::number(ac1.m_money));
  ac1.displayTransactionHistory(ui->tableWidget, (ac1.m_money)*0.05);
}


void Social::on_pushButton_comunalka_clicked()
{
  double input = ui->lineEdit_comunalka->text().toDouble();
  ac1.payForUtilities(input);
  ui->label_money->setText(QString::number(ac1.m_money));
  ac1.displayTransactionHistory(ui->tableWidget, (-input));
}


void Social::on_pushButton_bankomat_clicked()
{
    double input = ui->lineEdit_bankomat->text().toDouble();
    ac1.withdrawMoney(input);
    ui->label_money->setText(QString::number(ac1.m_money));
    ac1.displayTransactionHistory(ui->tableWidget, (-input));
}


void Social::on_pushButton_perekaz_clicked()
{
  double input = ui->lineEdit_perekaz->text().toDouble();
  ac1.transferMoney(input);
  ui->label_money->setText(QString::number(ac1.m_money));
  ac1.displayTransactionHistory(ui->tableWidget, (-input));
}


void Social::on_pushButton_na_rahunok_clicked()
{
  double input = ui->lineEdit_na_rachunok->text().toDouble();
  ac1.enterOnAccount(input);
  ui->label_money->setText(QString::number(ac1.m_money));
  ac1.displayTransactionHistory(ui->tableWidget, (input));
}

