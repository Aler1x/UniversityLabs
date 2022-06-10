//(x*x*x) - 6*x - 8 = 0
//3*x*x - 6  = 0
//6*x = 0;

//x^3 - 6x - 8 = 0

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>

double f(double x);
double fp(double x);
double fpp(double x);
double fi(double x, double a, double b);

void retryInput();

void NewtonMethod(double n, double m, double eps);
void IterationMethod(double a, double b, double eps);

int main() {

	std::cout << "Here we have an Expression: x^3 - 6x - 8 = 0\n" << "Now you have to enter a limits and eps\n" << "Expression has 1 root between (2; 3)\n";

	double a = 0, b = 0, eps = 0;
	while (1){
		printf("Enter Eps:");
		while (scanf("%lf", &eps) != 1 && eps <= 0){
			retryInput();
			printf("Wrong input\ntry again:");
		}
		printf("Enter A:");
		while (scanf("%lf", &a) != 1){
			retryInput();
			printf("Wrong input\nTry again:");
		}
		printf("Enter B:");
		while (scanf("%lf", &b) != 1){
			retryInput();
			printf("Wrong input\nTry again:");
		}
		if ((f(a) * f(b)) >= 0 || fabs(a - b) < eps){
			printf("Limits not correct\nTry again\n");
		}
		else{
			break;
		}
	}
	if (f(a) * fpp(a) > 0) {
		NewtonMethod(a, b, eps);
	}
	else if(f(b) * fpp(b) > 0) {
		NewtonMethod(b, a, eps);
	}
	IterationMethod(a, b, eps);
	return 0;
}

double f(double x) {
	return ((x * x * x) - (6 * x) - 8);
}

double fp(double x) {
	return ((3 * x * x) - 6);
}

double fpp(double x) {
	return 6 * x;
}

void retryInput(){
	while (getchar() != '\n');
}

void NewtonMethod(double n, double m, double eps) {
	double x = n;
	double xi = x;
	x = xi - (f(xi)) / (fp(xi));
	int i = 1;
	//printf("|   X    |   f(x)  |\n";
	while (fabs(xi - x) > eps) {
		xi = x;
		x = xi - (f(xi)) / (fp(xi));
		i++;
		//printf("| %.3lf | %.3lf |\n", x, f(x));
	}
	printf("\tNewton Method\n\tSolution\n\n  X  = \t%.10lf\nf(x) =\t%.10lf \nIteration = %d\n", x, f(x), i);
}

void IterationMethod(double a, double b, double eps) {
	double x = b, xi = fi(x, a ,b);
	int i = 1;

	//printf("|   X    |   f(x)  |\n";
	while (fabs(xi - x) >= eps) {
		//printf("| %.3lf | %.3lf |\n", xi, f(xi));
		x = xi;
		xi = fi(x, a ,b);
		i++;
	}
	printf("\tIteration Method\n\tSolution\n\n  X  = \t%.10lf\nf(x) =\t%.10lf \nIteration = %d\n", xi, f(xi), i);
}

double fi(double x, double a, double b) {

	double k;
	if ( a >= 0 && b >= 0) {
		k = fp(b) / 2;
	}
	else if(a <= 0 && b <= 0) {
		k = -1 * fp(b) / 2;
	}
	else {
		if (a <= 0) {
			a = 0;
		}
		else {
			b = 0;
		}
		k = fp(b) / 2;
	}
	return (x - (f(x) / k));
}