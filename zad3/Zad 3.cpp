#include <stdio.h>
#include <conio.h>
#include <ctype.h>


int namale(char c)
{
	if(c >= 'A' && c <= 'Z')
	return c + 'a' - 'A';
	else 
	return c;
}

int main()
{
	char c;
	for(int i=0; i<5; i++){
	
printf("Podaj jakies znaki oddzielone spacja  \n");
scanf("%s", &c);
	printf("Wprowadzona litera to : %c\n", toupper(c));
}
	
}



