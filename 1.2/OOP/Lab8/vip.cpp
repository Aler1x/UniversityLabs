#include "vip.h"
#include "ui_vip.h"

VIPBankAccount vip1(20000);

VIP::VIP(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::VIP)
{
  ui->setupUi(this);
  ui->statusbar->showMessage(vip1.print());
}

VIP::~VIP()
{
  delete ui;
}

void VIP::on_pushButton_deposit_clicked()
{
  vip1.defoultDeposit();
  ui->label_money->setText(QString::number(vip1.m_money));
  vip1.displayTransactionHistory(ui->tableWidget, vip1.m_money*0.07);
}


void VIP::on_pushButton_comunalka_clicked()
{
  double input = ui->lineEdit_comunalka->text().toDouble();
  vip1.payForUtilities(input);
  ui->label_money->setText(QString::number(vip1.m_money));
  vip1.displayTransactionHistory(ui->tableWidget, (-input));
}


void VIP::on_pushButton_bankomat_clicked()
{
  double input = ui->lineEdit_bankomat->text().toDouble();
  vip1.withdrawMoney(input);
  ui->label_money->setText(QString::number(vip1.m_money));
  vip1.displayTransactionHistory(ui->tableWidget, (-input));
}


void VIP::on_pushButton_perekaz_clicked()
{
  double input = ui->lineEdit_perekaz->text().toDouble();
  vip1.transferMoney(input);
  ui->label_money->setText(QString::number(vip1.m_money));
  vip1.displayTransactionHistory(ui->tableWidget, (-input));
}


void VIP::on_pushButton_na_rahunok_clicked()
{
  double input = ui->lineEdit_na_rahunok->text().toDouble();
  vip1.enterOnAccount(input);
  ui->label_money->setText(QString::number(vip1.m_money));
  vip1.displayTransactionHistory(ui->tableWidget, (input));
}


void VIP::on_pushButton_credit_clicked()
{
  double input = ui->lineEdit_credit->text().toDouble();
  vip1.takeCredit(input);
  ui->label_money->setText(QString::number(vip1.m_money));
  ui->label_money_2->setText(QString::number(vip1.getCreditMoney()));
  vip1.displayTransactionHistory(ui->tableWidget, (input));
}


void VIP::on_pushButton_credit_3_clicked()
{
  vip1.displayTransactionHistory(ui->tableWidget, (-vip1.getCreditMoney()));
  vip1.returnCredit();
  ui->label_money->setText(QString::number(vip1.m_money));
  ui->label_money_2->setText(QString::number(vip1.getCreditMoney()));
}


void VIP::on_pushButton_credit_4_clicked()
{
  vip1.creditPercents();
  ui->label_money->setText(QString::number(vip1.m_money));
  ui->label_money_2->setText(QString::number(vip1.getCreditMoney()));
  vip1.displayTransactionHistory(ui->tableWidget, (-vip1.getCreditMoney()*0.1));
}

