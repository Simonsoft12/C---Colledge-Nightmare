#include <stdio.h>
#include <stdlib.h>




int main()
{
	
float *tablica = malloc(sizeof(float)*100);

int i;

for(i=0; i<100; i++)
  printf("%.2f\n",tablica[i] = i);

  free(tablica);
  return 0;
}
