#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include "ui_mainwindow.h"


class Complex
{
public:
  Complex();
  Complex(double r, double i);

  double getReal();
  double getImagine();

  void setReal(double a);
  void setImagine(double a);
  void setAll(double a, double b);

  void readFromForm(QLineEdit *real, QLineEdit *imagine);
  void printToForm(QLabel *resultLine);

  Complex sum(const Complex &b);
  Complex mult(const Complex &b);
  Complex minus(const Complex &b);
  Complex pow(int n);

  double module();
  void trigonometry(QLabel *resultLine);

private:
  double real;
  double imagine;
};
