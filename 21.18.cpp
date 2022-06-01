#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tab_min(const int* tab, int size, int *min)
{
	if(min == NULL) return 0;
	if(tab == NULL) return 0;
    int i;
    *min = *(tab+0);
    for(i=0; i<size; i++)    
        if(*min > *(tab+i))
            *min = (*(tab+i)); 
		if(*min == 0) return 0;       
    return 1;               
}    

int main()     
{
	int minimum;
    int i,size,tab[100];
    int *wsk=tab;
    
    printf("Podaj liczbe elementow tablicy: ");
    scanf("%d",&size);
    
    printf("podaj element tablicy :");
    for(i=0; i<100; i++)
    {
    	if(i == size) break;
        scanf("%d", &*(wsk+i));
        
    }    
    tab_min(tab,size,&minimum);
    printf("\nElement minimalny w tablicy: %d\n", minimum);
    system("pause");
    return 0;
}  



