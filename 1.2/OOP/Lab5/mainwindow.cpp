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
  ui->label_result->setText(QString::number(Z2.module()));
}

void MainWindow::onPushButtonZ1PowNClicked()
{
    int n = (ui->lineEdit_n->text()).toInt();
    scanZ1(&Z1);
    Z3 = Z1.pow(n);
    Z3.printToForm(ui->label_result);
}

void MainWindow::onPushButtonZ2PowNClicked()
{
  int n = (ui->lineEdit_n->text()).toInt();
  scanZ2(&Z2);
  Z3 = Z2.pow(n);
  Z3.printToForm(ui->label_result);
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

