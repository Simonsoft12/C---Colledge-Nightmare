#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum(const float* tab, unsigned int size, float *result);
int avg(const float* tab, unsigned int size, float *result);
int read_vector_float(float *vec, int size, float stop_value);

int main()
{
	int i;
	unsigned int size = 0;
	float tab[100];
	float suma, srednia;
	float *wsk;
	wsk = tab;

	
	printf("Podaj liczby:\n");
		
	for(i=0; i<100; i++)
		{
			scanf("%f", &*(wsk+i));
			
			if(*(tab+0) == 0)
			{
				printf("Not enough data available");
				exit(3);
			}
			size++;
			
			if(*(tab+i) == 0)
			{
				size--;
				break;
			}	
		}
	
		sum(wsk, size, &suma);
		avg(wsk, size, &srednia);
	
		printf("Suma : %0.2f\n", suma);
		printf("Srednia : %0.2f\n", srednia);
		
	return 0;
}

int sum(const float* tab, unsigned int size, float *result)
	{	
		if(tab == NULL) return 0;
		if(result==NULL) return 0;
		unsigned int i;
		*result = 0;

		for(i=0;i<size;i++)
		{
    		*result +=*(tab+i);
		}
	
		
		return 1;
	}
	
	
int avg(const float* tab, unsigned int size, float *result)
	{
		if(tab == NULL) return 0;
		if(result==NULL) return 0;
		unsigned int i;
		*result = 0;
		
		for(i=0; i<size; i++)
		{
			*result += *(tab+i)/size;
		}
		
			
		return 1;
	}
	
int read_vector_float(float *vec, int size, float stop_value)
{
	
}










