#include "array.h"


void Array::addElement(double data, int n) {
  if(n >= size || n < 0){
        std::cout << "Error: overwrite " << std::endl;
    } else {
        array[n] = data;
    }
}

void Array::clearArray() {
  delete[] array;
  array = nullptr;
  size = 0;
}

void Array::changeSize(int n) {
  double *ar = new double[n];
  for(int i = 0; i < size; i++){
    ar[i] = array[i];
  }
  this->clearArray();
  array = ar;
  size = n;
}

double Array::getMaxValue() {
  double max = array[0];
  for(int i = 0; i < size; i++){
      max = (array[i] > max) ? array[i] : max;
    }
  return max;
}

double Array::getMinValue() {
  double max = array[0];
  for(int i = 0; i < size; i++){
      max = (array[i] < max) ? array[i] : max;
    }
  return max;
}

double Array::averageValue() {
  double ave = 0;
  for(int i = 0; i < size; i++){
      ave += array[0];
    }
  return ave/size;
}

double Array::getElementValue(int num) {
  return array[num];
}

void Array::selectionSortToLower() {
  if(!array){
      std::cout << "Error: array is NULL " << std::endl;
      return;
  }

  for(int step = 0; step < size - 1; step++){
      int min_idx = step;
      for(int i = step + 1; i < size-step; i++){
          min_idx = (array[i] > array[min_idx]) ? i : min_idx;
      }//for(i)
      if(min_idx != step){
        double temp = array[step];
        array[step] = array[min_idx];
        array[min_idx] = temp;
      }//if(swap)
  }//for(step)
  std::cout << "Selection sort done" << std::endl;
}

void Array::bubbleSortToLarger() {

  if(!array){
      std::cout << "Error: array is NULL " << std::endl;
      return;
  }

  for(int step = 0; step < size; step++){
      bool swapped = false;
      for(int i = 0; i < size-step-1; i++){
          if(array[i] > array[i+1]){
              double temp = array[i];
              array[i] = array[i+1];
              array[i+1] = temp;
              swapped  = true;
            }//if
        }//for(i)
      if(!swapped)
        break;
    }//for(step)

  std::cout << "Bubble sort done" << std::endl;
}

void operator>>(QListWidget *in, Array &ar) {
  ar.clearArray();

  ar.changeSize(in->count());

  for(int i = 0; i < in->count(); i++) {
      in->setCurrentRow(i);
      ar.addElement(in->currentItem()->text().toDouble(), i);
    }
}

void operator<<(QListWidget *out, Array &ar) {
  out->clear();

  for(int i = 0; i < ar.size; i++){
      out->addItem(QString::number(ar.array[i]));
    }
}

void operator>>(QTableWidget *in, Array &ar) {
  ar.clearArray();

  ar.changeSize(in->rowCount());

  QString str;
  for(int i = 0; i < in->rowCount(); i++) {
      str = in->item(i, 0)->text();
      if(str != ""){
        ar.addElement(str.toDouble(), i);
        }
    }
}

void operator<<(QTableWidget *out, Array &ar) {
  out->clearContents();

  out->setRowCount(ar.size);
  out->setColumnCount(1);

  for(int i = 0; i < ar.size; i++) {
      QTableWidgetItem *item = new QTableWidgetItem();
      item->setText(QString::number(ar.array[i]));
      out->setItem(i, 0, item);
    }
}

void operator<<(QLabel *out, Array &ar) {
  out->clear();

  QString str = "";

  for(int i = 0; i < ar.size; i++) {
      str += QString::number(ar.array[i]) += " ";
    }
  out->setText(str);
}

Array Array::operator+(Array &ar){
  if(size > ar.size){ar.changeSize(size);}
  else if(size < ar.size) {changeSize(ar.size);}

  double *res_arr = new double[size];

  for(int i = 0; i < size; i++){
      res_arr[i] = array[i] + ar.array[i];
    }
  return Array(res_arr, size);
}

Array Array::operator-(Array &ar){
  if(size > ar.size){ar.changeSize(size);}
  else if(size < ar.size) {changeSize(ar.size);}

  double *res_arr = new double[size];

  for(int i = 0; i < size; i++){
      res_arr[i] = array[i] - ar.array[i];
    }
  return Array(res_arr, size);
}

void operator*(Array &ar, double n){
  for(int i = 0; i < ar.size; i++){
    ar.array[i] = ar.array[i] * n;
    }
}
