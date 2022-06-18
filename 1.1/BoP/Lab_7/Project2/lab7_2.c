#include <stdio.h>
#include <math.h>

double data(double);
void tabulationWithFor(double, double, double);
void tabulationWithWhile(double, double, double);
void tabulationWithDoWhile(double, double, double);
void (*getResult) (double, double, double);

int main(void) {
    double a = 0, b = log(2), step;
    int option;
    printf("Enter step: ");
    scanf_s("%lf", &step);

    printf("Choose tabulation type (1 - for, 2 - while, 3 - do...while): ");
    scanf_s("%d", &option);

        switch (option)
        {
        case 1:
            getResult = &tabulationWithFor;
            break;
        case 2:
            getResult = &tabulationWithWhile;
            break;
        case 3:
            getResult = &tabulationWithDoWhile;
            break;
        default:
            break;
        }

        getResult(a, b, step);
}

double data(double x) {
    return x * exp(-x);
}

void tabulationWithFor(double a, double b, double step) {
    printf("Tabulation type: for\n");
    printf("|  x  |  f(x) |\n");
    for (double x = a; x < b; x+= step)
    {
        printf("|%0.3lf|%0.5lf|\n", x, data(x));
    }
}
void tabulationWithWhile(double a, double b, double step) {
    printf("Tabulation type: while\n");
    printf("|  x  |  f(x) |\n");
    double x = a;
    while (x <= b) {
        printf("|%0.3lf|%0.5lf|\n", x, data(x));
        x += step;
    }
}
void tabulationWithDoWhile(double a, double b, double step) {
    printf("Tabulation type: do.....while\n");
    printf("|  x  |  f(x) |\n");
    double x = a;
    do {
        printf("|%0.3lf|%0.5lf|\n", x, data(x));
        x += step;
    } while (x<b);
}