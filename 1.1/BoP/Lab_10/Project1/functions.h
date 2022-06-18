#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  STANDARD_STRING_LENGHT 100

typedef struct BookNode
{
    char author[STANDARD_STRING_LENGHT];
    char name[STANDARD_STRING_LENGHT];
    int year;
    int pages;
    double price;

    struct BookNode* next;
}Book;

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

Book* buyNewBook();

void readFromFile(Book** first);

void placeNewBook(Book** firstBook, Book* newBook);

int placeOnShelf(Book* one, Book* two);

Book* burnBooks(Book* first);

void seeOnShelf(Book* firstBook);

void sellBooks(Book* firstBook);

#endif // FUNCTIONS_H 