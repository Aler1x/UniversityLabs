#include "complex.h"

Complex::Complex()
{
  real = 0;
  imagine = 0;
}

Complex::Complex(double r, double i){
  real = r;
  imagine = i;
}

void Complex::readFromForm(QLineEdit *real, QLineEdit *imagine){
  if(real->text() != ""){
      this->real = real->text().toDouble();
    }
  if(imagine->text() != "") {
      this->imagine = imagine->text().toDouble();
    }
}

void Complex::printToForm(QLabel *resultLine)
{
  QString str, realSTR, imagineSTR;

  if(QString::number(real) != "0"){
    realSTR = QString::number(real);
    }
  if(QString::number(imagine) != "0"){
      imagineSTR = QString::number(imagine);
    }

  if (imagine > 0){
  str = realSTR + "+" + imagineSTR + "i";
    } else if(imagine < 0){
  str = realSTR + imagineSTR + "i";
    }else {
      str = realSTR;
    }
  if (real == 0){
      str = imagineSTR + "i";
    }
  resultLine->setText(str);
}

Complex Complex::sum(const Complex &b)
{
  return Complex((real + b.real), (imagine+b.imagine));
}

Complex Complex::mult(const Complex &b)
{
  return Complex(((real * b.real) - (imagine * b.imagine)), ((real*b.imagine)+(imagine*b.real)));

}

Complex Complex::minus(const Complex &b)
{
  return Complex((real - b.real), (imagine - b.imagine));
}

Complex Complex::pow(int n)
{
    if( n == 0){
      return Complex(0, 0);

    } else if(n == 1){
      return *this;

    } else if (n&1){
      return this->mult(this->pow(n - 1));

    } else {
      return this->pow(n / 2).mult(this->pow(n / 2));
      }
}

double Complex::module() {
  return sqrt( (real * real) + (imagine * imagine) );
}

void Complex::trigonometry(QLabel *resultLine)
{
  double r = this->module();
  double arg;
  double x = this->real;
  double y = this->imagine;
  if(x > 0 && y >= 0){
      arg = atan(y / x);
    } else if(x < 0 && y >= 0){
      arg = M_PI - atan(fabs(y / x));
    } else if(x < 0 && y < 0){
      arg = M_PI + atan(fabs(y / x));
    } else if(x > 0 && y < 0){
      arg = 2 * M_PI - atan(abs(double(y) / double(x)));
    } else if (x == 0 && y > 0) {
      arg = M_PI / 2;
    } else if (x == 0 && y < 0) {
      arg = 3 * M_PI / 2;
    }
  else {
      arg = 0;
      resultLine->setText("Error");
    }
  resultLine->setText(QString::number(r) + "(cos(" + QString::number(arg) + ") + i*sin(" + QString::number(arg) + "))" );
}

double Complex::getReal(){
  return real;
}
double Complex::getImagine(){
  return imagine;
}

void Complex::setReal(double a){
  real = a;
}
void Complex::setImagine(double a){
  imagine = a;
}

void Complex::setAll(double a, double b)
{
  real = a;
  imagine = b;
}
