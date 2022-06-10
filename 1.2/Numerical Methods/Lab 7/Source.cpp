/*
*	Variant 2
* cos(x - 1) + y = 0.5
* x - cos(y) = 3
* 
*	Variant 1
* sin(x + 1) - y = 1.2
* 2x + cos(y) = 2
*/

#include "Header.h"

#define eps 0.001

using namespace std;

double det(double a[2][2]) {
	return (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);
}

bool isConvergence(double x, double y) {
	return (fabs(der_f1_x(x)) + fabs(der_f2_x()) < 1 && fabs(der_f1_y()) + fabs(der_f2_y(y)) < 1);
}

void IterationMethod() {
	cout << "=====[ Simple Iteration Method ]=====" << endl;

	double x = 3, y = 1;
	double prev_x, prev_y;
	int iter = 0;

	if(isConvergence(x, y)) {
		cout << "Error, equation not covergence" << endl;
		return;
	}

	cout << "|Iter|       X       |       Y      |" << endl;
	do {

		++iter;
		prev_x = x;
		prev_y = y;

		y = f1_x(prev_x);
		x = f2_y(prev_y);

		cout << "|" << setw(4) << iter << "|" << setw(15) << x << "|" << setw(14) << y << "|" << endl;
	} while((fabs(x - prev_x) + fabs(y - prev_y)) > eps);

	cout << "=====================================" << endl << "Result:\n[X] = " << x << "\n[Y] = " << y << endl;
}

double Jacobi(double x, double y) {
	double a[2][2];

	a[0][0] = der_f1_x(x);
	a[0][1] = der_f1_y();
	a[1][0] = der_f2_x();
	a[1][1] = der_f2_y(y);

	return det(a);
}

double Dx(double x, double y) {
	double a[2][2];

	a[0][0] = f1_xy(x, y);
	a[0][1] = der_f1_y();
	a[1][0] = f2_xy(x, y);
	a[1][1] = der_f2_y(y);

	return det(a);
}

double Dy(double x, double y) {
	double a[2][2];

	a[0][0] = der_f1_x(x);
	a[0][1] = f1_xy(x, y);
	a[1][0] = der_f2_x();
	a[1][1] = f2_xy(x, y);

	return det(a);
}

void NewtonMethod() {
	double x0 = 3, y0 = 1;
	if(Jacobi(x0, y0) == 0) {
		cout << "Error: Jacobi determinant = 0" << endl;
		return;
	} else {
		cout << endl << "==========[ Newton Method ]==========" << endl;
		cout << "|Iter|       X       |       Y      |" << endl;

		double x1 = x0 - (Dx(x0, y0) / Jacobi(x0, y0));
		double y1 = y0 - (Dy(x0, y0) / Jacobi(x0, y0));
		int iter = 1;

		cout << "|" << setw(4) << iter << "|" << setw(15) << x1 << "|" << setw(14) << y1 << "|" << endl;

		do {
			++iter;
			x0 = x1;
			y0 = y1;
			x1 = x0 - (Dx(x0, y0) / Jacobi(x0, y0));
			y1 = y0 - (Dy(x0, y0) / Jacobi(x0, y0));

			cout << "|" << setw(4) << iter << "|" << setw(15) << x1 << "|" << setw(14) << y1 << "|" << endl;

		} while((fabs(x1 - x0) + fabs(y1 - y0)) > eps);

		cout << "=====================================" << endl << "Result:\n[X] = " << x1 << "\n[Y] = " << y1 << endl;
	}
}

int main() {
	IterationMethod();
	NewtonMethod();
	return 0;
}