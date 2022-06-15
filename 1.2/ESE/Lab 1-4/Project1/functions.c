#include "functions.h"

//------------------------------------------------------------------------------

//Check what letter you enter
//Return it to main function
char checkTask(char choise) {
	choise = getchar();
	return choise;
}

//------------------------------------------------------------------------------

//Allocate memory for new node element
//Return pointer to new node element
SBook *addNewBook() {
	SBook *newBook = (SBook *)calloc(1, sizeof(SBook));
	return newBook;
}

//------------------------------------------------------------------------------

//Restart input when it was not correct
void clearLine(char cLast) {
	while (getchar() != cLast);
}

//------------------------------------------------------------------------------

//Enter new node elements to program memory from console
void readFromConsole(SBook **pHead, int *iCount) {
	int amount;
	printf("What amount of books you want to input in list?  \n");
	while(!scanf("%d", &amount) || amount <= 0) {
		clearLine('\n');
		printf("You entered wrong number of books\nTry again: ");
	}
	while (amount > 0) {
		SBook *newBook = addNewBook();

		printf("Enter Author of the book: ");
		clearLine('\n');

		gets_s(newBook->sAuthor, STANDARD_STRING_LENGHT, stdin);

		for (int i = 0; newBook->sAuthor[i]; i++) {
			if (!(isalpha(newBook->sAuthor[i])) && !(ispunct(newBook->sAuthor[i])) && !(isspace(newBook->sAuthor[i]))) {
				printf("Error, wrong Author\nTry again: ");
				gets_s(newBook->sAuthor, STANDARD_STRING_LENGHT, stdin);
				i = 0;
			}
		}

		printf("Enter book name: ");
		gets_s(newBook->sName, STANDARD_STRING_LENGHT, stdin);
		for (int i = 0; newBook->sName[i]; i++) {
			if (!(isalpha(newBook->sName[i])) && !(ispunct(newBook->sName[i])) && !(isspace(newBook->sName[i]))) {
				printf("Error, wrong name of book\nTry again: ");
				gets_s(newBook->sName, STANDARD_STRING_LENGHT, stdin);
				i = 0;
			}
		}

		printf("Enter year of publishing: ");
		while ((!scanf("%d", (&newBook->iYear))) || (newBook->iYear >= 2022 || newBook->iYear < 0)) {
			clearLine('\n');
			printf("You entered wrong year\nTry again: ");
		}
		printf("Enter number of pages: ");
		while (!scanf("%d", (&newBook->iPages)) || newBook->iPages <= 0) {
			clearLine('\n');
			printf("You enterd wrong amount of pages\nTry again: ");
		}
		printf("Enter book price: ");
		while ((!scanf("%lf", (&newBook->dPrice))) || (newBook->dPrice) < 0) {
			clearLine('\n');
			printf("You entered wrong price of book\nTry again: ");
		}
		sortNewNodeElementByName(pHead, newBook);
		amount--;
		(*iCount)++;
	}
	printf("Input data from console done succesful\n");
}

//------------------------------------------------------------------------------

