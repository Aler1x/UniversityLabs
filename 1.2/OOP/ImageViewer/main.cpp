#include "imageviewer.h"
#include <scenemanager.h>

#include <QApplication>

int main(int argc, char *argv[]){
  QApplication a(argc, argv);

  SceneManager sceneManager;
  ImageViewer w{sceneManager};
  w.show();
  return a.exec();
}
