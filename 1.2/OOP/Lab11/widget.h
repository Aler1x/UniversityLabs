#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QLayout>

#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);

  std::stack<float, std::vector<float>> stack_1;
  std::stack<float, std::vector<float>> stack_2;
  std::queue<float> queue;
  std::vector<float> vector;

private slots:
  void OnStart();

private:
  QLabel *taskResult_1;
  QLabel *outputLabel_1;
  QLabel *taskResult_2;
  QLabel *outputLabel_2;
  QLabel *taskResult_3;
  QLabel *outputLabel_3;
  QLabel *taskResult_4;
  QLabel *outputLabel_4;
  QLabel *taskResult_5;
  QLabel *outputLabel_5;
  QLabel *taskResult_6;
  QLabel *outputLabel_6;

  QPushButton * startButton;
};
#endif // WIDGET_H
