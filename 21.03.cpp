#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
	{
		int i, n = 10, T[10];
		int *wskaznik = T;
		
		srand(time(0));
		
		printf("Moja Tablica : \n");
		
		for(i=0; i<n; i++)
		{
			*wskaznik = i;
			printf("%d\t", *wskaznik);
			wskaznik++;
		}
		printf("\n");
		system("pause");
		return 0;
	}
