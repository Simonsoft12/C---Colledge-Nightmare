#include <stdio.h>

int main(void)
{

    char filename[31];

    printf("podaj sciezke do pliku: ");
    scanf("%30[^\n]s", filename);

    FILE *file = fopen(filename, "rt");
    if (file == NULL)
    {
      if ((file = fopen(filename,"wt"))== NULL)
      {
        printf("Couldn't create file\n");
        return 5;
      }
      else
      {
      printf("File created\n");
      fclose(file);
      return 0;
      }
    }
    else if(file != NULL)
    {
      printf("File already exists!\n");
      fclose(file);
      return 0;
    }
}