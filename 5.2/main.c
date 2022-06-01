#include <stdio.h>
#include "word_set.h"

// LSB (65 66 67 68) - od najmniej do najbardziej znaczÄcego bajtu
// MSB (68 67 66 65) - od najbardziej do najmniej znaczÄcego bajtu

int main(void){
union word_set ubytes;
printf("Podaj liczbe: ");
int res = scanf("%d",&ubytes.num);
if(res != 1)
{
  printf("Incorrect input");
  return 1;
}
for(int i = 0; i < 2; i++)
{
  printf("%d ", *(ubytes.b+i));
}
return 0;
}