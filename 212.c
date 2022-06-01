#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int message_compression(char* c) {
	if(c == NULL) return -1;
	int pos = 0;
	int t = 0;
	int trwa = 0;
	int res=0;
	while(*(c + t) != '\0') {
		char s = *(c+t);
		if(s >= 'a' && s <= 'z') {  
			if(trwa == 1) {
				*(c+pos)=s;
			} else {
				*(c+pos)=s-'a'+'A';
				trwa=1;
			}
			pos++;
		} else if(s>='A' && s <= 'Z') {
			if(trwa == 1) {
				*(c+pos)=s-'A'+'a';
			} else {
				*(c+pos)=s;
				trwa=1;
			}
			pos++;
		} else {
			trwa = 0;
			res += 1;
		}
		t += 1;
	}
	*(c+pos) = '\0';
	return res;
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
	message_compression(c);
	if(*c == '\0') printf("NothingToShow");
	else printf("%s", c);
	fflush(stdout);
}
