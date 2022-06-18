#include <stdio.h>

#define N 3

void sum(double x[], double y[], double z[]) {
	for (int i = 0; i < N; i++) {
		z[i] = x[i] + y[i];
	}
}

void enter(double *vector) {
	printf("Enter %d numbers: ", N);
	scanf_s("%lf %lf %lf", &vector[0], &vector[1], &vector[2]);
}

int main(void){
	double a[N], b[N], c[N], d[N];

	printf("Enter a:\n");
	enter(a);
	printf("Enter b:\n");
	enter(b);
	printf("Enter c:\n");
	enter(c);

	sum(a, b, d);
	sum(c, d, d);

	printf("Vector d: ");
	for (int i = 0; i < N; i++) {
		printf("%g ", d[i]);
	}
}