#include <stdio.h>

int main(void) {
	double x, y, z;
	printf("Enter x and y and z\n");
	scanf_s("%lf %lf %lf", &x, &y, &z);
	double max1=5.65, max2 = 0, min1 = 0;
	if (x >= 5.65 && x >= y) {
		max1 = x;
	}
	else if (y >= 5.65 && y >= x) {
		max1 = y;
	}

	if (y >= z) {
		max2 = y;
	}
	else {
		max2 = z;
	}

	double z4 = z - 4;
	if (x <= y && x <= z4) {
		min1 = x;
	}
	if (y <= x && y <= z4) {
		min1 = y;
	}
	if (z4 <= x && z4 <= y) {
		min1 = z4;
	}

	printf("%lf", (max1 + (x * max2)) / (((x * x) * (y * y * y)) + ((z * z * z * z) - min1)));
	return 0;
}
