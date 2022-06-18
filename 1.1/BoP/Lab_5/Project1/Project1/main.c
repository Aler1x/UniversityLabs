#include <stdio.h>
#include <math.h>
#include "prototypes.h"
// work from 0 to ln(2)
int main(void) {

	double x, b, h;//a = x
	printf("Please enter step: ");
	scanf_s("%lf", &h);
	b = log(2);
	tabulation(h);
	
	return 0;
}