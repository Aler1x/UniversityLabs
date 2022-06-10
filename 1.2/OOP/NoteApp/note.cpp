#include "note.h"
#include "ui_note.h"

Note::Note(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::Note)
{
  ui->setupUi(this);
  this->setCentralWidget(ui->textEdit);

  connect(ui->actionNew, &QAction::triggered, this, &Note::newDocument);
  connect(ui->actionOpen, &QAction::triggered, this, &Note::open);
  connect(ui->actionSave, &QAction::triggered, this, &Note::save);
  connect(ui->actionSave_as, &QAction::triggered, this, &Note::save_as);
  connect(ui->actionPrint, &QAction::triggered, this, &Note::print);
  connect(ui->actionExit, &QAction::triggered, this, &Note::exit);

  connect(ui->actionCopy, &QAction::triggered, this, &Note::copy);
  connect(ui->actionCut, &QAction::triggered, this, &Note::cut);
  connect(ui->actionPaste, &QAction::triggered, this, &Note::paste);

  connect(ui->actionUndo, &QAction::triggered, this, &Note::undo);
  connect(ui->actionRedo, &QAction::triggered, this, &Note::redo);

  connect(ui->actionAbout, &QAction::triggered, this, &Note::about);
}

Note::~Note(){
  delete ui;
}

void Note::about(){
  QMessageBox w;
  w.setWindowTitle("About");
  w.setWindowIcon(QIcon(":/image/NoteIcons/about.png"));
  w.setText("Notepad app created by Oleksii Morozov.");
  w.exec();
}

void Note::newDocument(){
    currentFile.clear();
    ui->textEdit->setText(QString());
    setWindowTitle("*New");
    statusBar()->showMessage(tr("File created"), 1000);
}

void Note::open(){
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
    statusBar()->showMessage(tr("File opened"), 1000);
}

void Note::save(){
    QString fileName;
    // If we don't have a filename from before, get one.
    if (currentFile.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Save");
        currentFile = fileName;
    } else {
        fileName = currentFile;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
    statusBar()->showMessage(tr("File saved"), 1000);
}


void Note::save_as(){
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
    statusBar()->showMessage(tr("File saved"), 1000);
}

void Note::print(){
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    if (dialog.exec() == QDialog::Rejected)
        return;
    ui->textEdit->print(&printer);
    statusBar()->showMessage(tr("File printed"), 1000);
}

void Note::exit(){
    QCoreApplication::quit();
}

void Note::copy(){
    ui->textEdit->copy();
    statusBar()->showMessage(tr("Text copied"), 1000);
}

void Note::cut(){
    ui->textEdit->cut();
    statusBar()->showMessage(tr("Text cutted"), 1000);
}

void Note::paste(){
    ui->textEdit->paste();
    statusBar()->showMessage(tr("text pasted"), 1000);
}

void Note::undo(){
     ui->textEdit->undo();
}

void Note::redo(){
    ui->textEdit->redo();
}
