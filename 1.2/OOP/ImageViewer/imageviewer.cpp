#include "imageviewer.h"
#include "ui_imageviewer.h"
#include <scenemanager.h>

ImageViewer::ImageViewer(SceneManager &manager, QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::ImageViewer)
  , sceneManager(manager)
{
  ui->setupUi(this);
  this->setCentralWidget(ui->imageView);
  connect(ui->actionExit, &QAction::triggered, this, &ImageViewer::exit);
  connect(ui->actionAbout, &QAction::triggered, this, &ImageViewer::about);
  connect(ui->actionOpen, &QAction::triggered, this, &ImageViewer::showOpenDialog);
  connect(ui->actionZoomIn, &QAction::triggered, this, &ImageViewer::zoomIn);
  connect(ui->actionZoomOut, &QAction::triggered, this, &ImageViewer::zoomOut);

  setWindowTitle(defaultWindowTitle);
  ui->imageView->setScene(sceneManager.scene());

  connect(&sceneManager, &SceneManager::imageChanged, this, &ImageViewer::ImageChanged);
}

ImageViewer::~ImageViewer(){
  delete ui;
}

void ImageViewer::openImage(const QString &path)
{
  if(sceneManager.isFileSupported(path)){
      sceneManager.openImage(path);
      fitInWindow();
    }
}

void ImageViewer::wheelEvent(QWheelEvent *event)
{
  if(event->angleDelta().y() > 0){
      zoomIn();
    }
  else{
      zoomOut();
    }
}

void ImageViewer::mouseDoubleClickEvent(QMouseEvent *event)
{
  if(event->button() == Qt::LeftButton){
      fitInWindow();
    }
}


void ImageViewer::ImageChanged(const QString &filename)
{
  setWindowTitle(QString("%0 - \"%1\"").arg(defaultWindowTitle).arg(filename));
}

void ImageViewer::fitInWindow()
{
  sceneManager.fitInWindow();
}

void ImageViewer::zoomIn()
{
  ui->imageView->scale(1.1, 1.1);
}

void ImageViewer::zoomOut()
{
    ui->imageView->scale(0.9, 0.9);
}

void ImageViewer::showOpenDialog()
{
  QString imageExtensions = QString("").arg(sceneManager.supportedExtensions().join(" "));

  QString path = QFileDialog::getOpenFileName(this, "Open image", "", imageExtensions);

  if(path.size()){
      openImage(path);
    }
}

void ImageViewer::exit(){
  QCoreApplication::quit();
}

void ImageViewer::about(){
  QMessageBox w;
  w.setWindowTitle("About");
  w.setWindowIcon(QIcon(":/icons/Icons/information.png"));
  w.setText("Image viewer app created by Oleksii Morozov.");
  w.exec();
}
