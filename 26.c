#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

char* my_strcpy(char* dest, const char* src);
char* my_strcat(char* dest, const char* src);
int my_strlen(const char* str);
void loadc(char* tab, int size);

int main()
{
	char tab1[1001], tab2[1001];
	char* t1 = tab1, * t2 = tab2;

	printf("Wprowadz napis pierwszy: ");
	loadc(t1, 1000);
	printf("Wprowadz napis drugi: ");
	loadc(t2, 1000);

	int strlen1 = my_strlen(t1);
	int strlen2 = my_strlen(t2);
	printf("%d %d\n", strlen1, strlen2);

	my_strcat(t2, t1);
	printf("%s\n", t2);
	my_strcpy(t2, t1);
	printf("%s\n", t2);

}

void loadc(char* tab, int size)
{
	int i = 0;
	char c;
	while (i < size)
	{
		if ((c = getchar()) == '\n' || c == EOF) {
			*(tab + i) = '\0';
			i = -1;
			break;
		}
		*(tab + i) = c;
		i++;
	}
	if (i == size) {
		while ((c = getchar()) != '\n' && c != EOF);
	}

}

char* my_strcpy(char* dest, const char* src)
{
	if (dest == NULL || src == NULL) return NULL;
	int i = 0;

	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return dest;
}

char* my_strcat(char* dest, const char* src)
{
	if (dest == NULL || src == NULL) return NULL;
	char* tmp = dest;
	int i = 0;

	int len = my_strlen(dest);

	i = len;
	while (i < len + my_strlen(src) && i < 1000)
	{
		*(dest + i) = *(src + i - len);
		i++;
	}
	*(dest + i) = '\0';
	return dest;

	while (*dest != '\0' && i < 1001 && *dest != '\0') {
		dest++;
		i++;
	}
	while (*src != '\0' && *src != '\n') {
		(*dest++ = *src++);
		i--;
	}
	*(dest + i) = '\0';

	return tmp;
}

int my_strlen(const char* str)
{
	if (str == NULL) return -1;
	const char* p = str;

	while (*p != '\0') {
		++p;
	}

	return p - str;
}
