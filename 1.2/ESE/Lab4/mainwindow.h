#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QValidator>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QInputDialog>
#include "form.h"

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
  void on_actionFile_triggered();

  void on_actionSave_triggered();

  void on_actionHelp_triggered();

  void on_actionExit_triggered();

  void on_actionDelete_book_before_year_triggered();

  void on_actionShow_oldest_triggered();

  void on_actionHome_triggered();

private:
  Ui::MainWindow *ui;

  QDoubleValidator m_doubleValidator;
  QIntValidator m_yearValidator, m_pageValidator;

  QRegularExpressionValidator m_authorValidator, m_titleValidator;

  Form form;
};
#endif // MAINWINDOW_H
