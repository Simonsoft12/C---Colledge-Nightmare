#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char name[31];
    printf("Podaj ĹciekÄ do pliku: ");
    scanf("%30[^\n]s", name);
    while (getchar() != '\n')
        ;

    FILE *file = fopen(name, "r");
    if (file == NULL)
    {
        printf("Couldn't open file\n");
        exit(4);
    }

    for (;;)
    {
        int c = fgetc(file);
        if (isalpha(c))
        {
            fclose(file);
            printf("file corrupted\n");
            return 6;
        }
        if (c == EOF)
        {
            break;
        }
    }
    fseek(file, 0, SEEK_SET);
    int suma = 0;
    while (!feof(file))
    {
        int liczba = 0;
        fscanf(file, "%d", &liczba);
        suma += liczba;
    }
    printf("Suma wynosi: %d\n", suma);
    fclose(file);
    return 0;
}