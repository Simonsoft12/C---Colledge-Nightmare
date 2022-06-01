#include <stdio.h>
#include "bit_set.h"

int main(void){
union bit_set bytes;
int num = 0;
printf("Podaj liczbe: ");
int res = scanf("%d", &num);
if(res != 1)
{
  printf("Incorrect input");
  return 1;
}
bytes.num = num;
printf("%u %u %u %u %u %u %u %u ", bytes.bity.b7, bytes.bity.b6, bytes.bity.b5, bytes.bity.b4,
bytes.bity.b3, bytes.bity.b2, bytes.bity.b1, bytes.bity.b0);
// printf("%lu", sizeof(union bit_set));
return 0;
}