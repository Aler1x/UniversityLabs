#include "mainwindow.h"
#include "ui_mainwindow.h"

Array ar1(10), ar2(10), ar3(10);

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
  ar1.clearArray();
  ar2.clearArray();
  ar3.clearArray();
}

int MainWindow::setArray() {
  QMessageBox msgBox;
  msgBox.setText("Chose what array should use");
  msgBox.setWindowIcon(QIcon(":/icons/icons/info.png"));
  QAbstractButton* pButtonAr1 = msgBox.addButton(tr("Array 1"), QMessageBox::YesRole);
  QAbstractButton* pButtonAr2 = msgBox.addButton(tr("Array 2"), QMessageBox::AcceptRole);
  QAbstractButton* pButtonAr3 = msgBox.addButton(tr("Array 3"), QMessageBox::NoRole);
  msgBox.exec();

  if (msgBox.clickedButton() == pButtonAr1) {
        return 0;
  } else if (msgBox.clickedButton() == pButtonAr2) {
        return 1;
   } else if (msgBox.clickedButton() == pButtonAr3) {
        return 2;
   }
  return 0;
}

void MainWindow::on_pushButton_input_table_widget_clicked() {
  int check = setArray();
  switch(check){
    case(0):{
        ui->tableWidget >> ar1;
        ui->label_array << ar1;
        break;
      }
    case(1):{
        ui->tableWidget >> ar2;
        ui->label_array << ar2;
        break;
      }
    case(2):{
        ui->tableWidget >> ar3;
        ui->label_array << ar3;
        break;
      }
    }
}


void MainWindow::on_pushButton_output_table_widget_clicked() {
  int check = setArray();
  switch(check){
    case(0):{
        ui->tableWidget << ar1;
        break;
      }
    case(1):{
        ui->tableWidget << ar2;
        break;
      }
    case(2):{
        ui->tableWidget << ar3;
        break;
      }
    }
}


void MainWindow::on_pushButton_iput_list_widget_clicked() {
  int check = setArray();
  switch(check){
    case(0):{
        ui->listWidget >> ar1;
        ui->label_array << ar1;
        break;
      }
    case(1):{
        ui->listWidget >> ar2;
        ui->label_array << ar2;
        break;
      }
    case(2):{
        ui->listWidget >> ar3;
        ui->label_array << ar3;
        break;
      }
    }
}


void MainWindow::on_pushButton_output_list_widget_clicked() {
  int check = setArray();
  switch(check){
    case(0):{
        ui->listWidget << ar1;
        break;
      }
    case(1):{
        ui->listWidget << ar2;
        break;
      }
    case(2):{
        ui->listWidget << ar3;
        break;
      }
    }
}


void MainWindow::on_pushButton_min_clicked() {
  int check = setArray();
  switch(check){
    case(0):{
        ui->label_Result->setText(QString::number(ar1.getMinValue()));
        break;
      }
    case(1):{
        ui->label_Result->setText(QString::number(ar2.getMinValue()));
        break;
      }
    case(2):{
        ui->label_Result->setText(QString::number(ar3.getMinValue()));
        break;
      }
    }
}


void MainWindow::on_pushButton_max_clicked() {
  int check = setArray();
  switch(check){
    case(0):{
        ui->label_Result->setText(QString::number(ar1.getMaxValue()));
        break;
      }
    case(1):{
        ui->label_Result->setText(QString::number(ar2.getMaxValue()));
        break;
      }
    case(2):{
        ui->label_Result->setText(QString::number(ar3.getMaxValue()));
        break;
      }
    }
}


void MainWindow::on_pushButton_ave_clicked() {
  int check = setArray();
  switch(check){
    case(0):{
        ui->label_Result->setText(QString::number(ar1.averageValue()));
        break;
      }
    case(1):{
        ui->label_Result->setText(QString::number(ar2.averageValue()));
        break;
      }
    case(2):{
        ui->label_Result->setText(QString::number(ar3.averageValue()));
        break;
      }
    }
}


void MainWindow::on_pushButton_sort_to_higher_clicked() {
  int check = setArray();
  switch(check){
    case(0):{
        ar1.bubbleSortToLarger();
        ui->label_array << ar1;
        break;
      }
    case(1):{
        ar2.bubbleSortToLarger();
        ui->label_array << ar2;
        break;
      }
    case(2):{
        ar3.bubbleSortToLarger();
        ui->label_array << ar3;
        break;
      }
    }
}


void MainWindow::on_pushButton_sort_lower_clicked() {
  int check = setArray();
  switch(check){
    case(0):{
        ar1.selectionSortToLower();
        ui->label_array << ar1;
        break;
      }
    case(1):{
        ar2.selectionSortToLower();
        ui->label_array << ar2;
        break;
      }
    case(2):{
        ar3.selectionSortToLower();
        ui->label_array << ar3;
        break;
      }
    }
}


void MainWindow::on_pushButton_n_element_2_clicked(){
  int check = setArray();
  switch(check){
    case(0):{
        ar1.changeSize(ui->label_N->text().toInt());
        break;
      }
    case(1):{
        ar2.changeSize(ui->label_N->text().toInt());
        break;
      }
    case(2):{
        ar3.changeSize(ui->label_N->text().toInt());
        break;
      }
    }
}


void MainWindow::on_pushButton_mult_n_clicked() {
  int check = setArray();
  switch(check){
    case(0):{
        double num = ui->lineEdit->text().toDouble();
        ar1*num;
        ui->label_array << ar1;
        ui->label_Result->setText(QString::number(num));
        break;
      }
    case(1):{
        double num = ui->lineEdit->text().toDouble();
        ar2*num;
        ui->label_array << ar2;
        ui->label_Result->setText(QString::number(num));
        break;
      }
    case(2):{
        double num = ui->lineEdit->text().toDouble();
        ar3*num;
        ui->label_array << ar3;
        ui->label_Result->setText(QString::number(num));
        break;
      }
    }
}


void MainWindow::on_pushButton_n_element_clicked() {
  int check = setArray();
  switch(check){
    case(0):{
        ui->label_Result->setText(QString::number(ar1.array[ui->label_N->text().toInt()]));
        break;
      }
    case(1):{
        ui->label_Result->setText(QString::number(ar2.array[ui->label_N->text().toInt()]));
        break;
      }
    case(2):{
        ui->label_Result->setText(QString::number(ar3.array[ui->label_N->text().toInt()]));
        break;
      }
    }
}


void MainWindow::on_pushButton_plus_clicked() {
  ar3 = ar1 + ar2;
  ui->label_array << ar3;
}


void MainWindow::on_pushButton_minus_clicked() {
  ar3 = ar1 - ar2;
  ui->label_array << ar3;
}

