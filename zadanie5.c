#include <stdio.h>
#include <stdlib.h>


void wyswietl(const int* tablica, int N)
{
int i;
    for(i=0; i<N; i++)
    printf("%d ",tablica[i]);

}

int* kopia(const int* tablica, int N)
{
  int *kopiuj = malloc(sizeof(int)*N);
  
int i;
  for(i=0; i<N; i++)
    kopiuj[i] = tablica[i];
    return kopiuj;
}



int main(){

int tablica_wyrazow[] = {1,2,3,4,5,6,7,8,9,10};

wyswietl(tablica_wyrazow, 10);
printf("\n");
wyswietl(kopia(tablica_wyrazow,10),10);

  return 0;
}
