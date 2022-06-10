//(x*x*x) - 6*x - 8 = 0
//3*x*x - 6  = 0
//6*x = 0;
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>

double f(double x);
void retryInput();
void divideMethod(double a, double b, double eps);
void chordMethod(double a, double b, double eps);

int main() {
	std::cout << "Here we have an Expression: x^3 - 6*x - 8 = 0\n" << "Now you have to enter a limits and eps\n" << "Expression has 1 root between (2,5; 3)\n";
	double a=0, b=0, eps=0;
	while (1)
	{
		printf("Enter EPS:");
		while (scanf("%lf", &eps) != 1 || eps<= 0)
		{
			retryInput();
			printf("Wrong input\nTry again:");
		}
		printf("Enter A:");
		while (scanf("%lf", &a) != 1)
		{
			retryInput();
			printf("Wrong input\nTry again:");
		}
		printf("Enter B:");
		while (scanf("%lf", &b) != 1)
		{
			retryInput();
			printf("Wrong input\nTry again:");
		}
		if ((f(a) * f(b)) > 0 || fabs(a-b) < eps)
		{
			printf("Limits not correct\nTry again\n");
		}
		else
		{
			break;
		}
	}
	divideMethod(a, b, eps);
	chordMethod(a, b, eps);
	return 0;
}

double f(double x) {
	return ((x * x * x) - (6 * x) - 8);
}

double fpp(double x) {
	return 6 * x;
}

void retryInput()
{
	while (getchar() != '\n');
}

void divideMethod(double a, double b, double eps) {
	int i = 0;
	double x = 0;
	std::cout << "\tDivide method\n";// << "I\t A\t B\t X\t f(x)\n";

	while (fabs(a - b) >= eps && f(x) != 0) {
		x = (a + b) / 2;
		//printf("%2d %7lf %7lf %7lf %7lf\n", i, a, b, x, f(x));
		if ((f(a) * f(x)) < 0){
			b = x;
		}
		else{
			a = x;
		}
		i++;
	}
	printf("\tSolution:\nX = %10lf\nf(x) = %10lf\n\tIteration:\nI = %d\n\n", x, f(x), i);
	return;
}

void chordMethod(double a, double b, double eps) {
	int i = 0;

	if (f(a) * fpp(a) > 0) {
		double x = (a - (a - b) * f(a)) / (f(a) - f(b));

		std::cout << "\tChord method\n";// << "I\t A\t B\t X\t f(x)\n";

		while (fabs(x - b) > eps && f(x) != 0) {
			i++;
			b = x;
			x = (a - (a - b) * f(a)) / (f(a) - f(b));
			//printf("%2d %7lf %7lf %7lf %7lf\n", i, a, b, x, f(x));
		}
	}
	else {
		double x = b - (b - a) * f(b) / (f(b) - f(a));

		std::cout << "\tChord method\n";// << "I\t A\t B\t X\t f(x)\n";

		while (fabs(x - a) > eps && f(x) != 0) {
			i++;
			a = x;
			x = (b - (b - a) * f(b)) / (f(b) - f(a));
			//printf("%2d %7lf %7lf %7lf %7lf\n", i, a, b, x, f(x));
		}
	}
	printf("\tSolution:\nX =\t%10lf\nf(x) =\t%10lf\n\tIteration:\nI = %d\n", a, f(a), i);
	return;
}