//Enter new node elements from file to program memory
void readFromFile(SBook **pHead, int *iCount) {

	char buffer[STANDARD_STRING_SCAN_LENGHT];

	printf("Type name of file to import list from this file:\n");
	while (getchar() != '\n');
	char filesName[STANDARD_STRING_LENGHT];
	gets_s(filesName, STANDARD_STRING_LENGHT, stdin);

	char txt[] = ".txt";
	strcat(filesName, txt);

	FILE *file;
	if (!(file = fopen(filesName, "r"))) {
		printf("Can`t open file\nMaybe file does not exist\nReturn to menu\n");
		return;
	}

	bool bIfFileIsNull = false, bBookAddedInList = false;
	int iCountNonAddedBooks = 0;
	while (fgets(buffer, STANDARD_STRING_SCAN_LENGHT, file)) {
		bIfFileIsNull = true;
		SBook *newBook = addNewBook();
		strcpy(newBook->sAuthor, strtok(buffer, "\t"));

		for (int i = 0; newBook->sAuthor[i]; i++) {
			if (!(isalpha(newBook->sAuthor[i])) && !(ispunct(newBook->sAuthor[i])) && !(isspace(newBook->sAuthor[i]))) {
				printf("Error, wrong Author in %i book\nError:numbers\n", *iCount+1);
				free(newBook);
				return;
			}
		}
		
		strcpy(newBook->sName, strtok(NULL, "\t"));

		for (int i = 0; newBook->sName[i]; i++) {
			if (!(isalpha(newBook->sName[i])) && !(ispunct(newBook->sName[i])) && !(isspace(newBook->sName[i]))) {
				printf("Error, wrong name of book in %i book\nError:numbers\n", *iCount+1);
				free(newBook);
				return;
			}
		}

		char *numberBuffer = strtok(NULL, "\t");

		if(!numberBuffer) {
			printf("Error, wrong year in %i book\nError: not exist\n", *iCount + 1);
			free(newBook);
			return;
		}

		for (int i = 0; numberBuffer[i]; i++) {
			if (!(isdigit(numberBuffer[i]))) {
				printf("Error, wrong year in %i book\nError:letters\n", *iCount+1);
				free(newBook);
				return;
			}
		}

		newBook->iYear = atol(numberBuffer);

		if (newBook->iYear < 0 || newBook->iYear > 2022) {
			printf("Error, wrong year in %i book\nError:limit(lower 0 or higher current year)\n", *iCount+1);
			free(newBook);
			return;
		}
		numberBuffer = NULL;
		numberBuffer = strtok(NULL, "\t");

		if(!numberBuffer) {
			printf("Error, wrong amount of pages in %i book\nError: not exist\n", *iCount + 1);
			free(newBook);
			return;
		}

		for (int i = 0; numberBuffer[i]; i++) {
			if (!(isdigit(numberBuffer[i])) && numberBuffer) {
				printf("Error, wrong amount of pages in %i book\nError:letters\n", *iCount+1);
				free(newBook);
				return;
			}
		}

		newBook->iPages = atol(numberBuffer); 

		if (newBook->iPages <= 0) {
			printf("Error, wrong amount of pages in %i book\nError:limit(lower 1)\n", *iCount+1);
			free(newBook);
			return;
		}
		numberBuffer = NULL;
		numberBuffer = strtok(NULL, "\n");

		if(!numberBuffer) {
			printf("Error, wrong price in %i book\nError: not exist\n", *iCount + 1);
			free(newBook);
			return;
		}

		for (int i = 0; numberBuffer[i]; i++) {
			if (!(isdigit(numberBuffer[i])) && !(ispunct(numberBuffer[i]))) {
				printf("Error, wrong price in %i book\nError:letters\n", *iCount+1);
				free(newBook);
				return;
			}
		}

		newBook->dPrice = atol(numberBuffer);

		if (newBook->dPrice < 0) {
			printf("Error, wrong price in %i book\nError:limit(lower 0)\n", *iCount+1);
			free(newBook);
			return;
		}

		bBookAddedInList = sortNewNodeElementByName(pHead, newBook);
		if (bBookAddedInList) {
			(*iCount)++;
		} else {
			iCountNonAddedBooks++;
		}
	}

	fclose(file);

	if (bIfFileIsNull) {
		printf("Import data from file %s done succesful\n", filesName);
		if (iCountNonAddedBooks > 0) {
			printf("%d book(s) was already in list\n", iCountNonAddedBooks);
		}
	} else {
		printf("File %s is empty\n", filesName);
	}
}

//------------------------------------------------------------------------------

//Sort by entering node element in the opposite order to the alphabet
bool sortNewNodeElementByName(SBook **pHead, SBook *newBook)  {
	SBook *pCurrent = *pHead;

	while (pCurrent) {
		if (strcmp(pCurrent->sName, newBook->sName) == 0) {
			//printf("Book already in list\n");
			return false;

		}
		pCurrent = pCurrent->pNext;
	}

	pCurrent = *pHead;

	if (!*pHead || checkNodeElementName(pCurrent, newBook) > 0) {
		newBook->pNext = *pHead;
		*pHead = newBook;
		return true;
	}

	while (pCurrent->pNext && checkNodeElementName(pCurrent->pNext, newBook) < 0) {
		pCurrent = pCurrent->pNext;//set pointer to correct position
	}
	newBook->pNext = pCurrent->pNext;//set node element to correct position
	pCurrent->pNext = newBook;
	return true;
}

//------------------------------------------------------------------------------

//Check where new node element was comparing with the other elements in list
//Return 0 if name 1 and 2 books are equal
//<0 if the first non-matching character in book name 1 is greater (in ASCII) than that of book name 2
//>0 if the first non-matching character in book name 1 is lower (in ASCII) than that of book name 2.
int checkNodeElementName(SBook *one, SBook *two) {
	return strcmp(two->sName, one->sName );
}

//------------------------------------------------------------------------------

