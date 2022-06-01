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
    printf("Couldn't open file\n");
    exit(4);
  }
  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  rewind(file);

  int ilosc_liczb=0;
  int suma=0;
  for(;;)
  {
    if(fgetc(file)==EOF)  break;
    int c=fgetc(file);
    if(isalpha(c))
    {
      fclose(file);
      printf("File corrupted");
      return 6;
    }
  }
  rewind(file);
  fscanf(file, "%d", &ilosc_liczb);
  // printf("%d", ilosc_liczb);
  if(ilosc_liczb>size || ilosc_liczb<=0)
  {
    fclose(file);
    printf("File corrupted");
    return 6;
  }
  for(int i=0;i<ilosc_liczb;i++)
  {
    int liczba=0;
    fscanf(file, "%d", &liczba);
    //printf("i:%d liczba:%d\n", i, liczba);
    suma+=liczba;
  }
  fclose(file);
  float srednia=(float)suma/(float)ilosc_liczb;
  
  printf("%d\n%f", suma, srednia);
  return 0;
}