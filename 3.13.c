#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char filename[31];
    printf("podaj sciezke do pliku: ");
    scanf("%30[^\n]s", filename);

    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Couldn't open file");
        exit(4);
    }
    for (;;)
    {
        int c = fgetc(file);
        if (c == EOF)
            break;
        printf("%d ", c);
    }
    fclose(file);
    return 0;
}
