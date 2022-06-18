#include <stdio.h>
#include <string.h>

void printer(char*, int, int);

int main(void) 
{
	char s[21];

	printf("Enter 20 sumbols: ");
	fgets(s, sizeof(s), stdin);
	printer(s, strlen(s), strlen(s));
	return 0;
}

void printer(char* s, int n, int m)
{
	if (n > 0)
	{
		printer(s, n - 1, m);
		printf("%c", s[m - n]);
	}
	return;
}