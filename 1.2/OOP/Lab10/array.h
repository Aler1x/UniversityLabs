#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>
#include <QLabel>
#include <QString>
#include <iostream>


template <class Type>

class Array {
private:
  int m_arrayLength;
  Type *m_arrayData;
public:

  Array() {
    m_arrayLength = 0;
    m_arrayData = nullptr;
  }

  ~Array() {
    delete[] m_arrayData;
  }

  void СlearArray() {
    delete[] m_arrayData;
    m_arrayData = nullptr;
    m_arrayLength = 0;
  }

  void addElement(Type data) {
    ResizeArray(m_arrayLength+1);
    m_arrayData[m_arrayLength-1] = data;
  }

  void ResizeArray(int new_length) {
    Type *new_arr = new Type[new_length];

    if(m_arrayData) {
    m_arrayLength = (new_length <= m_arrayLength) ? new_length: m_arrayLength;
    for(int i = 0; i < m_arrayLength; i++){
        new_arr[i] = m_arrayData[i];
      }
    }
    m_arrayData = new_arr;
    m_arrayLength = new_length;
  }

  void ShowArray(QLabel *lbl) {
    if(m_arrayLength == 0){
        std::cout << "Array has not have element." << std::endl;
        return;
      }
      QString str;
        for(int current = 0; current < m_arrayLength; current++) {
          str += QString::number(m_arrayData[current]) += " ";
        }
      lbl->setText(str);
  }

  void SortToMin() {
    if(m_arrayLength == 0){
        std::cout << "Array has not have element." << std::endl;
        return;
      }

        for(int step = 0, j; step < m_arrayLength; step++) {
            Type key = m_arrayData[step];
            for(j = step - 1; j >= 0 && key > m_arrayData[j]; j--){
                m_arrayData[j+1] = m_arrayData[j];
              }
            m_arrayData[j+1] = key;
          }
  }

  void SortToMax() {
    if(m_arrayLength == 0){
        std::cout << "Array has not have element." << std::endl;
        return;
      }
        for(int step = 0, j; step < m_arrayLength; step++) {
            Type key = m_arrayData[step];
            for(j = step - 1; j >= 0 && key < m_arrayData[j]; j--){
                m_arrayData[j+1] = m_arrayData[j];
              }
            m_arrayData[j+1] = key;
          }
  }

  Type getMin() {
    if(m_arrayLength == 0){ throw ("Incorrect index."); }

    Type* minNum = new Type;
    *minNum = m_arrayData[0];

    for(int current; current < m_arrayLength; current++) {
        (*minNum) = ((*minNum) > m_arrayData[current]) ? m_arrayData[current] : (*minNum);
      }
    return *minNum;
  }

  Array& operator=(Array* a) {
    this->СlearArray();
    this->m_arrayData = a->m_arrayData;
    this->m_arrayLength = a->m_arrayLength;
    return this;
  }

  Array operator=(Type data) {
    this->addElement(data);
    return *this;
  }
};

#endif // TEMPLATEARRAY_H
