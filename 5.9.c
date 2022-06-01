#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SUCCESS 0
#define INCORRECT_INPUT_DATA 1
#define COULDNT_OPEN_FILE 2
#define FILE_CORRUPTED 3
#define COULDNT_CREATE_FILE 4

union value
{
    unsigned int dec;

    struct bin_t
    {
        unsigned char b0 : 1;
        unsigned char b1 : 1;
        unsigned char b2 : 1;
        unsigned char b3 : 1;
        unsigned char b4 : 1;
        unsigned char b5 : 1;
        unsigned char b6 : 1;
        unsigned char b7 : 1;
    } bin;
};

int decode(const char *input, const char *output)
{
    if(input == NULL || output == NULL)
    {
        return INCORRECT_INPUT_DATA;
    }
    FILE *file_in = fopen(input, "rt");
    if(file_in == NULL)
    {
        return COULDNT_OPEN_FILE;
    }
    int sum = 0;
    while(!feof(file_in))
    {
        int c = fgetc(file_in);
        sum++;
        if(c != '0' && c != '1' && c != EOF)
        {
            fclose(file_in);
            return FILE_CORRUPTED;
        }
    }
    sum--;
    fseek(file_in, 0, SEEK_SET);
    if(sum % 8 != 0 || sum == 0)
    {
        fclose(file_in);
        return FILE_CORRUPTED;
    }
    FILE *file_out = fopen(output, "wt");
    if(file_out == NULL)
    {
        fclose(file_in);
        return COULDNT_CREATE_FILE;
    }



    while(!feof(file_in))
    {
        union value liczba;
        liczba.dec = 0;

        int bin = fgetc(file_in);
        if(bin == EOF) break;

        liczba.bin.b7 = (unsigned char) (bin - '0');
        bin = fgetc(file_in);
        if(bin == EOF) break;
        liczba.bin.b6 = (unsigned char) (bin -  '0');
        bin = fgetc(file_in);
        if(bin == EOF) break;
        liczba.bin.b5 = (unsigned char) (bin -  '0');
        bin = fgetc(file_in);
        if(bin == EOF) break;
        liczba.bin.b4 = (unsigned char) (bin - '0');
        bin = fgetc(file_in);
        if(bin == EOF) break;
        liczba.bin.b3 = (unsigned char) (bin - '0');
        bin = fgetc(file_in);
        if(bin == EOF) break;
        liczba.bin.b2 = (unsigned char) (bin  - '0');
        bin = fgetc(file_in);
        if(bin == EOF) break;
        liczba.bin.b1 = (unsigned char) (bin  - '0');
        bin = fgetc(file_in);
        if(bin == EOF) break;
        liczba.bin.b0 = (unsigned char) (bin -  '0');

        fprintf(file_out, "%03u", liczba.dec);
    }

    fclose(file_in);
    fclose(file_out);
    return 0;
}

int encode(const char *input, const char *output)
{
    if(input == NULL || output == NULL)
    {
        return INCORRECT_INPUT_DATA;
    }
    FILE *file_in = fopen(input, "rt");
    if(file_in == NULL)
    {
        return COULDNT_OPEN_FILE;
    }

    while(!feof(file_in))
    {
        int c = fgetc(file_in);
        if(!isdigit(c) && c != EOF)
        {
            fclose(file_in);
            return FILE_CORRUPTED;
        }
    }
    int size = ftell(file_in);
    fseek(file_in, 0, SEEK_SET);

    if(size % 3 != 0 || size == 0)
    {
        fclose(file_in);
        return FILE_CORRUPTED;
    }

    for(int i = 0 ; i < size/3 ; i++)
    {
        unsigned int num;
        fscanf(file_in, "%3u", &num);
        if(num > 255)
        {
            fclose(file_in);
            return FILE_CORRUPTED;
        }
    }

    fseek(file_in, 0 , SEEK_SET);

    FILE *file_out = fopen(output, "wt");
    if(file_out == NULL)
    {
        fclose(file_in);
        return COULDNT_CREATE_FILE;
    }

    for(int i = 0; i < size/3 ; i++)
    {
        union value liczba;
        liczba.dec = 0;
        fscanf(file_in, "%3u", &liczba.dec);
        fprintf(file_out, "%u%u%u%u%u%u%u%u", liczba.bin.b7, liczba.bin.b6, liczba.bin.b5,
                liczba.bin.b4, liczba.bin.b3, liczba.bin.b2, liczba.bin.b1, liczba.bin.b0);
    }

    fclose(file_in);
    fclose(file_out);
    return SUCCESS;


}

int main() {
    char op;
    char filename_in[30];
    char filename_out[30];
    printf("Enter operation (D - bin to dec; E - dec to bin): ");
    scanf("%c", &op);
    if(op == 'd' || op == 'D')
    {
        while(getchar()!='\n');

        printf("Enter input file name: ");
        scanf("%30[^\n]s", filename_in);
        while(getchar()!='\n');

        printf("Enter output file name:");
        scanf("%30[^\n]s", filename_out);
        while(getchar()!='\n');

        int res = decode(filename_in, filename_out);
        if(res == COULDNT_OPEN_FILE)
        {
            printf("Couldn't open file");
            return 4;
        }
        if(res ==  COULDNT_CREATE_FILE)
        {
            printf("Couldn't create file");
            return 5;
        }
        if(res == FILE_CORRUPTED)
        {
            printf("File corrupted");
            return 6;
        }
    }
    else if(op == 'e' || op == 'E')
    {
        while(getchar()!='\n');

        printf("Enter input file name: ");
        scanf("%30[^\n]s", filename_in);

        while(getchar()!='\n');
        printf("Enter output file name:");
        scanf("%30[^\n]s", filename_out);

        while(getchar()!='\n');

        int res = encode(filename_in, filename_out);
        if(res == COULDNT_OPEN_FILE)
        {
            printf("Couldn't open file");
            return 4;
        }
        if(res ==  COULDNT_CREATE_FILE)
        {
            printf("Couldn't create file");
            return 5;
        }
        if(res == FILE_CORRUPTED)
        {
            printf("File corrupted");
            return 6;
        }
    }
    else
    {
        printf("Incorrect input data");
        return 2;
    }

    printf("File saved");
    return SUCCESS;
}