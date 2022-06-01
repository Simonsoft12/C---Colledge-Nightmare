#include <stdio.h>

int main()
{
	
	int a, *wsk1 = &a;
	float b, *wsk2 = &b;
	char c, *wsk3 = &c;

	*wsk1 = 15;
	*wsk2 = 5.6;
	*wsk3 = '$';

	printf("%d\t%0.1f\t%c", *wsk1, *wsk2, *wsk3);
	
	return 0;
}
