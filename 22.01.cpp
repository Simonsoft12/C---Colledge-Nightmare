#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main(void){
  const char* t1="Ala Ma Kota a kot Ma AlE";
  while (*(t1)) putchar(*(t1)++);
}

