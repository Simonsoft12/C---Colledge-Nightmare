#include <stdio.h>
#include <stdlib.h>


float *alokuj(int N)
{
  float *tablica = malloc(sizeof(float)*N);
  return tablica;
}


int main()
{

int a, i;
float *tablica;

printf("Liczba elementow tablicy: ");
tablica = alokuj(scanf("%d",&a));

for(i=0; i<a; i++)

  printf("%.2f\n",tablica[i]);
  return 0;
}
