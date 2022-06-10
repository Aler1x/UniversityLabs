#pragma once

#include <scenemanager.h>

#include <QMainWindow>
#include <QMessageBox>
#include <QStringList>
#include <QFileDialog>
#include <QWheelEvent>

#include <QtPrintSupport/QPrintDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class ImageViewer; }
QT_END_NAMESPACE

class SceneManager;

class ImageViewer : public QMainWindow
{
  Q_OBJECT

public:
  ImageViewer(SceneManager &manager, QWidget *parent = nullptr);
  ~ImageViewer();

  void openImage(const QString &path);

protected:
  void wheelEvent(QWheelEvent *event) override;
  void mouseDoubleClickEvent(QMouseEvent *event) override;

private slots:

  void ImageChanged(const QString &filename);

  void fitInWindow();
  void zoomIn();
  void zoomOut();

  void showOpenDialog();

  void exit();
  void about();

private:
  Ui::ImageViewer *ui;

  SceneManager &sceneManager;

  const QString defaultWindowTitle = "Image Viewer";
};
