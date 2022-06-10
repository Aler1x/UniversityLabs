#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "social.h"
#include "standart.h"
#include "vip.h"

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
  void on_pushButton_std_clicked();

  void on_pushButton_soc_clicked();

  void on_pushButton_vip_clicked();

private:
  Ui::MainWindow *ui;

  Social *socUI;
  Standart *stdUI;
  VIP *vipUI;
};
#endif // MAINWINDOW_H
