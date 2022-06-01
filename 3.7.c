#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int q = 0;

    printf("Podaj iloĹÄ liczb: ");
    int res = scanf("%d", &q);
    if (res != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }
    if (q < 1 || q > 1000)
    {
        printf("Incorrect input data\n");
        return 2;
    }

    for (int i = 0; i <= 100; i++)
    {
        char filename[10];
        sprintf(filename, "%d.txt", i);
        FILE *file = fopen(filename, "wt");
        if (file == NULL)
        {
            printf("couldn't create file");
            exit(5);
        }
        printf("%s\n", filename);

        for (int j = 0; j < 10; j++)
        {
            int g = rand();
            fprintf(file, "%d\n", g);
            q--;
            if (q == 0)
                break;
        }
        fclose(file);
        if (q == 0)
            break;
    }

    return 0;
}