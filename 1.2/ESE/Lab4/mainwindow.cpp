#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow), m_doubleValidator(0, 5000, 2, this)
  , m_yearValidator(0, 2022, this), m_pageValidator(0, 5000, this)
  , m_authorValidator(QRegularExpression("^\\D{80}$")), m_titleValidator(QRegularExpression("^\\D{80}$"))
{
  ui->setupUi(this);
  ui->tableWidget->setColumnWidth(0, 160);
  ui->tableWidget->setColumnWidth(1, 330);
  ui->tableWidget->setColumnWidth(2, 117);
  ui->tableWidget->setColumnWidth(3, 90);
  ui->tableWidget->setColumnWidth(4, 97);

  m_doubleValidator.setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_5->setValidator(&m_doubleValidator);
    ui->lineEdit_5->setPlaceholderText("Enter price");

  //m_intValidator1.setNotation(QIntValidator::StandardNotation);
    ui->lineEdit_4->setValidator(&m_yearValidator);
    ui->lineEdit_4->setPlaceholderText("Enter year");

  //m_intValidator2.setNotation(QIntValidator::StandardNotation);
    ui->lineEdit_3->setValidator(&m_pageValidator);
    ui->lineEdit_3->setPlaceholderText("Enter pages");

    ui->lineEdit->setValidator(&m_authorValidator);
    ui->lineEdit->setPlaceholderText("Enter book`s author");

    ui->lineEdit_2->setValidator(&m_titleValidator);
    ui->lineEdit_2->setPlaceholderText("Enter book`s title");

    ui->statusbar->showMessage("Eldest", 1000000000);
}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::on_actionFile_triggered()
{
  QString fileName = QFileDialog::getOpenFileName(this, "Open file", "C:\\Users\\alexm\\Documents", "*.txt");
  QFile file(fileName);
  if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
      QMessageBox::warning(this, "BookShelf", "Cannot open file: " + file.errorString());
//      QMessageBox msgbox;
//      QString msgstr = "Cannot open file: " + file.errorString();
//      msgbox.setText(msgstr);
//      msgbox.setWindowTitle("BookShelf");
//      msgbox.setWindowIcon(QIcon(":/icons/Icons/baseline_auto_stories_black_48dp.png"));
//      msgbox.show();
//      msgbox.exec();
      return;
  } else {
      QMessageBox::critical(this, "BookShelf", "Incorrect data in file\n" + fileName);
    }
  QTextStream in(&file);
  file.close();
}

void MainWindow::on_actionSave_triggered()
{
  QString fileName = QFileDialog::getOpenFileName(this, "Save in file", "C:\\Users\\alexm\\Documents", "*.txt");
  QFile file(fileName);
  if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
      QMessageBox::warning(this, "BookShelf", "Cannot save file: " + file.errorString());
//      QMessageBox msgbox;
//      QString msgstr = "Cannot save file: " + file.errorString();
//      msgbox.setText(msgstr);
//      msgbox.setWindowTitle("BookShelf");
//      msgbox.setWindowIcon(QIcon(":/icons/Icons/baseline_auto_stories_black_48dp.png"));
//      msgbox.show();
//      msgbox.exec();
      return;
  }
  QTextStream in(&file);
  file.close();
}


void MainWindow::on_actionHelp_triggered()
{
  QWidget *inst = new Form;
  inst->show();
}


void MainWindow::on_actionExit_triggered()
{
  QMessageBox::warning(this, "BookShelf", "You did not save information\nYou really want to exit program");
}


void MainWindow::on_actionDelete_book_before_year_triggered()
{
  bool ok;
  int year = QInputDialog::getInt(this, tr("Enter year"),
                                       tr("Books published before entered year will be deleted"), QLineEdit::Normal,
                                       0, 2022, 1, &ok);
}


void MainWindow::on_actionShow_oldest_triggered()
{
  QMessageBox::warning(this, "BookShelf", "The list of books is empty");
}


void MainWindow::on_actionHome_triggered()
{
    ui->tableWidget->setRowCount(14);
}

