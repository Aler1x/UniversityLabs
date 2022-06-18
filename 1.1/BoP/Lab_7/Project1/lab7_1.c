#include "Includer.h"

char isSortedAsc(int[], int);
char areEqual(int[], int[], int);

int main(void) {
	double tm1, tm2;
	int mas1[MAS], mas2[MAS], i;
	srand(time(NULL));
	for (i = 0; i < MAS; i++)
	{
		mas1[i] = rand();
		mas1[i] *= rand();
		mas2[i] = mas1[i];
	}

	printf("Arrays are %sequal before sorting.\n", (areEqual(mas1, mas2, MAS) ? "" : "not"));

	tm1 = clock() / (float)CLOCKS_PER_SEC;
	qs_sort(mas1, 0, MAS - 1);
	tm2 = clock() / (float)CLOCKS_PER_SEC;

	printf("First array is %s. Quick-sorting took %.3f seconds.\n", (isSortedAsc(mas1, MAS) ? "sorted" : "not sorted"), (tm2 - tm1));

	tm1 = clock() / (float)CLOCKS_PER_SEC;
	bubblesort(mas2);
	tm2 = clock() / (float)CLOCKS_PER_SEC;

	printf("Second array is %s. Bubble-sorting took %.3f seconds.\n", (isSortedAsc(mas2, MAS) ? "sorted" : "not sorted"), (tm2 - tm1));
	printf("Arrays are %sequal after sorting.\n", (areEqual(mas1, mas2, MAS) ? "" : "not "));

	/*for (int i = 0; i < MAS; i++) {
		printf("%d\n", mas2[i]);
	}*/

	return 0;
}

char isSortedAsc(int mas[], int sz)
{
	for (int i = 1; i < sz; i++)
		if (mas[i - 1] < mas[i])
			return 0;

	return 1;
}

char areEqual(int mas1[], int mas2[], int sz)
{
	for (int i = 0; i < sz; i++)
		if (mas1[i] - mas2[i])
			return 0;

	return 1;
}