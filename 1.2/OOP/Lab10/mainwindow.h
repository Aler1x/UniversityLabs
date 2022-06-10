#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QValidator>
#include "mystring.h"

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

  void on_pushButton_input_clicked();

  void on_pushButton_output_clicked();

  void on_pushButton_sort_to_larger_clicked();

  void on_pushButton_sort_to_lower_clicked();

  void on_pushButton_min_clicked();

private:
  Ui::MainWindow *ui;
  QRegularExpressionValidator m_stringValidator;
};
#endif // MAINWINDOW_H
