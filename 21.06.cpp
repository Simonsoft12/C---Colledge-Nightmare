#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double znajdz_sume(int n,double *T)
{
    int i;
	double wynik;
	double *wsk;
	wsk = T;
	  	
	wynik = 0; 
	for ( i = 0; i < n; i++)
	{
		wynik += *(wsk+i);
	}
	return wynik;         
}    
double srednia(int n, double *T) 
{
	double wynik=0;
	int i;
	double *wsk;
	wsk = T;
	
	for(i=0; i<=n-1; i++)
	{
		wynik+=*(wsk+i);
	}
	return wynik/n;
}

int main()     
{
    int i,n=100;
	double T[100];
    double *wsk=T;

    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        *wsk=((float)rand()/(RAND_MAX))*20;
        printf("%f\t",*wsk);
        wsk++;
    }    
    printf("\nSuma: %.2f\n",znajdz_sume(n,T));
    printf("Srednia: %.2f\n",srednia(n,T));
    system("pause");
    return 0;
}  



