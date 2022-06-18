#include <stdio.h>
#include <math.h>
#define X 1.825
#define Y 18.225

int main(void) {
	printf("Enter x and y\n");
	double x, y;
	scanf_s("%lf %lf", &x, &y);

	printf("%lf\n", fabs(pow(X, Y/X) - pow(Y/X, 1.0/3.0)));
	return 0;
 }