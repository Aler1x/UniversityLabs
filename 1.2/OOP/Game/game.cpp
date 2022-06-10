#include "game.h"

#include <QTableWidget>
#include <QWidget>
#include <QMessageBox>

Matrix matrix;

Game::Game(QWidget *parent): QMainWindow(parent) , ui(new Ui::Game)
{
  ui->setupUi(this);
  setWindowTitle("Sudoku");
  Game::newGame();
  connect(ui->actionExit, &QAction::triggered, this, &Game::exit);
  connect(ui->actionNew, &QAction::triggered, this, &Game::newGame);
  connect(ui->actionCheck, &QAction::triggered,this, &Game::checkTable);
  connect(ui->actionQuestion, &QAction::triggered,this, &Game::howToPlay);
}

void Game::newGame(){
 matrix.start();
 for (int i = 0; i < 9; ++i)
 {
     for (int j = 0; j < 9; ++j)
     {
         QTableWidgetItem* Cell = ui->tableWidget->item(i, j);
         QString str = "";
         str += '0' + QString::number(matrix.read(i, j));
         const QString cstr = str;
         Cell->setText(cstr);
         if (matrix.read(i, j))
         {
             QColor color(188,188,188);
             Cell->setBackground(color);
         }
         else
         {
             QColor color(255,255,255);
             Cell->setBackground(color);
         }
     }
 }
}

void Game::clickOnButton(int num)
{
    QTableWidgetItem* Cell = ui->tableWidget->item(Row, Column);
    matrix.write(Row, Column, num);
    QString str = "";
    str += '0' + QString::number(matrix.read(Row, Column));
    const QString cstr = QString::number(num);
    Cell->setText(cstr);
}

void Game::howToPlay(){
  QMessageBox faq;
  faq.setWindowTitle("How to play sudoku");
  faq.setWindowIcon(QIcon(":/icons/Icons/sudoku.png"));
  faq.setText("Click on a cell, which you want to change.\nThen click on a button with number you want to enter on cell.");
  faq.exec();
}

void Game::checkTable(){
  if (matrix.checkWin())
  {
      QMessageBox youWin;
      youWin.setWindowIcon(QIcon(":/icons/Icons/check.png"));
      youWin.setText("You win!");
      youWin.exec();
  }
  else
  {
      QMessageBox youWin;
      youWin.setWindowIcon(QIcon(":/icons/Icons/forbidden.png"));
      youWin.setText("Sudoku don't solved");
      youWin.exec();
  }
}

void Game::exit(){
  QCoreApplication::quit();
}

Game::~Game()
{
  delete ui;
}


void Game::on_tableWidget_cellClicked(int row, int column)
{
  Row = row;
  Column = column;
}


void Game::on_pushButton_1_clicked()
{
    clickOnButton(1);
}


void Game::on_pushButton_2_clicked()
{
  clickOnButton(2);
}


void Game::on_pushButton_3_clicked()
{
    clickOnButton(3);
}


void Game::on_pushButton_4_clicked()
{
    clickOnButton(4);
}


void Game::on_pushButton_5_clicked()
{
    clickOnButton(5);
}


void Game::on_pushButton_6_clicked()
{
    clickOnButton(6);
}


void Game::on_pushButton_7_clicked()
{
    clickOnButton(7);
}


void Game::on_pushButton_8_clicked()
{
    clickOnButton(8);
}


void Game::on_pushButton_9_clicked()
{
    clickOnButton(9);
}



