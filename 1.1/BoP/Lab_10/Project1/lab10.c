#include "functions.h"

int main(void) {

    Book* firstBook = NULL;
    
    int chose = customerChose();

    readFromConsole(&firstBook);

    readFromFile(&firstBook);//створення "бібліотеки"

    printf("\t\t\t\t\t Before burning books\n");
    seeOnShelf(firstBook);

    firstBook = burnBooks(firstBook);

    printf("\t\t\t\t\t After burning books\n");
    seeOnShelf(firstBook);

    sellBooks(firstBook);

	return 0;
}