//Delete node element which year is less or same to enter
SBook *deleteBooksByYear(SBook *pHead, int *iCount) {
	if (!pHead) {
		printf("Book not found\n");
		return pHead;
	}
	int iYear;
	printf("Enter year, book published before this year would be Delete from list\n");
	while (!scanf("%i", &iYear)) {
		clearLine('\n');
		printf("Year is numbers, not letters or symbols\nTry again: ");
	}
	SBook *pCurrent = pHead;
	SBook *pPrevious = NULL;
	while (pCurrent) {
		if ((!pPrevious) && (pCurrent->iYear < iYear)) {
			pHead = pCurrent->pNext;
			free(pCurrent);
			pCurrent = pHead;
			(*iCount)--;
			continue;
		}

		if (pCurrent->iYear < iYear) {
			pPrevious->pNext = pCurrent->pNext;
			free(pCurrent);
			pCurrent = pPrevious->pNext;
			(*iCount)--;
			continue;
		}
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;
	}
	printf("Books published before %i year deleted\n", iYear);
	return pHead;
}

//------------------------------------------------------------------------------

//Print list from program memory to console
void printListToConsole(SBook *pHead) {
	if (!pHead) {
		printf("Book not found\n");
		return;
	}
	printf("=================================================================================================================================\n");
	printf("|              Author           |                            Name                              | Published | Pages |    Price   |\n");
	printf("+===============================+==============================================================+===========+=======+============+\n");

	SBook *pCurrent = pHead;
	do {
		printf("|%-30s | %-60s |    %4d   |  %3d  |   %4.2lf   |\n",\
			pCurrent->sAuthor, pCurrent->sName, pCurrent->iYear, pCurrent->iPages, pCurrent->dPrice);
		if(pCurrent->pNext) {
			printf("--------------------------------+--------------------------------------------------------------+-----------+-------+------------+\n");
		} else {
			printf("=================================================================================================================================\n");
		}
			pCurrent = pCurrent->pNext;
	} while (pCurrent);
	printf("\n");
	
}

//------------------------------------------------------------------------------

//Clear memory after exiting program
void freeDunamicAllocatedMemory(SBook *pCurrent) {
	if (!pCurrent) {
		return;
	}
	freeDunamicAllocatedMemory(pCurrent->pNext);
	free(pCurrent);
}

//------------------------------------------------------------------------------

//Save in file list from program memory
void saveListInFile(SBook *pHead) {
	if (!pHead) {
		printf("Book not found\n");
		return;
	}
	printf("Type name of file where you want to save\n");
	char filesName[STANDARD_STRING_LENGHT] = "filesName";
	scanf_s("%s", filesName, STANDARD_STRING_LENGHT);

	char txt[] = ".txt";
	strcat(filesName, txt);

	FILE *file;
	if (!(file = fopen(filesName, "a"))) {
		printf("Save error\nFile not open.\nReturn to menu\n");
		return;
	}
	SBook *pCurrent = pHead;
	do {
		fprintf(file, "%s\t%s\t%d\t%d\t%.2lf\n", \
			pCurrent->sAuthor, pCurrent->sName, pCurrent->iYear, pCurrent->iPages, pCurrent->dPrice);

		pCurrent = pCurrent->pNext;
	} while (pCurrent);
	fclose(file);
	printf("Save data in file %s done succesful\n", filesName);
	return;
}

//------------------------------------------------------------------------------

//Find 6 or less eldest books in list
void findEldestBookInList(SBook *pHead,SBook **pEldest,int iCount) {
	if (!pHead) {
		printf("Book not found\n");
		return;
	}

	for (int i = 0; i < iCount; i++) {
		SBook *pCurr = pHead;
		while (pCurr) {
			if (!pEldest[i]) {

				for (int j = 0; j < iCount; j++) {
					if (pCurr == pEldest[j] && pCurr->pNext) {
						pCurr = pCurr->pNext;
						j = 0;// restart checking from first element in array pEldest
					}
				}

				pEldest[i] = pCurr;
			} else if (pEldest[i]->iYear > pCurr->iYear) {
				bool bUsed = false;
				for (int j = 0; j < iCount; j++) {
					if (pCurr == pEldest[j]) {
						bUsed = true;
					}
				}
				if (!bUsed) {
					pEldest[i] = pCurr;
				}
			}

			pCurr = pCurr->pNext;
		}
	}

	printf("_______________________________________Eldest Books In List__________________________________________\n");
	printf("\t Author\t      |\t\t\t Name\t\t\t    | Published| Pages |    Price   |");
	printf("\n=====================================================================================================\n");

	for (int i = 0; i < iCount; i++) {
		printf(" %-20s | %-44s|   %4d   |  %3d  |   %4.2lf   |\n", \
			pEldest[i]->sAuthor, pEldest[i]->sName, pEldest[i]->iYear, pEldest[i]->iPages, pEldest[i]->dPrice);
		printf("----------------------+---------------------------------------------+----------+-------+------------+\n");
	}
	printf("\n");
	
}

//------------------------------------------------------------------------------