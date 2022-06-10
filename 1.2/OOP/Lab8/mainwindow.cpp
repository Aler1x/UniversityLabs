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

void MainWindow::on_pushButton_std_clicked()
{
    Standart* win = new Standart();
    win->show();
}


void MainWindow::on_pushButton_soc_clicked()
{
  Social* win = new Social();
  win->show();
}


void MainWindow::on_pushButton_vip_clicked()
{
  VIP* win = new VIP();
  win->show();
}

