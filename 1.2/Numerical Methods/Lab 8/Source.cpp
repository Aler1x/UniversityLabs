#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

#define ArraySize 10
using namespace std;

int factorial(int n) {
	if(!n)
		return 1;
	return factorial(n - 1) * n;
}

void Lagrange(vector<double> &X, vector<double> &Y, double x) {
	cout << "[ Polinom Lagrange ]" << endl;

	double result = 0;
	for(int i = 0; i < X.size(); i++) {

		double numerator = 1; // чисельник
		double denominator = 1; // знаменник

		for(int j = 0; j < X.size(); j++) {
			if(i != j) {
				numerator *= x - X[j];
				denominator *= X[i] - X[j];
			}
		}

		result += (numerator / denominator) * Y[i];
		
	}
	cout << endl << "[ " << setprecision(6) << "Result: " << result << " ]" << endl;
}

void Newton(vector<double> &X, vector<double> &Y, double X0) {
	cout << endl << endl << "================================[ Polinom Newthon ]================================" << endl;
	cout << " d1_f(x)  d2_f(x)  d3_f(x)  d4_f(x)  d5_f(x)  d6_f(x)  d7_f(x)  d8_f(x)  d9_f(x)" << endl;

	double result = Y[0];
	double h = X[1] - X[0];
	double DY[ArraySize][ArraySize] = { 0 };

	//Заповнення таблиці скінченних різниць
	for(int i = 0; i < ArraySize; i++) {
		DY[i][0] = Y[i];
	}

	for(int i = 1; i < ArraySize; i++) {
		for(int j = 0; j < ArraySize - 1; j++) {
			if(j < ArraySize - i) {
				DY[j][i] = DY[j + 1][i - 1] - DY[j][i - 1];
				cout << showpos << fixed << setprecision(4) << setw(8) << DY[j][i] << " " << noshowpos;
			} else {
				cout << "   ---   ";
			}
		}
		cout << endl;
	}
	//таблиця заповнена та виведена


	for(int i = 1; i < ArraySize; i++) {
		double numerator = DY[0][i];
		double denominator = factorial(i);

		for(int j = 0; j < i; j++) {
			numerator *= X0 - X[j];
			denominator *= h;
		}
		result += numerator / denominator;

	}
	cout << endl << "================================[ " << setprecision(5) << "Result: " << result << " ]================================" << endl;
}

int main() {
	vector<double> X = { 0.101, 0.106, 0.111, 0.116, 0.121, 0.126, 0.131, 0.136, 0.141, 0.146 };
	vector<double> Y = { 1.261, 1.276, 1.291, 1.306, 1.321, 1.336, 1.352, 1.367, 1.383, 1.399 };
	
	cout << "==============================[ Tabular function V2 ]==============================\n" <<
			"X | 0.101 | 0.106 | 0.111 | 0.116 | 0.121 | 0.126 | 0.131 | 0.136 | 0.141 | 0.146 |\n" <<
			"Y | 1.261 | 1.276 | 1.291 | 1.306 | 1.321 | 1.336 | 1.352 | 1.367 | 1.383 | 1.399 |\n" <<
			"===================================================================================" << endl << endl;

	double X0 = 0.1102;
	Lagrange(X, Y, X0);
	Newton(X, Y, X0);
	return 0;
}