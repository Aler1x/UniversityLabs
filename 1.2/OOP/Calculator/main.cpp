#include "mainwindow.h"

#include <QtWidgets>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  MainWindow calc;

  calc.show();

  return app.exec();
}
