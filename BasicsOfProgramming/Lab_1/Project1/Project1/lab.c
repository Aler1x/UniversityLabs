#include <stdio.h>
#include <math.h>
int main(void) {
	double x, y;
	printf("Enter x and y\n");
	scanf_s("%lf %lf", &x, &y);
	double drob, stepin, korin, result, a;
	drob = y / x;
	stepin = pow(x, drob);
	korin = pow(drob, 1. / 3.);
	result = stepin - korin;
	a = fabs(result);
	printf("%lf\n", a);
	return 0;
 }