#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAS 100000

#ifndef QSORT_H
#define QSORT_H

void swap(int array[], long pos1, long pos2);

void qs_sort(int array[], long start, long end);

#endif; // !QSORT_H

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

void bubblesort(int* array);

#endif; // !BUBBLESORT_H