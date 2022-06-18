#include <stdio.h>
#include <math.h>
#if 1
#define MAX(x, y, z) (fmax(fmax(x,y),z))
#define MIN(x, y, z) (fmin(fmin(x,y),z))
#define SQUARE(x) (x*x)

#define FIRST_LINE
//#undef FIRST_LINE
#ifndef FIRST_LINE
#define CALC_W(x, y, z) (SQUARE(MAX(x, y, z)) - 2 * MIN(x, y, z))
#else
#define CALC_W(x, y, z) (SQUARE(sin(x)) + MAX(x, y, z) / MIN(x, y, z))
#endif
#endif

int main()
{
    double x, y, z;
    printf("Enter x y z: ");
    scanf_s("%lf %lf %lf", &x, &y, &z);
    double w = CALC_W(x, y, z);
    printf("%lf\n", w);
    return 0;
}