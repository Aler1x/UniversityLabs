#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

double f(double x) {
	return (1 + (2 * x)) / pow(log(2 + pow(x, 2)), 2);
}

double LeftRectangles(double a, double b, int n) {
	double res = 0;
	double h = (b - a) / n;
	for(int i = 0; i < n; i++) {
		res += f(a + (i * h));
	}
	return res * h;
}

double RightRectangles(double a, double b, int n) {
	double res = 0;
	double h = (b - a) / n;
	for(int i = 1; i <= n; i++) {
		res += f(a + (i * h));
	}
	return res * h;
}

double MiddleRectangles(double a, double b, int n) {
	double res = 0;
	double h = (b - a) / n;
	for(int i = 0; i < n; i++) {
		res += f(a + (i * h) + (h/2));
	}
	return res * h;
}

double TrapezeMethod(double a, double b, int n) {
	double res = (f(a) + f(b)) / 2;
	double h = (b - a) / n;
	for(int i = 0; i < n; i++) {
		res += f(a + (i * h));
	}
	
	return res * h;
}

double GomerSimpsonMethod(double a, double b, int n) {
	double h = (b - a) / n;
	double res = 0, tmp, x = a, n_pair = 0, pair = 0;

	res += f(x);
	x += h;

	for(int i = 1; i <= n; ++i) {
		if(i == n) {
			res += f(x);
		} else {
			tmp = f(x);

			if(!(i % 2)) {
				pair += tmp;
			} else {
				n_pair += tmp;
			}
		}
		x += h;
	}
	res += 4 * n_pair + 2 * pair;
	return res * h / 3;
}

int main() {

	cout << "[ Numerical Methods Of Integration ]" << endl << endl
		 << "  / 4      1 + 2x" << endl
		 << "  |   ----------------- dx;" << endl
		 << "0 /    ln^2(2 + (x^2))" << endl;

	double a = 0, b = 4, e = 0;

	cout << endl << "Enter accuracy:" << endl;
	cin >> e;

	double res_prev, res_next;

	int h_prev = (b - a) / sqrt(e);
	int h_next;

	//======================================================================//

	do {
		res_prev = LeftRectangles(a, b, h_prev);
		h_next = h_prev * 2;
		res_next = LeftRectangles(a, b, h_next);
		h_prev = h_next;
	} while(fabs(res_prev - res_next) > e);

	cout << endl << "=====[ Left Rectangles Method ]=====" << endl
		 << "n = " << h_next << endl
		 << "Result = " << res_next << endl;

	//======================================================================//

	h_prev = (b - a) / sqrt(e);

	do {
		res_prev = RightRectangles(a, b, h_prev);
		h_next = h_prev * 2;
		res_next = RightRectangles(a, b, h_next);
		h_prev = h_next;
	} while(fabs(res_prev - res_next) > e);

	cout << endl << "=====[ Right Rectangles Method ]====" << endl
		<< "n = " << h_next << endl
		<< "Result = " << res_next << endl;

	//======================================================================//

	h_prev = (b - a) / sqrt(e);

	do {
		res_prev = MiddleRectangles(a, b, h_prev);
		h_next = h_prev * 2;
		res_next = MiddleRectangles(a, b, h_next);
		h_prev = h_next;
	} while(fabs(res_prev - res_next) > e);

	cout << endl << "====[ Middel Rectangles Method ]====" << endl
		<< "n = " << h_next << endl
		<< "Result = " << res_next << endl;

	//======================================================================//

	h_prev = (b - a) / sqrt(sqrt(e));
	
	do {
		res_prev = TrapezeMethod(a, b, h_prev);
		h_next = h_prev * 2;
		res_next = TrapezeMethod(a, b, h_next);
		h_prev = h_next;
	} while(fabs(res_prev - res_next) > e);

	cout << endl << "=========[ Trapeze Method ]=========" << endl
		<< "n = " << h_next << endl
		<< "Result = " << res_next << endl;

	//======================================================================//

	h_prev = (b - a) / sqrt(sqrt(e));

	do {
		res_prev = GomerSimpsonMethod(a, b, h_prev);
		h_next = h_prev * 2;
		res_next = GomerSimpsonMethod(a, b, h_next);
		h_prev = h_next;
	} while(fabs(res_prev - res_next) > e);

	cout << endl << "=========[ Simpson Method ]=========" << endl
		<< "n = " << h_next << endl
		<< "Result = " << res_next << endl;

	//======================================================================//

	return 0;
}
