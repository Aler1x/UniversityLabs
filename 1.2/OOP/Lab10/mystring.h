#ifndef MYSTRING_H
#define MYSTRING_H

#include "array.h"
#include <cstring>

class MyString {
private:
  char* m_string;
  int m_size;
public:

  MyString() {
    m_string = nullptr;
    m_size = 0;
  }

  MyString(const MyString &a) {
    m_size = a.m_size;
    qDebug() << m_size << "class array size";
    m_string = new char[m_size];
    for(int i = 0; i < m_size; i++){
        m_string[i] = a.m_string[i];
      }
  }

  ~MyString(){
    delete[] m_string;
  }

  char* getString() const{
    return m_string;
  }

  int getSize(){
    return m_size;
  }

  friend bool operator>(const MyString a, const MyString b){
    if(strncmp(b.m_string, a.m_string, 2))
      return true;
    else
      return false;
  }

  friend bool operator<(const MyString a, const MyString b){
    if(strncmp(a.m_string, b.m_string, 2))
      return true;
    else
      return false;
  }

  MyString& operator=(const MyString &str) {
    if(m_string != nullptr){
        delete[] m_string;
        m_string = nullptr;
      }

    m_size = str.m_size;
    m_string = new char[m_size];

    for(int i = 0; i < m_size; i++){
        m_string[i] = str.m_string[i];
      }

    return *this;
  }

  MyString& operator=(const QString &qstr){
    if(m_string != nullptr){
        delete[] m_string;
        m_string = nullptr;
      }

    qDebug() << qstr.size() << "size from qstr";

    m_size = qstr.size();
    m_string = new char[m_size];

    for(int i = 0; i < m_size; i++){
        m_string[i] = qstr[i].toLatin1();
      }

    return *this;
  }

  QString toQString(){
    qDebug() << m_size << "size to qstr";
    qDebug() << m_string << "m_string";
    return QString::fromLatin1(m_string, m_size);
  }

};

template<>
class Array<MyString> {
private:
  int m_length;
  MyString *m_data;
public:

  Array() {
    m_length = 0;
    m_data = nullptr;
  }

  ~Array() {
    delete[] m_data;
  }

  void СlearArray() {
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
  }

  void addElement(QString data) {
    resize(m_length+1);
    m_data[m_length-1] = data;
  }

  void resize(int newlength){
    MyString *newarray = new MyString[newlength];

    if(newlength < m_length) m_length = newlength;

    for(int i = 0; i < m_length; i++)
      newarray[i] = m_data[i];

    m_data = newarray;
    m_length = newlength;
  }

  void ShowArray(QLabel *lbl) {
    QString str;
      for(int current = 0; current < m_length; current++) {
        str += m_data[current].toQString() + '\n';
      }
      lbl->setText(str);
  }

  void SortToMin() {
        for(int step = 0, j; step < m_length; step++) {
            MyString key = m_data[step];
            for(j = step - 1; j >= 0 && key < m_data[j]; j--){
                m_data[j+1] = m_data[j];
              }
            m_data[j+1] = key;
          }
  }

  void SortToMax() {
        for(int step = 0, j; step < m_length; step++) {
            MyString key = m_data[step];
            for(j = step - 1; j >= 0 && key > m_data[j]; j--){
                m_data[j+1] = m_data[j];
              }
            m_data[j+1] = key;
          }
  }

  MyString getMin() {
    MyString minNum = m_data[0];

    for(int current = 0; current < m_length; current++) {
        minNum = (minNum > m_data[current]) ? m_data[current] : minNum;
      }
    return minNum;
  }

  MyString operator[](int index){
    return m_data[index];
  }
};

#endif // MYSTRING_H
