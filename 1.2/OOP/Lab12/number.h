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
		Number():
		m_CheckBinaryData("[01]"),
		m_CheckDecimalData("[0-9]"),
		m_CheckHeximalData("[A-Za-z0-9]")
		{
			m_data = 0;
		}
		Number(int num):
			m_CheckBinaryData("[01]"),
			m_CheckDecimalData("[0-9]"),
			m_CheckHeximalData("[A-Za-z0-9]") {
			m_data = num;
		}

		std::string toHex();
		std::string toDec();
		int getDec();
		std::string toBin();

		void fromHex(const std::string &str);
		void fromDec(const std::string &str);
		void fromDec(int &num);
		void fromBinary(const std::string &str);

		friend Number operator+(const Number &a, const Number &b);
		friend Number operator-(const Number &a, const Number &b);
		friend Number operator*(const Number &a, const Number &b);
		friend Number operator/(const Number &a, const Number &b);

		Number & operator+=(const Number &a);
		Number & operator-=(const Number &a);
		Number & operator*=(const Number &a);
		Number & operator/=(const Number &a);

		Number & operator=(const Number &a);
		Number & operator=(int &num);
};

#endif // NUMBER_H
