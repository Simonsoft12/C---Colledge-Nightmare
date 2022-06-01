#include <stdio.h>


union double_to_char_t
{
    double d;
    char tab[8];
};

int save_double(const union double_to_char_t *dtc, const char *filename)
{
    if(dtc == NULL || filename == NULL)
    {
        return 1;
    }
    FILE *file = fopen(filename, "wt");
    if(file == NULL)
    {
        return 2;
    }
    int res = fwrite(dtc->tab, sizeof(char), 8, file);
    if(res != 8)
    {
        fclose(file);
        return 3;
    }
    fclose(file);
    return 0;
}

int load_double(union double_to_char_t *dtc, const char *filename)
{
    if(dtc == NULL || filename == NULL)
    {
        return 1;
    }
    FILE *file = fopen(filename, "rt");
    if(file == NULL)
    {
        return 2;
    }
    int res = fread(dtc->tab, sizeof(char), 8, file);
    if(res != 8)
    {
        fclose(file);
        return 3;
    }
    fclose(file);
    return 0;
}

int main() {
    union double_to_char_t num;
    char filename[40];
    printf("Enter the number: ");
    int res = scanf("%lf", &(num.d));
    if(res != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    while(getchar()!='\n');
    printf("Enter file name: ");
    scanf("%39[^\n]s", filename);
    res = save_double(&num, filename);
    if(res == 2)
    {
        printf("Couldn't create file");
        return 5;
    }
    printf("File saved\n");
    while(getchar()!='\n');
    printf("Enter file name: ");
    *filename = 0;
    scanf("%39[^\n]s", filename);
    res = load_double(&num, filename);
    if(res == 2)
    {
        printf("Couldn't open file");
        return 4;
    }
    if(res == 3)
    {
        printf("File corrupted");
        return 6;
    }

    printf("%lf", num.d);

    return 0;
}