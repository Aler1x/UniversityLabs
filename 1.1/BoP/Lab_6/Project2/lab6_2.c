#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int countVowels(char, ...);
int main()
{
    char s[21];
    printf("Enter characters (max 20):\n");
    fgets(s, sizeof(s), stdin);
    printf("%d\n", countVowels(s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[8], s[9], s[10], s[11], s[12], s[13], s[14], s[15], s[16], s[17], s[18], s[19], s[20]));

    return 0;
}

int countVowels(char c, ...)
{
    char vowels[] = "aeiouyAEIOUY";
    int count = 0;
    if (strchr(vowels, c) != NULL) count++;
    va_list arg_list;
    va_start(arg_list, c);

    while ((c = va_arg(arg_list, int)) != '\0')
    {
        if (strchr(vowels, c) != NULL) count++;
    }
    return count;
}