#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include <QWidget>
#include <QString>

#include <cmath>

class QPushButton;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parentWidget = nullptr);
  ~MainWindow();
  void calculate();

private:
  Ui::MainWindow *ui;

private slots:
  void digits();
  void operations();
  void math_operations();
  void on_clearButton_clicked();
  void on_pointButton_clicked();
  void on_resultButton_clicked();
};
#endif // MAINWINDOW_H
