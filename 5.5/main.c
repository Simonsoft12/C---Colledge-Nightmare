#include <stdio.h>
#include "bit_set.h"

int main(void){
union bit_set bytes;
printf("Podaj liczbe: ");
int res = scanf("%u", &bytes.num);

if(res != 1)
{
  printf("Incorrect input");
  return 1;
}

int suma = 0;

for(int i = 0 ; i < 4 ; i++)
{
  if((bytes.bity+i)->b0 == 1) suma++;
  if((bytes.bity+i)->b1 == 1) suma++;
  if((bytes.bity+i)->b2 == 1) suma++;
  if((bytes.bity+i)->b3 == 1) suma++;
  if((bytes.bity+i)->b4 == 1) suma++;
  if((bytes.bity+i)->b5 == 1) suma++;
  if((bytes.bity+i)->b6 == 1) suma++;
  if((bytes.bity+i)->b7 == 1) suma++;
}
if(suma % 2 == 0)
{
  printf("YES");
}
else{
  printf("NO");
}

return 0;
}