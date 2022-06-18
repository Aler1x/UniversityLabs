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

	double verh1, verh, nuz1, nuz2, nuz, stx, sty, stz, u;
	verh1 = x * max2;
	verh = max1 + verh1;
	stx = x * x;
	sty = y * y * y;
	stz = z * z * z * z;
	nuz1 = stx * sty;
	nuz2 = stz - min1;
	nuz = nuz1 + nuz2;
	u = verh / nuz;
	printf("%lf", u);
	return 0;
}