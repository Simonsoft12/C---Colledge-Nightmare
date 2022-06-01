#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main(void)
{
    FILE *file0 = fopen("0.txt", "w");
        if (file0 == NULL)
    {
        printf("Couldn't create file");
        exit(5);
    }

    FILE *file2 = fopen("2.txt", "w");
    if (file2 == NULL)
    {
        printf("Couldn't create file");
        fclose(file0);
        exit(5);
    }

    FILE *file3 = fopen("3.txt", "w");
    if (file3 == NULL)
    {
        printf("Couldn't create file");
        fclose(file0);
        fclose(file2);
        exit(5);
    }
    FILE *file5 = fopen("5.txt", "w");
    if (file5 == NULL)
    {
        printf("Couldn't create file");
        fclose(file0);
        fclose(file2);
        fclose(file3);
        exit(5);
    }

    printf("Podaj liczby: ");
    for (;;)
    {
        int scan = 0;
        scanf("%d", &scan);
        if (scan == 0)
            break;
        if (scan % 2 == 0)
            fprintf(file2, "%d\n", scan);
        if (scan % 3 == 0)
            fprintf(file3, "%d\n", scan);
        if (scan % 5 == 0)
            fprintf(file5, "%d\n", scan);
        if (scan % 2 != 0 && scan % 3 != 0 && scan % 5 != 0)
            fprintf(file0, "%d\n", scan);
    }

    fclose(file0);
    fclose(file2);
    fclose(file3);
    fclose(file5);
    printf("Files saved");
    return 0;
}