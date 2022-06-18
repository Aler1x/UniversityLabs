#pragma warning(disable : 4996)
//вимикає помилку з безпекою fopen
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <conio.h>

void logFile(char str[]) {
	time_t t = time(NULL);
	struct tm* timestamp = localtime(&t);

	FILE* log;
	if (!(log = fopen("log.txt", "a"))) {
		printf("Log file error");
		return;
	}
	fprintf(log, "[%02d.%02d.%04d %02d:%02d:%02d] %s\n",
		timestamp->tm_mday, timestamp->tm_mon+1, timestamp->tm_year+1900, 
		timestamp->tm_hour, timestamp->tm_min, timestamp->tm_sec, str);
	fclose(log);
}

int main(void) {

	printf("enter input file name with extension (50 sumbols):");
	char name[50];
	//scanf("%s", name);
	gets_s(name, 50);

	double x, y;
	printf("\nEnter x and y: ");
	scanf("%lf %lf", &x, &y);
	FILE* input;
	if (!(input = fopen(name, "wb"))) {
		printf("Input number error");
		return 1;
	}
	fwrite(&x, sizeof(double), 1, input);
	fwrite(&y, sizeof(double), 1, input);
	fclose(input);
	//printf("%lf\n%lf\n", x, y);

	char outputString[220];
	logFile("Start program.");

	FILE* file;
	if (!(file = fopen(name, "rb"))) {
		printf("Input error");
		return 1;
	}
	double xFromFile, yFromFile;
	fread(&xFromFile, sizeof(double), 1, file);
	fread(&yFromFile, sizeof(double), 1, file);
	fclose(file);
	sprintf(outputString, "Parametres file \"%s\" opened. x = %lf, y = %lf", name, xFromFile, yFromFile);
	logFile(outputString);

	double result = fabs(pow(xFromFile, yFromFile / xFromFile) - cbrt(yFromFile / xFromFile));
	sprintf(outputString, "Expression calculated. Result = %lf.", result);
	logFile(outputString);

	char outputName[50];
	printf("\nenter output file name with extension (50 sumbols):");
	scanf("%s", outputName);	
	//gets_s(outputName, 50);
	printf("\nenter output file extension (3 sumbols):");
	char extension[4];
	scanf("%s", extension);
	//gets_s(extension, 4);


	if (!strcmp(extension, "txt")) {
		strcpy(extension, "w");
		if (!(file = fopen(outputName, extension))) {
			printf("output error");
			return 1;
		}
		fprintf(file, "%lf", result);
		fclose(file);
	}
	else if (!strcmp(extension, "bin")) {
		strcpy(extension, "wb");
		if (!(file = fopen(outputName, extension))) {
			printf("output error");
			return 1;
		}
		fwrite(&result, sizeof(double), 1, file);
		fclose(file);
	}
	else {
		printf("error extension");
		return 1;
	}

	sprintf(outputString, "Output file \"%s\" saved", outputName);
	logFile(outputString);

	logFile("Program ended\n");
	//printf("%lf\n%lf\n%lf\n", result, xFromFile, yFromFile);
	return 0;
}
char u[4][15] = { " ", " "," "," " };