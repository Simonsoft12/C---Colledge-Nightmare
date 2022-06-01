#include <stdio.h>
#include <stdlib.h>
 
int ASCIIZ_length(const char* txt){
    int i;
    if (txt == NULL) return -1;
    for(i = 0; ; i++){
        if(*(txt+i) == '\0') return i;
    }
}
 
int main() {
 
    printf("Pisz:");
    char text[1010];
    fgets(text,1010,stdin);
    char *t = text;
 
    printf("%d", ASCIIZ_length(t)-1);
 
    return 0;
}
