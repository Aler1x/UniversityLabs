#include "scenemanager.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QImageReader>

SceneManager::SceneManager(QObject *parent): QObject{parent}{
  imageScene = new QGraphicsScene(this);
  supportedExtensions();
}

QGraphicsScene *SceneManager::scene(){
  return imageScene;
}

QStringList SceneManager::supportedExtensions()
{
  return imgExtensions;
}

void SceneManager::openImage(const QString &path){
  openFile(path);
  showImage(path);
}

void SceneManager::fitInWindow(){
  if(imageScene->items().size() && imageScene->views().size()){
      auto view = imageScene->views().at(0);
      view->fitInView(imageScene->items().at(0), Qt::KeepAspectRatio);
      view->setSceneRect(imageScene->items().at(0)->boundingRect());
    }
}

bool SceneManager::isFileSupported(const QString &path){
  for(auto ext : imgExtensions){
      ext = ext.remove(0,1);
      if(path.endsWith(ext, Qt::CaseInsensitive)){
          return 1;
        }
    }
  return 0;
}

void SceneManager::showImage(const QString &path){
  imageScene->clear();

  QImageReader imgReader(path);
  imgReader.setAutoTransform(1);

  QImage img = imgReader.read();

  if(!img.isNull()){
      QPixmap pixmap = QPixmap::fromImage(img);

      imageScene->addPixmap(pixmap);
      imageScene->update();

      emit imageChanged(getCurrentFilename());
    }
}

void SceneManager::openFile(const QString &path){
  QFileInfo current(path);
  currentFilePath = path;
  currentFileName = current.fileName();
}

QString SceneManager::getCurrentFilename(){
  return currentFileName;
}
