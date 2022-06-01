#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i, tab[] = {67305985, 134678021, 202050057}, *T1;	
	int s;
	char tab1[3], *T2;
	T1 = tab;
	T2 = tab1;
	

	s = sizeof(tab);
	for(i=0; i<3; i++)
	{
		*(T2+i) = *(T1+i);
		
	}
	for(i=0; i<s; i++)
	{	
		 printf("%d,", ((char)*T2+i));
	}
	return 0;
	
	
}
// ka¿dy int to 4 bajty , 3 inty to 12 bajtów jeden char to jeden bajt
// 1-4 , 5-8, 9-12

