#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QTableWidget>
#include <QWidget>
#include <QMessageBox>
#include <matrix.h>
#include "ui_game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow
{
  Q_OBJECT

public:
  Game(QWidget *parent = nullptr);
  ~Game();

private slots:
  void newGame();
  void howToPlay();
  void checkTable();
  void exit();

  void on_pushButton_1_clicked();
  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();
  void on_pushButton_4_clicked();
  void on_pushButton_5_clicked();
  void on_pushButton_6_clicked();
  void on_pushButton_7_clicked();
  void on_pushButton_8_clicked();
  void on_pushButton_9_clicked();
  void on_tableWidget_cellClicked(int row, int column);


  void clickOnButton(int num);

private:
  Ui::Game *ui;
  int Row, Column;

};
#endif // GAME_H
