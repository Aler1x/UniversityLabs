#ifndef NOTE_H
#define NOTE_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Note; }
QT_END_NAMESPACE

class Note : public QMainWindow
{
  Q_OBJECT

public:
  Note(QWidget *parent = nullptr);
  ~Note();

private slots:
    void newDocument();

    void open();

    void save();

    void save_as();

    void print();

    void exit();

    void copy();

    void cut();

    void paste();

    void undo();

    void redo();

    void about();

private:
  Ui::Note *ui;
  QString currentFile = "";
};
#endif // NOTE_H
