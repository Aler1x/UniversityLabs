#include "prototypes.h"
#include <math.h>
#define e 2.71828

double formula1(double x) {
	return x * exp(-x);
}

int formula2(double x, double *y) {
	*y = x * exp(-x);

	if (*y < 0) {
		return -1;
	}
	else if (*y == 0) {
		return 0;
	}
	else if (*y > 0) {
		return 1;
	}
	return 2;
}

void tabulation(double h, double b) {
	printf("|     x      |first_method|second_method|\n");
	for (double x = 0; x <= b; x += h) {
		if (x < 0) { break; }
	double y;
	int res = formula2(x, &y);
	printf("| x = %.4lf | y = %.4lf |    z = %d    |\n", x, formula1(x), res);
	}
	
}