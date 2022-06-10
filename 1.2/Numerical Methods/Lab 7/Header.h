#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>

#define V 2

//return y from 1 equation
double f1_x(double x) {
	if(V == 2) {
		return (0.5 - cos(x - 1.0)); // y = 0.5 - cos(x - 1)
	} else {
		return (sin(x + 1) - 1.2);
	}
}

//return solve from 1 equation
double f1_xy(double x, double y) {
	if(V == 2) {
		return (cos(x - 1.0) + y - 0.5); // f(x, y) = cos(x - 1) + y - 0.5
	} else {
		return (sin(x + 1) - y - 1.2);
	}
}

double der_f1_x(double x) {
	if(V == 2) {
		return (-sin(x - 1.0));
	} else {
		return (cos(x + 1));
	}
}

double der_f1_y() {
	if(V == 2) {
		return 1.0;
	} else {
		return -1.0;
	}
}

//return x from 2 equation
double f2_y(double y) {
	if(V == 2) {
		return (3.0 + cos(y)); // x = 3 + cos(y)
	} else {
		return ((2-cos(y))/2);
	}
	
}

//return solve from 2 equation
double f2_xy(double x, double y) {
	if(V == 2) {
		return (x - cos(y) - 3.0); // f(x, y) = x - cos(y) - 3
	} else {
		return (2*x + cos(y) - 2);
	}
	
}

double der_f2_x() {
	if(V == 2) {
		return 1.0;
	} else {
		return 2.0;
	}
	
}

double der_f2_y(double y) {
	if(V == 2) {
		return sin(y);
	} else {
		return (-sin(y));
	}
}