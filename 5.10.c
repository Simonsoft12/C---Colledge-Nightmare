
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct file_t
{
    FILE *f;
    int size;
};
int open_file(struct file_t* f, const char *filename);
struct file_t* find_min(const struct file_t* files, int size);
void close_file(struct file_t* f);
int main(){
    struct file_t filename[5],*wsk_filename;
    printf("podaj nazwy plikow: ");
    char tab[100000];
    int licznikotwarc = 0;
    while(1)
    {
        fgets(tab,100,stdin);
        if(*tab=='\n'){
            if(licznikotwarc==0){
                printf("Error");
                return 1;
            }
            break;
        }
        *(tab+strlen(tab)-1) = '\0';
        if(licznikotwarc<5)
            if(open_file(filename+licznikotwarc,tab))licznikotwarc++;
    }//git
    printf("podaj teskty: ");
    for(;;){
        wsk_filename = find_min(filename,licznikotwarc);
        fgets(tab,100000,stdin);
        if(*tab=='\n'){//future
            break;
        }
        wsk_filename->size += strlen(tab);
        fputs(tab,wsk_filename->f);
    }
    printf("Files saved");
    for(int i = 0; i < licznikotwarc; i++){
        close_file(filename+i);
    }
    return 0;
}
int open_file(struct file_t* f, const char *filename)
{
    if(!f || !filename)return 0;
    FILE *p = fopen(filename,"r+");
    if(p == NULL)return 0;
    f->f = p;
    int licznik = 0;
    while(fgetc(p) != EOF)licznik++;
    f->size = licznik;
    return 1;
}
struct file_t* find_min(const struct file_t* files, int size)
{
    if(!files || size<1)return NULL;
    int min = (files)->size;
    const struct file_t *punkt = files;
    for(int i = 1; i < size; i++){
        if((files+i)->size < min){
            min = (files+i)->size;
            punkt = (files+i);
        }
    }
    return (struct file_t*)punkt;
}
void close_file(struct file_t* f)
{
    if(f && f->f){
        fclose(f->f);
    }
}
