#ifndef NUMBER_H
#define NUMBER_H

#include <QRegularExpression>

#include <string>
#include <sstream>
#include <iostream>
#include <bitset>

class Number
{
	private:
		int m_data;

		QRegularExpression m_CheckBinaryData;
		QRegularExpression m_CheckDecimalData;
		QRegularExpression m_CheckHeximalData;

	public:
		Number() : m_data(),
		m_CheckBinaryData("[A-Z2-9]"),
		m_CheckDecimalData("[A-Z]") {};


		Number(int num) : m_data(num),
			m_CheckBinaryData("[A-Z2-9]"),
			m_CheckDecimalData("[A-Z]") {};

		Number(Number &n) :
			m_CheckBinaryData("[A-Z2-9]"),
			m_CheckDecimalData("[A-Z]]")
		{
			this->m_data = n.m_data;
		}


		std::string toHex();
		std::string toDec();
		int getDec();
		std::string toBin();

		void fromHex(const std::string &str);
		void fromDec(const std::string &str);
		void fromDec(int &num);
		void fromBinary(const std::string &str);

		friend Number operator+(const Number a, const Number b);
		friend Number operator-(const Number a, const Number b);
		friend Number operator*(const Number a, const Number b);
		friend Number operator/(const Number a, const Number b);

		Number & operator+=(const Number &a);
		Number & operator-=(const Number &a);
		Number & operator*=(const Number &a);
		Number & operator/=(const Number &a);

		Number & operator=(const Number &a);
		Number & operator=(int &num);
};

#endif // NUMBER_H
