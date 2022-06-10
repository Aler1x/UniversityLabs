#include "mainwindow.h"
#include "ui_mainwindow.h"

Array<MyString> stringArray;

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
  ,m_stringValidator(QRegularExpression(".{512}"))
{
  ui->setupUi(this);
  ui->lineEdit_input->setValidator(&m_stringValidator);
  ui->lineEdit_input->setPlaceholderText("Enter string here");
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pushButton_input_clicked()
{
  stringArray.addElement(ui->lineEdit_input->text());
  stringArray.ShowArray(ui->label_output);
}


void MainWindow::on_pushButton_output_clicked()
{
  stringArray.ShowArray(ui->label_output);
}


void MainWindow::on_pushButton_sort_to_larger_clicked()
{
    stringArray.SortToMax();
    stringArray.ShowArray(ui->label_output);
}


void MainWindow::on_pushButton_sort_to_lower_clicked()
{
  stringArray.SortToMin();
  stringArray.ShowArray(ui->label_output);
}


void MainWindow::on_pushButton_min_clicked()
{
  MyString minstr = stringArray.getMin();
  ui->label_output->setText(minstr.toQString());
}

