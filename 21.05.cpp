#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
	{
		int i, n=20;
		float *wsk;
		float T[20];
		wsk = T;
		
		srand(time(0));


		for(i=0; i<n; i++)
		{
			*(wsk+i)=((float)rand()/(RAND_MAX))*10;                          
			printf("%f ", *(wsk+i));
		}
		
		printf("\n");
		
		for(i=0; i<n/2; i++)
		{
			printf("%f ", *(wsk+2*i));
		}

		printf("\n");
    	system("pause");
    	return 0;
	}
