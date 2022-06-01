#include <stdio.h>
#include <stdlib.h>
#include <time.h>

	int all_even(int num)
	{
	
		int cyfra, wynik=0;
	    do
	    {
	        cyfra=num;
	        wynik+=cyfra%2;
	        num-=cyfra;

	    } 
	    while(num > 0);
	    if(wynik==0)
	        return 1;
	    return 0;          
	}  

int main()     
	{    
	    int i,size,T[100];
	    int nowysize=0;
	    int *wsk;
	    wsk= T;
	    printf("Podaj ile liczb wprowadzisz: \n");
	    scanf("%d",&size);
	    
	    printf("Wprowadz liczby:\n");
	    for(i=0; i<100; i++)
	    {
	    	if(i == size) break;
	    	scanf("%d", &*(wsk+i));	

		}
		
	   
	      
	    for(i=0;i<size;i++)
	    {
	        if(all_even(*(wsk+i))){
	        	nowysize++;
	            printf("%d ",*(wsk+i));
	        } 
		}
		if (nowysize == 0) printf("\n No Data \n");
	    printf("\n"); 
	    system("pause");
	    return 0;
	    
	}  
	
 
