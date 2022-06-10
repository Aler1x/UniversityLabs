#ifndef WINDOW2_H
#define WINDOW2_H

#include <QWidget>

namespace Ui {
  class window2;
}

class window2 : public QWidget
{
  Q_OBJECT

public:
  explicit window2(QWidget *parent = nullptr);
  ~window2();

private slots:
  void on_pushButton_input_clicked();

  void on_pushButton_sort_to_larger_clicked();

  void on_pushButton_sort_to_lower_clicked();

  void on_pushButton_min_clicked();

  void on_pushButton_output_clicked();

private:
  Ui::window2 *ui;
};

#endif // WINDOW2_H
