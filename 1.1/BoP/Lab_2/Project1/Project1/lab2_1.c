#include <stdio.h>
int main(void) {
	int num = 1000, sum=0;
	while(num<=9999)
	{
			int digit1 = num / 1000;
			int digit2 = num % 1000 / 100;
			int digit3 = num % 100 / 10;
			int digit4 = num % 10;
			sum = digit1 + digit2 + digit3 + digit4;
			if (sum <= 23) { printf("number = %d\n", num); }
			num++;
	}
	return 0;
}