#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	int rows, columns, n;
	printf("Enter number of rows:");//рядки
	scanf_s("%d", &rows);
	printf("Enter number of columns:");//стовпці
	scanf_s("%d", &columns);
	retry:
	printf("Enter number of column for sum:");//шуканий стовпець
	scanf_s("%d", &n);
	if (n > columns) {
		printf("Wrong number of column for sum, try again\n");
		goto retry;
	}

	int** pointer2DArray = NULL;//створення масиву в динамічній пам'яті
	pointer2DArray = (int**)calloc(rows, sizeof(int));
	for (int i = 0; i < rows; ++i)
	{
		pointer2DArray[i] = (int*)calloc(columns, sizeof(int));
	}

	srand(time(NULL));
	for (int i = 0; i < rows; ++i)//введення масиву
	{
		for (int j = 0; j < columns; ++j) {
			*(*(pointer2DArray + i) + j) = rand() % 16;
			printf("%d\t", *(*(pointer2DArray + i) + j));
		}
		printf("\n");
	}
	printf("\n");

	int sum = 0;
	for (int i = 0; i < rows; i++) //визначення суми
	{
		sum += *(*(pointer2DArray + i) + (n-1));
		printf("%d", *(*(pointer2DArray + i) + (n-1)));
		if (!(i == rows-1)) {
			printf(" + ");
		}
	}
	printf(" = %d\n", sum);

	for (int i = 0; i < rows; ++i) //очищення пам'яті
	{
		if (pointer2DArray) {
		free(*(pointer2DArray+i));
		}
	}
	free(pointer2DArray);
	pointer2DArray = NULL;

	return 0;
}