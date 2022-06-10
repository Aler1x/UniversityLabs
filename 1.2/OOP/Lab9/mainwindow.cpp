#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_comboBox_type_activated(int index)
{
  switch(index){
    case(0):{
        ui->comboBox_size->setEnabled(false);
        ui->comboBox_rect_type->setEnabled(false);
        break;
      }
    case(1):{
        ui->comboBox_size->setEnabled(true);
        ui->comboBox_rect_type->setEnabled(false);
        break;
      }
    case(2):{
        ui->comboBox_size->setEnabled(true);
        ui->comboBox_rect_type->setEnabled(true);
        break;
      }
  }
}


void MainWindow::on_comboBox_form_activated(int index)
{
    if(index != 0 || (ui->comboBox_type->currentIndex()) == 0 || (ui->comboBox_type->currentIndex()) == 1){
        ui->comboBox_rect_type->setEnabled(false);
      } else {
        ui->comboBox_rect_type->setEnabled(true);
      }
}


void MainWindow::on_pushButton_clicked()
{
    int currClass = ui->comboBox_type->currentIndex();
    int currSize = ui->comboBox_size->currentIndex();
    int size;
    switch(currSize){
      case(0): size = 10; break;
      case(1): size = 20; break;
      case(2): size = 30; break;
      default: size = 20;
      }

    SimpleMazeBuilder* m0 = new SimpleMazeBuilder(ui->comboBox_form->currentText());
    MiddleMazeBuilder* m1 = new MiddleMazeBuilder(ui->comboBox_form->currentText(), size);
    ComplexMazeBuilder* m2 = new ComplexMazeBuilder(ui->comboBox_form->currentText(), ui->comboBox_rect_type->currentText() , size);
    MazeBuilder* mazelist[3];
    mazelist[0] = m0;
    mazelist[1] = m1;
    mazelist[2] = m2;
    if(currClass == 0){

       mazelist[0]->createMaze(ui->label);
      } else if(currClass == 1){

        mazelist[1]->createMaze(ui->label);
      } else if(currClass == 2){

        mazelist[2]->createMaze(ui->label);
      }

    for(int i = 0; i < 3; i++){
        delete mazelist[i];
      }
}

