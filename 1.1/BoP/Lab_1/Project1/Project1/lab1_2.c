#include <stdio.h>

int main(void) {
	double x, y, z;
	printf("enter x and y and z");
	scanf_s("%lf %lf %lf", &x, &y, &z);
	double max1, max2 = 0, min1 = 0;
	if (x > y > 5.65) {
		max1 = x;
	}
	if (y > x > 5.65) {
		max1 = y;
	}
	if (5.65 > x > y) {
		max1 = 5.65;
	}
	printf("%lf", max1);
}