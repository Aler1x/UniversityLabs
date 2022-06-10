#include "window2.h"
#include "ui_window2.h"
#include "array.h"

Array<int> intArray;

window2::window2(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::window2)
{
  ui->setupUi(this);
  ui->lineEdit_input->setPlaceholderText("Enter array here");
}

window2::~window2()
{
  delete ui;
}


void window2::on_pushButton_input_clicked()
{
  intArray.addElement(ui->lineEdit_input->text().toInt());
  intArray.ShowArray(ui->label_output);
}


void window2::on_pushButton_sort_to_larger_clicked()
{
  intArray.SortToMax();
  intArray.ShowArray(ui->label_output);
}


void window2::on_pushButton_sort_to_lower_clicked()
{
  intArray.SortToMin();
  intArray.ShowArray(ui->label_output);
}


void window2::on_pushButton_min_clicked()
{
  ui->label_output->setText(QString::number(intArray.getMin()));
}


void window2::on_pushButton_output_clicked()
{
  intArray.ShowArray(ui->label_output);
}

