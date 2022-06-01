#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
	{
		int i, *wsk, n=20, T[20];
		wsk = T;
		
		srand(time(0));

		for(i=0; i<n; i++)
		{
			*(wsk+i)=(int)+rand()%100;
			printf("%d ", *(wsk+i));
		}
		
		printf("\n");
		
		for(i=0; i<n/2; i++)
		{
			printf("%d ", *(wsk+2*i));
		}

		printf("\n");
    	system("pause");
    	return 0;
	}
