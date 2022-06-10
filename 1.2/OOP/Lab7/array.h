#ifndef ARRAY_H
#define ARRAY_H

#ifndef SET_H
#define SET_H
#include <iostream>

#include <QTableWidget>
#include <QListWidget>
#include <QTextEdit>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QMessageBox>
#endif // SET_H

class Array
{
public:
  //--------------------------------------------------------
  double *array;
  int size;
  //--------------------------------------------------------
  Array(){
    array = new double[0];
    size = 0;
  }
  //--------------------------------------------------------
  Array(const Array &ar){
    array = ar.array;
    size = ar.size;
  }
  //--------------------------------------------------------
  Array(int n){
    array = new double[n];
    size = n;
  }
  //--------------------------------------------------------
  Array(double *ar, int n){
    array = ar;
    size = n;
  }
  //--------------------------------------------------------
  ~Array(){clearArray();}
  //--------------------------------------------------------
  void changeSize(int n);
  void addElement(double data, int n);
  void clearArray();
  //--------------------------------------------------------
  double getMaxValue();
  double getMinValue();
  double averageValue();
  double getElementValue(int num);
  //--------------------------------------------------------
  void selectionSortToLower();
  void bubbleSortToLarger();
  //--------------------------------------------------------
  friend void operator>>(QListWidget *in, Array &ar);
  friend void operator<<(QListWidget *out, Array &ar);
  friend void operator<<(QLabel *out, Array &ar);
  friend void operator>>(QTableWidget *in, Array &ar);
  friend void operator<<(QTableWidget *out, Array &ar);
  //--------------------------------------------------------
  Array operator+(Array &ar);
  Array operator-(Array &ar);
  //--------------------------------------------------------
  friend void operator*(Array &, double n);
  //--------------------------------------------------------
};

#endif // ARRAY_H
