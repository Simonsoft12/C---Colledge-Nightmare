#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

char* space_changer(char* c) {
	if(c == NULL) return NULL;
	int t = 0;
	while(*(c + t) != '\0') {
		if(*(c + t) == ' ') {
			*(c + t) = '_';
		} 
		t += 1;
	}
	return c;
}

int main() {
	printf("Podaj tekst: ");
	char c[1000];
	int pos = 0;
	char m;
	while(pos < 1000) {
		scanf("%c", &m);
		if(m == '\n') break;
		*(c + pos) = m;
		pos += 1;
	}
	*(c + pos) = '\0';
	while(m != '\n') {
		scanf("%c", &m);
		if(m == '\n') break;
	}
	space_changer(c);
	printf("%s", c);
	fflush(stdout);
}
