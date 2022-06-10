#include "mainwindow.h"
#include "window2.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  MainWindow w;
  w.show();
  w.setWindowTitle("Template Array<String>");
  w.setWindowIcon(QIcon("://icon//baseline_data_array_black_48dp.png"));

  window2 w2;
  w2.show();
  w2.setWindowTitle("Template Array<Int>");
  w2.setWindowIcon(QIcon("://icon//baseline_data_array_black_48dp.png"));

  return a.exec();
}
