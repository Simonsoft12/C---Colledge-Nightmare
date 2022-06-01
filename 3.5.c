#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char name[31];

    printf("Podaj nazwe pliku wyjsciowego: ");
    scanf("%30[^\n]s", name);

    FILE *file = fopen(name, "w");

    if (file == NULL)
    {
        printf("couldn't create file\n");
        exit(5);
    }

    for (int i = 0; i <= 100; i++)
    {
        fprintf(file, "%d\n", i);
    }

    fclose(file);
    printf("File saved\n");
    return 0;
}