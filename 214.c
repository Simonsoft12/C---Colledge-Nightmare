#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tested_declarations.h"
#include "rdebug.h"

int validate(const char*number) {
	if(number == NULL) return -1;
	if(*number == '0' && (int)strlen(number) > 1) return 0;

	for (int i = 0; i < (int)strlen(number); i++) {
		if (*(number + i) > '2'+2+2+2+1 || *(number + i) < '0') {
			return 0;
		}
	}
	return 1;
}

int add(const char* number1, const char* number2, char* result, int size) {
	if(number1 == NULL) return 1;
	if(number2 == NULL) return 1;
	if(result == NULL) return 1;
	if(size <= 0) return 1;
	if(!validate(number1) || !validate(number2)) return 1;
	if((int)strlen(number1) >= size) return 2;
	if((int)strlen(number2) >= size) return 2;
	
	int shift = 0, i = 0;
	char ctr = 0;
	for (int j = (int)strlen(number1) - 1, k = (int)strlen(number2) - 1; i < size && (j >= 0 || k >= 0); i++, j--, k--) {
		if (j < 0) {
			ctr = (*(number2 + k) - '0') + shift;
		} else if (k < 0) {
			ctr = (*(number1 + j) - '0') + shift;
		} else if (j >= 0 && k >= 0) {
			ctr = (*(number1 + j) - '0') + (*(number2 + k) - '0') + shift;
		}

		if (ctr >= 10) {
			ctr = ctr - 10 + '0';
			*(result + i) = ctr;
			shift = 1;
		} else {
			ctr += '0';
			*(result + i) = ctr;
			shift = 0;
		}
	}
	if (shift == 1) {
		if (i >= size - 1) {
			return 2;
		}
		*(result + i) = '1';
		*(result + i + 1) = '\0';
	} else {
		*(result + i) = '\0';
	}

	i = 0;

	for (int j = (int)strlen(result) - 1; i < j; i++, j--) {
		char temp =*(result + i);
		*(result + i) =*(result + j);
		*(result + j) = temp;
	}
	return 0;
}

int main() {
	char t1[200], t2[200];
	printf("Podaj pierwsza liczbe: ");
	int pos = 0;
	char m;
	while(pos < 200) {
		scanf("%c", &m);
		if(m == '\n') break;
		*(t1 + pos) = m;
		pos += 1;
	}
	*(t1 + pos) = '\0';
	while(m != '\n') {
		scanf("%c", &m);
		if(m == '\n') break;
	}
	printf("Podaj druga liczbe: ");
	
	pos = 0;
	while(pos < 200) {
		scanf("%c", &m);
		if(m == '\n') break;
		*(t2 + pos) = m;
		pos += 1;
	}
	*(t2 + pos) = '\0';
	while(m != '\n') {
		scanf("%c", &m);
		if(m == '\n') break;
	}

	if (!validate(t2) || !validate(t1)) {
		printf("Incorrect input");
		return 1;
	}

	char wynik[202];
	add(t1, t2, wynik, 202);
	
	for (int i = 0; i < (int)strlen(wynik); i++) {
		printf("%c",*(wynik + i));
	}

	return 0;
}
