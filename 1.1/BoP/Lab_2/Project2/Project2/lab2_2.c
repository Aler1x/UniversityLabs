#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, step, e;
    printf("Please, enter A, B, step, eps: ");
    scanf_s("%lf %lf %lf %lf", &a, &b, &step, &e);
    double delta, num, denum, result;
    //int i = 0;
    double drob = -0.25;
    for (double x = a; x <= b; x += step) {
        result = 1;
        delta = 1;
        num = 1;
        denum = 1; 
        //i++;
        if (fabs(x) < 1){
            int i = 0;
            for (int y = 1; y == 1 || fabs(delta) > e; y++) {
                
                num = (y * 4.0 - 3.0) * num;
                denum = (y * 4.0) * denum;
                delta = (pow(x, y) * num) / denum;

                if (y % 2 == 0) {
                    result += delta;
                }
                else {
                    result -= delta;
                }
                i++;
            }
            double function, mfunction = 1 + x;
            if (mfunction == 0) {
                function = 0;
            }
            else {
                function = pow(1 + x, drob);
            }
            printf(" X =%1.3lf | (1+x)^2 = %1.3lf | teylor =  %1.3lf | delta = %1.3lf | iteration = %d \n", x, function, result, fabs(function - result), i);
        }
    }
}