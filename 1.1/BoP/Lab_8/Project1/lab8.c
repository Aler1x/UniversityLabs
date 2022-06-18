#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STANDARD_STRING_LENGHT 100

struct Book
{
    char author[STANDARD_STRING_LENGHT];
    char name[STANDARD_STRING_LENGHT];
    int year;
    int pageCount;
    double price;
}Books[14];

void sort_by_name(struct Book Books[], int n) {
    struct Book tempName;
    for (int i = 1; i < n; i++) {
        for(int j = 0; j <= n-1; j++){
            if (0 < strcmp(Books[i].name, Books[j].name)) {
                tempName = Books[i];
                Books[i] = Books[j];
                Books[j] = tempName;
            }
        }

    }
}

void sort_by_year(struct Book Books[], int n) {
    struct Book tempYear;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= n - 1; j++) {
            if (Books[i].year < Books[j].year) {
                tempYear = Books[i];
                Books[i] = Books[j];
                Books[j] = tempYear;
            }
        }
    }
}


int main(void) {

    int booksCount = 0;
    char* scanner;
    char str[STANDARD_STRING_LENGHT];

    FILE* file;
    //if (!(file = fopen("./Lab_8/Project1/database.txt", "rt"))) {
    if (!(file = fopen("database.txt", "rt"))) {
        printf("Input data error");
        return 1;
    }

    while (fgets(str, STANDARD_STRING_LENGHT, file))
    {
        scanner = strtok(str, "\t");
        strcpy(Books[booksCount].author, scanner);
        scanner = strtok(NULL, "\t");
        strcpy(Books[booksCount].name, scanner);
        scanner = strtok(NULL, "\t");
        Books[booksCount].year = strtol(scanner, &scanner, 10);
        scanner = strtok(NULL, "\t");
        Books[booksCount].pageCount = strtol(scanner, &scanner, 10);
        scanner = strtok(NULL, "\t");
        Books[booksCount].price = strtol(scanner, &scanner, 10);
        booksCount++;
    }
    fclose(file);

    sort_by_name(Books, booksCount);

    printf("\tAuthor\t\t\t Name\t\t\t       Published  Pages\t  Price\n");
    for (int i = 0; i < booksCount; i++){
        printf("%-20s|% -41s| %4d\t|  %4d\t| %4.2lf |\n", Books[i].author, Books[i].name, Books[i].year, Books[i].pageCount, Books[i].price);
    }
    printf("\n");

    sort_by_year(Books, booksCount);

    printf("\tAuthor\t\t\t Name\t\t\t       Published  Pages\t  Price\n");
    for (int i = 0; i < 6; i++){
        printf("%-20s|% -41s| %4d\t|  %4d\t| %4.2lf |\n", Books[i].author, Books[i].name, Books[i].year, Books[i].pageCount, Books[i].price);
    }
return 0;
}