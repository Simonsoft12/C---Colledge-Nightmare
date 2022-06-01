#include <stdio.h>
#include <stdlib.h>

#define COULDNT_OPEN_FILE 4;

int main(void)
{
    char name[31];
    printf("Podaj ĹciekÄ do pliku: ");
    scanf("%30[^\n]s", name);
    int i;
    FILE *f = fopen(name, "r");
    if (f == NULL)
    {
        
        printf("couldn't open file\n");
        exit(4);
    }
    int c = fgetc(f);
    if (c == EOF)
    {
        ungetc(c, f);
        printf("nothing to show\n");
    }
    else
    {
        ungetc(c, f);
        for (;;)
        {
            i = fgetc(f);
            if (i == EOF)
                break;
            putchar(i);
        }
    }
    fclose(f);
    return 0;
}