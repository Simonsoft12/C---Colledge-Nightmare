#include <stdio.h>
#include "byte_set.h"
#include "tested_declarations.h"
#include "rdebug.h"
// LSB (65 66 67 68) - od najmniej do najbardziej znaczÄcego bajtu
// MSB (68 67 66 65) - od najbardziej do najmniej znaczÄcego bajtu

int main(void){
union byte_set ubytes;
printf("Podaj liczbe: ");
int res = scanf("%d",&ubytes.num);
if(res != 1)
{
  printf("Incorrect input");
  return 1;
}
for(int i = 0; i < 4; i++)
{
printf("%d ", *(ubytes.bytes+i));
}
return 0;
}