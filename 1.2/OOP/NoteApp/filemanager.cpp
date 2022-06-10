#include "filemanager.h"

FileManager::FileManager(QObject *parent)
  : QObject{parent}
{
  supportedExtensions();
}

QStringList FileManager::supportedExtensions()
{
  return imgExtensions;
}

bool FileManager::isFileSupported(const QString &path){
  for(auto ext : imgExtensions){
      ext = ext.remove(0,1);
      if(path.endsWith(ext, Qt::CaseInsensitive)){
          return 1;
        }
    }
  return 0;
}

void FileManager::openFile(const QString &path){
  QFileInfo current(path);
  currentFilePath = path;
  currentFileName = current.fileName();
}
