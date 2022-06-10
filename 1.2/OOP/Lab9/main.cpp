#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowIcon(QIcon("://logo//Icons//labyrinth.png"));
  w.setWindowTitle("Maze Builder");
  w.show();
  return a.exec();
}
