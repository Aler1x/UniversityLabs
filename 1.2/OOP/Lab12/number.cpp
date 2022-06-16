#include "number.h"

std::string Number::toHex(){
	std::stringstream hexstr;
	hexstr << std::hex << this->m_data;
	return hexstr.str();
}
std::string Number::toDec(){
	return std::to_string(m_data);
}
std::string Number::toBin(){
	return (std::bitset<8>{static_cast<unsigned long long>(m_data)}).to_string();
}

void Number::fromHex(const std::string &str){
		std::stringstream hexstr;
		hexstr << str;
		hexstr >> std::hex >> this->m_data;
}
void Number::fromDec(const std::string &str){
	if(QString::fromStdString(str).contains(m_CheckDecimalData)) {
		throw 1;
	}
	this->m_data = std::stoi(str);
}
void Number::fromDec(int &num){
	this->m_data = num;
}

unsigned long fromBin(unsigned long n)
{
	unsigned long factor = 1;
	unsigned long total = 0;

	while (n != 0)
	{
		total += (n%10) * factor;
		n /= 10;
		factor *= 2;
	}

	return total;
}

void Number::fromBinary(const std::string &str){
	if(QString::fromStdString(str).contains(m_CheckBinaryData)){
		throw 1;
	}
	unsigned long ui = std::stoi(str);
	qDebug() << ui;
	this->m_data = fromBin(ui);
	qDebug() << this->m_data;
}


Number operator+(const Number a, const Number b){
	return Number(a.m_data + b.m_data);
}
Number operator-(const Number a, const Number b){
	return Number(a.m_data - b.m_data);
}
Number operator*(const Number a, const Number b){
	return Number(a.m_data * b.m_data);
}
Number operator/(const Number a, const Number b){
	if(b.m_data == 0) {
		throw 1.1;
	}
	return Number(a.m_data / b.m_data);
}

Number & Number::operator+=(const Number &a){
	this->m_data = this->m_data + a.m_data;
	return *this;
}
Number & Number::operator-=(const Number &a){
	this->m_data = this->m_data - a.m_data;
	return *this;
}
Number & Number::operator*=(const Number &a){
	this->m_data = this->m_data * a.m_data;
	return *this;
}
Number & Number::operator/=(const Number &a){
	if(a.m_data == 0) {
		throw 1;
	}
	this->m_data = this->m_data / a.m_data;
	return *this;
}

Number & Number::operator=(const Number &a){
	this->m_data = a.m_data;
	return *this;
}
Number & Number::operator=(int &num){
	m_data = num;
	return *this;
}
