#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10

int main(void)
{
    int rowCount = MAX_SIZE, columnCount = MAX_SIZE;

    printf("Enter count of rows and columns: ");//введення розміру матриці
    scanf_s("%d %d", &rowCount, &columnCount);

    float matrix[MAX_SIZE][MAX_SIZE] = { 0 };

    int nullCount = 0;
    int maxNullCountRow = 0;

    for (int row = 0; row < rowCount; row++)//введення значень матриці
    {
        int zerocount = 0;
        
        for (int column = 0; column < columnCount; column++)
        {
            printf("Enter element for %d %d position: ", row + 1, column + 1);
            scanf_s("%f", *(matrix + row) + column);

            if (matrix[row][column] == 0) zerocount++;//підрахунок нулів в кожному рядку
        }

        if (zerocount > nullCount) //порявняння нулів
        {
            nullCount = zerocount;
            maxNullCountRow = row;
        }
    }

    printf("Before sorting:\n");//вивід несортованої матриці
    for (int row = 0; row < rowCount; row++)
    {
        for (int column = 0; column < columnCount; column++)
        {
            printf("%1.2f\t", matrix[row][column]);
        }
        printf("\n\n");
    }

    for (int column = 0; column < columnCount; ++column)//зміна значень матриці
    {
        const double row_swap_temp = matrix[maxNullCountRow][column];
        matrix[maxNullCountRow][column] = matrix[0][column];
        matrix[0][column] = row_swap_temp;
    }

    printf("After sorting:\n");//вивід зміненої матриці
    for (int row = 0; row < rowCount; row++)
    {
        for (int column = 0; column < columnCount; column++)
        {
            printf("%1.2lf\t", *(*(matrix + row) + column));
        }
        printf("\n\n");
    }

    return 0;
}