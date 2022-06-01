#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(){

double *zmienna = malloc(sizeof(double));

*zmienna = M_PI;

	printf("Wartosc zmiennej to : %f\n",*zmienna);
	printf("Adres zmiennej to : %p",zmienna);

  return 0;
}
