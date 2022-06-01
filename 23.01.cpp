#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f;
    char sciezka[100];
    char tekst;
    char *wsk;
    wsk = sciezka;
    char *tekst2;
	tekst2 = "text.txt";
	int i=0;

    printf("Podaj sciezke do pliku: ");
    do
	{
    	scanf("%s", &sciezka[i]);
    	i++;
	} while(sciezka[i] == '\n');
	
    
    if(*wsk == *tekst2)
    {
        f = fopen("text.txt", "r");
    
        do
			{
                tekst = getc(f);
                int i = strlen(tekst);
                if(strlen(tekst) = 0)
                {
                	printf("Nothing to show");
                	break;
				}
                printf("%c", tekst);
            } while(tekst != EOF);
        	fclose(f);
        	
    	}else printf("Couldn't open file'");
   
    	
    return 0;
}
