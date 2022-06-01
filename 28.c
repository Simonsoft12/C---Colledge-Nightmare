#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"


char* change_letter_size(char* dest, const char* src);

int main()
{
    char dest1[1001], src2[1001];
    char *dest = dest1, *src = src2;
    int i = 0;

    printf("Podaj tekst: ");
    fgets(src2, 1001, stdin);

    change_letter_size(dest,src);

    while (*(dest + i) != '\0') {
        printf("%c", *(dest + i));
        i++;
    }
}

char* change_letter_size(char* dest, const char* src)
{
    if (dest == NULL || src == NULL) return NULL;
    int i = 0, j = 0;
    char *h = "";

    while (*(src + i) != '\0' && *(src + i) != *h) {
        *(dest + i) = *(src + i);
        i++;
    }


    while (j < i) {
        if (*(dest + j) >= 'a' && *(dest + j) <= 'z')  *(dest + j) -= 32;
        else if (*(dest + j) >= 'A' && *(dest + j) <= 'Z')  *(dest + j) += 32;
        j++;
    }
    *(dest + j) = '\0';

    return dest;
}



