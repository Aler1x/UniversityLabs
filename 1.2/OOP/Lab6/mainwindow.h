#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "complex.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:

  void scan(Complex *Z1, Complex *Z2);
  void scanZ1(Complex *Z1);
  void scanZ2(Complex *Z2);

  void buttonClicked();

  void on_pushButton_mod_Z1_clicked();

  void on_pushButton_mod_Z2_clicked();

  void onPushButtonZ1PowNClicked();

  void onPushButtonZ2PowNClicked();

  void on_pushButton_Z1_trm_Form_clicked();

  void on_pushButton_Z2_trmForm_clicked();

  void onAmountClicked();

  void boolButtonClicked();

  void operatorButtonClicked();

private:
  Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
