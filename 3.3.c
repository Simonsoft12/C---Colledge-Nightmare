#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    char name_source[31];
    char name_dest[31];
    printf("Podaj ĹciekÄ do pliku: ");
    scanf("%30[^\n]s", name_source);
    while (getchar() != '\n')
        ;

    FILE *source = fopen(name_source, "r");
    if (source == NULL)
    {
        printf("couldn't open file\n");
        exit(4);
    }


    printf("Podaj nazwe pliku wyjsciowego: ");
    scanf("%30[^\n]s", name_dest);

    FILE *copied = fopen(name_dest, "w");

    if (copied == NULL)
    {
        printf("couldn't create file\n");
        fclose(source);
        exit(5);
    }

    for (;;)
    {
        int c = getc(source);
        if (c == EOF)
        {
            fclose(source);
            fclose(copied);
            break;
        }
        putc(c, copied);
    }
    printf("File copied\n");
    return 0;
}