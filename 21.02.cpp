#include <stdio.h>

int main(void)

	{
		int a;
		int *wskaznik;
		
		a = 1;
		wskaznik = &a;
		
		
		printf("liczba: wartosc zmiennej bezposrednio : %d, wartosc zmiennej z wykorzystaniem wskaznika : %d, Adres zmiennej : %p \n", a, *wskaznik, (void *)wskaznik);
		
		
		*wskaznik = 5;
		
		printf("liczba: wartosc zmiennej bezposrednio : %d, wartosc zmiennej z wykorzystaniem wskaznika : %d, Adres zmiennej : %p \n", a, *wskaznik, (void *)wskaznik);
		
		
		return 0;
}
