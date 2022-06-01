#include <stdio.h>
#include <stdint.h>
#include "bit_set.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main() {

    uint8_t bmp[41];
    printf("Enter values: \n");
    for(int i = 0 ; i < 40 ; i++)
    {
        int res = scanf("%hhx", (bmp+i));
        if(res != 1)
        {
            printf("Incorrect input");
            return 1;
        }
    }

    while(getchar()!='\n');
    char filename[51];
    printf("Enter file name: ");
    scanf("%50s", filename);

    for(int i = 0 ; i < 8 ; i++)
    {
        union bit_set bajt;

        for(int j = 0 ; j < 5 ; j++)
        {
            bajt.num = *(bmp+i*5+j);
            if(bajt.bity.b7 == 0)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }

            if(bajt.bity.b6 == 0)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }

            if(bajt.bity.b5 == 0)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }

            if(bajt.bity.b4 == 0)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }

            if(bajt.bity.b3 == 0)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }

            if(bajt.bity.b2 == 0)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }

            if(bajt.bity.b1 == 0)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }

            if(bajt.bity.b0 == 0)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }

    FILE *file = fopen(filename, "wt");
    if(file == NULL)
    {
        printf("Couldn't create file");
        return 5;
    }

    for(int i = 0 ; i < 8 ; i++)
    {
        union bit_set bajt;
        for(int j = 0 ; j < 5 ; j++)
        {
            bajt.num = *(bmp+i*5+j);
            if(bajt.bity.b7 == 0)
            {
                fprintf(file, " ");
            }
            else
            {
                fprintf(file, "#");
            }

            if(bajt.bity.b6 == 0)
            {
                fprintf(file, " ");
            }
            else
            {
                fprintf(file, "#");
            }

            if(bajt.bity.b5 == 0)
            {
                fprintf(file, " ");
            }
            else
            {
                fprintf(file, "#");
            }

            if(bajt.bity.b4 == 0)
            {
                fprintf(file, " ");
            }
            else
            {
                fprintf(file, "#");
            }

            if(bajt.bity.b3 == 0)
            {
                fprintf(file, " ");
            }
            else
            {
                fprintf(file, "#");
            }

            if(bajt.bity.b2 == 0)
            {
                fprintf(file, " ");
            }
            else
            {
                fprintf(file, "#");
            }

            if(bajt.bity.b1 == 0)
            {
                fprintf(file, " ");
            }
            else
            {
                fprintf(file, "#");
            }

            if(bajt.bity.b0 == 0)
            {
                fprintf(file, " ");
            }
            else
            {
                fprintf(file, "#");
            }
        }
        fprintf(file, "\n");
    }
    printf("File saved");
    fclose(file);
    return 0;
}