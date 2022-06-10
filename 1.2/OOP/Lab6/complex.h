#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include "ui_mainwindow.h"


class Complex
{
public:
  Complex();
  Complex(double r, double i);
  ~Complex();

  friend void operator<<(QLabel *resultLine, Complex &a);
  friend void operator>>(QLineEdit *array[], Complex &a);

  friend bool operator<(const Complex &a, const Complex &b);
  friend bool operator>(const Complex &a, const Complex &b);
  friend bool operator==(const Complex &a, const Complex &b);

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

  Complex operator+(const Complex &b);
  Complex operator-(const Complex &b);
  Complex operator*(const Complex &b);

  void powComplex(int n, QLabel *resultLine);
  double module() const;
  double operator!();
  void trigonometry(QLabel *resultLine);

  static int getAmount();

private:
  double real;
  double imagine;
  static int amount;
};
