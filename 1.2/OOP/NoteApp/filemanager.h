#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QFileInfo>
#include <QDir>

class FileManager : public QObject
{
  Q_OBJECT
public:
  explicit FileManager(QObject *parent = nullptr);

  bool isFileSupported(const QString &path);

  void openFile(const QString &path);

  QStringList supportedExtensions();

signals:

private:

  QStringList fileNamesInCurrentPath;

  QString currentFilePath;
  QString currentFileName;

  const QStringList imgExtensions = {".txt", ".cpp", ".h", ".hpp"};

};

#endif // FILEMANAGER_H
