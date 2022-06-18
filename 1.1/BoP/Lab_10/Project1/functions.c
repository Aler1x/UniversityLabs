#include "functions.h"

Book *buyNewBook() {
    Book* newBook = calloc(1, sizeof(Book));
    return newBook;
}

void readFromFile(Book** firstBook) {

    char buffer[STANDARD_STRING_LENGHT];

    FILE* file;
    if (!(file = fopen("database.txt", "r")))
    {
        printf("Input error");
        return;
    }

    while (fgets(buffer, STANDARD_STRING_LENGHT, file))
    {
        Book* newBook = buyNewBook();
        strcpy(newBook->author, strtok(buffer, "\t"));
        strcpy(newBook->name, strtok(NULL, "\t"));
        char* numberBuffer = strtok(NULL, "\t");
        newBook->year = strtol(numberBuffer, &numberBuffer, 10);
        numberBuffer = strtok(NULL, "\t");
        newBook->pages = strtol(numberBuffer, &numberBuffer, 10); 
        numberBuffer = strtok(NULL, "\t");
        newBook->price = strtol(numberBuffer, &numberBuffer, 10);

        placeNewBook(firstBook, newBook);
    }  

    fclose(file);
}

void placeNewBook(Book** firstBook, Book* newBook) 
{
    if (!*firstBook || placeOnShelf(*firstBook, newBook) > 0)
    {
        newBook->next = *firstBook;
        *firstBook = newBook;
        return;
    }

    Book* current = *firstBook;
    while (current->next && placeOnShelf(current->next, newBook) < 0)
    {
        current = current->next;
    }
    newBook->next = current->next;
    current->next = newBook;
}

int placeOnShelf(Book* one, Book* two) {
    return strcmp(two->name, one->name );
}

Book* burnBooks(Book* first) {
    Book* curr = first;
    Book* prev = NULL;
    while (curr) {
        if ((!prev) && (curr->year < 1991))
        {
            //problems with it
            first = curr->next;
            free(curr);
            curr = first;
            continue;
        }

        if (curr->year < 1991) {

            prev->next = curr->next;
            free(curr);
            curr = prev->next;
            continue;
        }
        prev = curr;
        curr = curr->next;
    }
    return first;
}

void seeOnShelf(Book* firstBook) {

    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("\t Author\t      |\t\t\t Name\t\t\t    | Published| Pages |    Price   |");
    printf("\n-----------------------------------------------------------------------------------------------------\n");

    Book* current = firstBook;
    do
    {
        printf(" %-20s | %-44s|   %4d   |  %3d  |   %4.2lf   |\n", current->author, current->name, current->year, current->pages, current->price);
        current = current->next;
    } 
    while (current);

    printf("-----------------------------------------------------------------------------------------------------\n\n");
}

void sellBooks(Book* curr) {
    if (!curr) {
        return;
    }
        sellBooks(curr->next);
        free(curr);
}