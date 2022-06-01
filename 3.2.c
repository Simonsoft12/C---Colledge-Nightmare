#include <stdio.h>
#include <stdlib.h>


#define CANT_DEFINE_SIZE -1;
#define DATA_ERROR -2;

int file_size_from_path(const char *path);
int file_size_from_file(FILE *f);

int main(void)
{
    char name[31];
    printf("Podaj ĹciekÄ do pliku: ");
    scanf("%30[^\n]s", name);
    const char *path = name;

    FILE *f = fopen(name, "r");
    if (f == NULL)
    {
        printf("couldn't open file\n");
        exit(4);
    }

    int rozmiar_file = file_size_from_file(f);
    fclose(f);

    int rozmiar_path = file_size_from_path(path);

    if (rozmiar_file == rozmiar_path)
    {
        printf("Rozmiar pliku : %d\n", rozmiar_file);
    }
    else
        printf("ERROR");

    return 0;
}

int file_size_from_path(const char *path)
{
    if (path == NULL)
        return DATA_ERROR;
    // printf("%s", path);
    int size = 0;
    FILE *f = fopen(path, "r");
    if(f==NULL) return CANT_DEFINE_SIZE;
    fseek(f,0,SEEK_END);
    size =ftell(f);
    fclose(f);
    return size;
}

int file_size_from_file(FILE *f)
{
    if (f == NULL)
        return  DATA_ERROR;
    FILE *file= f;
    int size=0;
    int save_first_position=ftell(f);
    fseek(file,0,SEEK_END);
    size=ftell(file);
    fseek(file, save_first_position, SEEK_SET);
    return size;
}