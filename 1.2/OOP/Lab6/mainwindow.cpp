#include "mainwindow.h"

Complex Z1, Z2, Z3;

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(buttonClicked()));

  connect(ui->pushButton_Z1_pow_n, SIGNAL(clicked()), this, SLOT(onPushButtonZ1PowNClicked()));
  connect(ui->pushButton_Z2_pow_n, SIGNAL(clicked()), this, SLOT(onPushButtonZ2PowNClicked()));

  connect(ui->pushButton_l, SIGNAL(clicked()), this, SLOT(boolButtonClicked()));
  connect(ui->pushButton_m, SIGNAL(clicked()), this, SLOT(boolButtonClicked()));
  connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(boolButtonClicked()));

  connect(ui->pushButton_amount, SIGNAL(clicked()), this, SLOT(onAmountClicked()));

  connect(ui->pushButton_plus_2, SIGNAL(clicked()), this, SLOT(operatorButtonClicked()));
  connect(ui->pushButton_minus_2, SIGNAL(clicked()), this, SLOT(operatorButtonClicked()));
  connect(ui->pushButton_mult_2, SIGNAL(clicked()), this, SLOT(operatorButtonClicked()));
}


MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::scan(Complex *Z1, Complex *Z2)
{

  Z1->readFromForm(ui->lineEdit_Z1_r, ui->lineEdit_Z1_i);
  Z2->readFromForm(ui->lineEdit_Z2_r, ui->lineEdit_Z2_i);
}

void MainWindow::scanZ1(Complex *Z1)
{
  Z1->readFromForm(ui->lineEdit_Z1_r, ui->lineEdit_Z1_i);
}

void MainWindow::scanZ2(Complex *Z2)
{
  Z2->readFromForm(ui->lineEdit_Z2_r, ui->lineEdit_Z2_i);
}

void MainWindow::buttonClicked(){
  scan(&Z1, &Z2);

  QString str = ((QPushButton *)sender())->text();

  if(str == '+'){
      Z3 = Z1.sum(Z2);
  } else if(str == '-'){
      Z3 = Z1.minus(Z2);
    } else if(str == '*'){
      Z3 = Z1.mult(Z2);
    }
  Z3.printToForm(ui->label_result);
}

void MainWindow::on_pushButton_mod_Z1_clicked()
{
  scanZ1(&Z1);
  ui->label_result->setText(QString::number(Z1.module()));
}


void MainWindow::on_pushButton_mod_Z2_clicked()
{
  scanZ2(&Z2);
  ui->label_result->setText(QString::number(!Z2));
}

void MainWindow::onPushButtonZ1PowNClicked()
{
  int n = (ui->lineEdit_n->text()).toInt();
  scanZ1(&Z1);
  Z1.powComplex(n, ui->label_result);
}

void MainWindow::onPushButtonZ2PowNClicked()
{
  int n = (ui->lineEdit_n->text()).toInt();
  scanZ2(&Z2);
  Z2.powComplex(n, ui->label_result);
}

void MainWindow::on_pushButton_Z1_trm_Form_clicked()
{
  scanZ1(&Z1);
  Z1.trigonometry(ui->label_result);
}


void MainWindow::on_pushButton_Z2_trmForm_clicked()
{
    scanZ2(&Z2);
    Z2.trigonometry(ui->label_result);
}

void MainWindow::onAmountClicked()
{
  QString str = QString::number(Complex::getAmount());
  ui->label_result->setText(str);
}

void MainWindow::boolButtonClicked()
{
  QString str = ((QPushButton*)sender())->text();
  scan(&Z1, &Z2);

  if(str == "<"){
      (Z1 < Z2) ? str = "true" : str = "false";
      ui->label_result->setText(str);
    } else if(str == ">"){
      (Z1 > Z2) ? str = "true" : str = "false";
      ui->label_result->setText(str);
    } else {
      (Z1 == Z2) ? str = "true" : str = "false";
      ui->label_result->setText(str);
    }
}

void MainWindow::operatorButtonClicked()
{
  QString str = ((QPushButton*)sender())->text();
  scan(&Z1, &Z2);

  if(str == "(+)"){
      Z3 = Z1+Z2;
  } else if(str == "(-)"){
      Z3 = Z1-Z2;
    } else if(str == "(*)"){
      Z3 = Z1*Z2;
    }
  Z3.printToForm(ui->label_result);
}

