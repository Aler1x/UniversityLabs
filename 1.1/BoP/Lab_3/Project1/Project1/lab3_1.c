#include <stdio.h>
#define SIZE 10

int main(void) {

	int size;
	printf("Enter vector size:");
	scanf_s("%d", &size);
	if (size <= -1) {
		printf("Not a valid size");
		return 0;
	}

	double vector[SIZE] = { 0 };
	printf("Enter %d elements:\n", size);//введення значень в вектор
	for (int i = 0; i < size; i++) {
		int read = scanf_s("%lf", (vector+i));
	}

	double average = 0;//обрахунок середнього значення
	for (int i = 0; i < size; i++)
	{
		average += vector[i];
	}
	average /= size;

	for (int i = 0; i < size; i++)//основні дії
	{
	 if (vector[i] < average)
	 {
		 vector[i] *= 1.7;
	 }
	 if(vector[i] == 0)
	 {
		 vector[i] = average;
	 }
	}
	printf("result: ");//вивід вектора
	for (int i = 0; i < size; i++)
	{
		printf("%1.3f, ", *(vector+i));
	}
	return 0; 
}