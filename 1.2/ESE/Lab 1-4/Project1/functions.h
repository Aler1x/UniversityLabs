#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define  STANDARD_STRING_SCAN_LENGHT 256
#define STANDARD_STRING_LENGHT 128//

typedef struct SBookNode{
    char sAuthor[STANDARD_STRING_LENGHT];
    char sName[STANDARD_STRING_LENGHT];
    int iYear;
    int iPages;
    double dPrice;

    struct SBookNode *pNext;
}SBook;

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//Scan and return char sumbol
//Used in menu to check what you choose
char checkTask(char choise);

//clear symbols in console 
void clearLine(char cLast);

//Save list of books in user choosed file 
void saveListInFile(SBook *pHead);

//Function allocate memory for new object
SBook *addNewBook();

//Scan information from user choosed file to program memory
void readFromFile(SBook **pHead, int *iCount);

//Scan information from console to program memory
void readFromConsole(SBook **pHead, int *iCount);

//Function set new element in correct position in list by name in the opposite order to the alphabet
bool sortNewNodeElementByName(SBook **pHead, SBook *newBook);

//Function delete book published before year which user entered
SBook *deleteBooksByYear(SBook *pHead, int *iCount);

//Show list in program window(console)
void printListToConsole(SBook *pHead);

//clean program memory after exiting program
void freeDunamicAllocatedMemory(SBook *pHead);

//print some eldest books
//if count of books >= 6 print 6 books
//else print all books
void findEldestBookInList(SBook *pHead, SBook **pEldest, int iCount);
#endif // FUNCTIONS_H 