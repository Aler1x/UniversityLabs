#pragma once

#include <QObject>
#include <imageviewer.h>

class QGraphicsScene;

class SceneManager : public QObject
{
  Q_OBJECT
public:
  explicit SceneManager(QObject *parent = nullptr);

  QGraphicsScene* scene();
  QStringList supportedExtensions();
  void openImage(const QString &path);

  void fitInWindow();
  bool isFileSupported(const QString &path);

  void setExtensions(const QStringList &extensions);
  void openFile(const QString &path);
  QString getCurrentFilename();

signals:
  void imageChanged(const QString &filename);

private:
  void showImage(const QString &path);

  QStringList fileNamesInCurrentPath;

  QString currentFilePath;
  QString currentFileName;

  QGraphicsScene *imageScene = nullptr;
  const QStringList imgExtensions = {".png", ".bmp", ".jpg", ".jpeg"};
};

