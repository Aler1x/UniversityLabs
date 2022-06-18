#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define MAX_SENTENCE_LENGTH 1001

int main(void) {

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    char* context = NULL;
    char* p_sentence = sentence;

    for(char* word; word = strtok_s(p_sentence, " ", &context); p_sentence = NULL) {
        if (strlen(word) >= 8) {
            fputs(word, stdout);
            printf("\n");
        }
    }

    return  0;
}