#include "functions.h"

int main(void) {

    SBook **pHead = NULL;
	int iCount = 0;

	char choise = '\0';
	printf("\t\t\t Menu\n");
	printf("Import from file - F\t\t Input from console - C\n");
	printf("Show list - L\t\t\t Save list in file - S\n");
	printf("Delete book by year - D\t\t Print 6 eldest books - P\nExit - E\n");

	while ((choise = checkTask(choise)) != 'E') {
		switch (choise) {
			case 'F': {
				readFromFile(&pHead, &iCount);//���������� � �����

				printf("\t\t\t Menu\n");
				printf("Import from file - F\t\t Input from console - C\n");
				printf("Show list - L\t\t\t Save list in file - S\n");
				printf("Delete book by year - D\t\t Print 6 eldest books - P\nExit - E\n");
				break;
			}
			case 'C': {
				readFromConsole(&pHead, &iCount);//���������� � ������

				printf("\t\t\t Menu\n");
				printf("Import from file - F\t\t Input from console - C\n");
				printf("Show list - L\t\t\t Save list in file - S\n");
				printf("Delete book by year - D\t\t Print 6 eldest books - P\nExit - E\n");
				break;
			}
			case 'L': {
				printListToConsole(pHead);//�������� ������

				printf("\t\t\t Menu\n");
				printf("Import from file - F\t\t Input from console - C\n");
				printf("Show list - L\t\t\t Save list in file - S\n");
				printf("Delete book by year - D\t\t Print 6 eldest books - P\nExit - E\n");
				break;
			}
			case 'S': {
				saveListInFile(pHead);//���������� ������ � ����

				printf("\t\t\t Menu\n");
				printf("Import from file - F\t\t Input from console - C\n");
				printf("Show list - L\t\t\t Save list in file - S\n");
				printf("Delete book by year - D\t\t Print 6 eldest books - P\nExit - E\n");
				break;
			}
			case 'D': {
				pHead = deleteBooksByYear(pHead, &iCount);//��������� ���� ������� ������� ����

				printf("\t\t\t Menu\n");
				printf("Import from file - F\t\t Input from console - C\n");
				printf("Show list - L\t\t\t Save list in file - S\n");
				printf("Delete book by year - D\t\t Print 6 eldest books - P\nExit - E\n");
				break;
			}
			case 'P': {
				int iEldestBooksCount = (iCount > 6) ? 6 : iCount;
				SBook** pEldest = calloc(iEldestBooksCount, sizeof(SBook));
				findEldestBookInList(pHead, pEldest, iEldestBooksCount);

				printf("\t\t\t Menu\n");
				printf("Import from file - F\t\t Input from console - C\n");
				printf("Show list - L\t\t\t Save list in file - S\n");
				printf("Delete book by year - D\t\t Print 6 eldest books - P\nExit - E\n");
				free(pEldest);
				break;
			}
			default: {
				if (choise == '\n') {
					break;
				} else {
					printf("Symbol(s) not correct, look on Menu and try another\n");
					while (getchar()!='\n');
					break;
				}
			}
		}
	}

    if (pHead) {
		freeDunamicAllocatedMemory(pHead);
    }
	return 0;
}