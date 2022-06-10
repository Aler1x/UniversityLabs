#include "game.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Game window;
  window.show();
  return a.exec();
}
