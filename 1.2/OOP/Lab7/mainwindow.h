#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "array.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  int setArray();

private slots:

  void on_pushButton_input_table_widget_clicked();

  void on_pushButton_output_table_widget_clicked();

  void on_pushButton_iput_list_widget_clicked();

  void on_pushButton_output_list_widget_clicked();

  void on_pushButton_min_clicked();

  void on_pushButton_max_clicked();

  void on_pushButton_ave_clicked();

  void on_pushButton_sort_to_higher_clicked();

  void on_pushButton_sort_lower_clicked();

  void on_pushButton_n_element_2_clicked();

  void on_pushButton_mult_n_clicked();

  void on_pushButton_n_element_clicked();

  void on_pushButton_plus_clicked();

  void on_pushButton_minus_clicked();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
