#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)  , ui(new Ui::MainWindow){
    ui->setupUi(this);

    connect(ui->numButton_0, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->numButton_1, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->numButton_2, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->numButton_3, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->numButton_4, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->numButton_5, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->numButton_6, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->numButton_7, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->numButton_8, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->numButton_9, SIGNAL(clicked()), this, SLOT(digits()));

    connect(ui->changeButton, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->sqrtButton, SIGNAL(clicked()), this, SLOT(operations()));

    connect(ui->plusButton, SIGNAL(clicked()), this, SLOT(math_operations()));
    ui->plusButton->setCheckable(true);
    connect(ui->minusButton, SIGNAL(clicked()), this, SLOT(math_operations()));
    ui->minusButton->setCheckable(true);
    connect(ui->multipleButton, SIGNAL(clicked()), this, SLOT(math_operations()));
    ui->multipleButton->setCheckable(true);
    connect(ui->divideButton, SIGNAL(clicked()), this, SLOT(math_operations()));
    ui->divideButton->setCheckable(true);

}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::digits(){
  QPushButton *pbutton = (QPushButton *)sender();
  QString strNum;
  if(ui->lbl->text().contains('.') && pbutton->text()=="0"){
      ui->lbl->text()+pbutton->text();
    }
  else{
      strNum = ui->lbl->text()+pbutton->text();
  }
  ui->lbl->setText(QString::number((strNum).toDouble()));//
}
void MainWindow::operations(){
  QString str = ((QPushButton *)sender())->text();
  double numbers=(ui->lbl->text()).toDouble();

  if(str == "+/-"){
     numbers=numbers * (-1);
     ui->lbl->setText(QString::number(numbers));
  }
  else if(str == "√" && numbers > 0) {
      numbers=sqrt(numbers);
      ui->lbl->setText(QString::number(numbers));
      ui->lbl_2->clear();
  }
  else{
      ui->lbl_2->setText("Error");
      ui->lbl->setText("click CE");
    }

}

void MainWindow::math_operations(){

  //if(!(ui->divideButton->isChecked() || ui->multipleButton->isChecked()||ui->minusButton->isChecked()||ui->plusButton->isChecked())){
      QPushButton *pbutton = (QPushButton *)sender();
      ui->lbl_2->setText((ui->lbl->text())+pbutton->text());
      ui->lbl->setText("0");
      pbutton->setChecked(true);
    //}
}

void MainWindow::on_clearButton_clicked()
{
  ui->lbl->clear();
  ui->lbl->setText("0");
  ui->lbl_2->clear();
  ui->divideButton->setChecked(false);
  ui->multipleButton->setChecked(false);
  ui->minusButton->setChecked(false);
  ui->plusButton->setChecked(false);
}


void MainWindow::on_pointButton_clicked()
{
  if(!(ui->lbl->text().contains('.'))){
        ui->lbl->setText(ui->lbl->text()+".");
  }
}


void MainWindow::on_resultButton_clicked()
{
      double result, fnum, snum;
      fnum = ui->lbl_2->text().remove((ui->lbl_2->text().length())-1, 1).toDouble();
      snum = ui->lbl->text().toDouble();

    if(ui->plusButton->isChecked()){
        ui->lbl_2->setText(ui->lbl_2->text()+ui->lbl->text());
        result = fnum+snum;
        ui->lbl->setText(QString::number(result));
        ui->plusButton->setChecked(false);
      }
    else if(ui->minusButton->isChecked()){
        ui->lbl_2->setText(ui->lbl_2->text()+ui->lbl->text());
        result = fnum-snum;
        ui->lbl->setText(QString::number(result));
        ui->minusButton->setChecked(false);
      }
    else if(ui->divideButton->isChecked() && snum != 0){
        ui->lbl_2->setText(ui->lbl_2->text()+ui->lbl->text());
        result = fnum/snum;
        ui->lbl->setText(QString::number(result));
        ui->divideButton->setChecked(false);
      }
    else if(ui->multipleButton->isChecked()){
        ui->lbl_2->setText(ui->lbl_2->text()+ui->lbl->text());
        result = fnum*snum;
        ui->lbl->setText(QString::number(result));
        ui->multipleButton->setChecked(false);
      }
    else{
        ui->lbl_2->setText("Error");
        ui->lbl->setText("click CE");
      }
}

