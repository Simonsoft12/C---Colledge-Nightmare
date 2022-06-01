#include <stdio.h>

int read_file(const char *filename);
int read_file_2(const char *filename, int *xd);
void print_file_in(FILE *file)
{
  for (;;)
  {
    int a = fgetc(file);
    if (a == EOF)
      break;
    printf("%c", a);
  }
}

void dodaj(int *a)
{
  *a += 1;
  return;
}

int main(void)
{

  char filename[31];

  printf("podaj sciezke do pliku: ");
  scanf("%30[^\n]s", filename);

  FILE *file = fopen(filename, "rt");
  if (file == NULL)
  {
    printf("Couldn't open file\n");
    return 4;
  }
  int res = read_file(filename);
  fclose(file);
  printf("%d", res);
  return 0;
}

int read_file_2(const char *filename, int *xd)
{

  FILE *file = fopen(filename, "rt");
  if (file == NULL)
  {
    return 0;
  }
  dodaj(xd);
  for (char filename_in[31] = {0}; fscanf(file, "%30s\n", filename_in) != 0;)
  {
    printf("%s\n", filename_in);
    FILE *file_in = fopen(filename_in, "rt");

    read_file_2(filename_in, xd);
    if (file_in != NULL)
    {
      fclose(file_in);
    }
    if (feof(file))
      break;
  }
  fclose(file);
  return 1;
}

int read_file(const char *filename)
{
  if (filename == NULL)
    return -1;
  int x = 0;
  int *ptr = &x;
  read_file_2(filename, ptr);
  return x;
}
