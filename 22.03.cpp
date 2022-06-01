#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int marks_counter(const char* text, int* uppercase, int* lowercase, int* whitespace);

int main()
{
	const char* t1="Learn to enjoy every minute of your life. Be happy now. Don't wait for something outside of yourself to make you happy in the future. Think how really precious is the time you have to spend, whether it's at work or with your family. Every minute should be enjoyed and savored. - Earl Nightingale";
	const char* text;
	text = t1;
	int uppercase=0;
	int lowercase=0;
	int whitespace=0;
	
	int a=marks_counter(text,&uppercase,&lowercase,&whitespace);
	
	if(a == -1||a == -2)
	{
		printf("Error\n");
	}
	printf("Wielkie: %d Male: %d Znaki Biale: %d",uppercase,lowercase,whitespace);
	return 0;
}

int marks_counter(const char* text, int* uppercase, int* lowercase, int* whitespace)
{
	if(text==NULL)
		{
			return -1;
		}
	if(uppercase==NULL||lowercase==NULL||whitespace==NULL)
		{
			return -2;
		}
		
	unsigned int a;
	
	for(a = 0; a < strlen(text); a++)
	{
		
		if(islower(*(text+a)))
		{
			*lowercase+=1;
		}
		else if(isupper(*(text+a)))
		{
			*uppercase+=1;
		}
		else if(isspace(*(text+a)))
		{
			*whitespace+=1;
		}
	}
	
	return 1;
}
