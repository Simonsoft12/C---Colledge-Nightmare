#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
  char filename[31];
  printf("podaj sciezke do pliku: ");
  scanf("%30[^\n]s", filename);

  FILE *file = fopen(filename, "rt");
  if (file == NULL)
  {
    printf("Couldn't open file");
    exit(4);
  }

  for(;;)
  {
    int c=fgetc(file);
    if(c=='\n') break;

    if(!isdigit(c) && c!=' ')
    {
      printf("File corrupted\n");
      fclose(file);
      return 6;
    }
  }

  fseek(file,0,SEEK_END);
  int size=ftell(file);
  fseek(file,0,SEEK_SET);
  
  int liczba=0;
  FILE *numbers = fopen("numbers.txt", "w+");

    for (;;)
    {
        liczba = 0;
        fscanf(file, "%d", &liczba);
        if(liczba>=size)
        {
          printf("File corrupted\n");
          fclose(numbers);
          fclose(file);
          return 6;
        }
        if (isalpha(fgetc(file)))
            break;
        fprintf(numbers, "%d ", liczba);
    }

  fseek(numbers,0,SEEK_SET);
    for (;;)
    {
        liczba = 0;
        fscanf(numbers, "%d", &liczba);
        // printf("%d ", liczba);

        if (fgetc(numbers)==EOF)
            break;

        fseek(file, liczba, SEEK_SET);
        printf("%c", fgetc(file));
    }

    
  fclose(numbers);
  fclose(file);

  return 0;
}