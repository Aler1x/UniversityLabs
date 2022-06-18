#include "Includer.h"

void bubblesort(int* array)
{
    for (int c = 0; c < MAS - 1; c++)
    {
        int swapped = 0;
        for (int d = 0; d < MAS - c - 1; d++)
        {
            if (array[d] < array[d + 1])
            {
                int swap = array[d];
                array[d] = array[d + 1];
                array[d + 1] = swap;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}