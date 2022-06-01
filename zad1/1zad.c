#include <stdio.h>
#include <conio.h>

float dodawanie(float pierwsza, float druga)
{
	float wynik;
	wynik = pierwsza + druga;
	return wynik;
}

float odejmowanie(float pierwsza, float druga)
{
	float wynik;
	wynik = pierwsza - druga;
	return wynik;
}

float mnozenie(float pierwsza, float druga)
{
	float wynik;
	wynik = pierwsza * druga;
	return wynik;
}

float dzielenie(float pierwsza, float druga)
{
	float wynik;
	wynik = pierwsza / druga;
	return wynik;
}

int szukaczdzialan(int functionpointer, float pierwsza, float druga)
{
	float wynik;
	
	if(functionpointer == '+')
	{
		wynik = dodawanie(pierwsza,druga);
	}
	else if(functionpointer == '-')
	{
		wynik = odejmowanie(pierwsza,druga);
	}
	else if(functionpointer == '*')
	{
		wynik = mnozenie(pierwsza,druga);
	}
	else if(functionpointer == '/')
	{
		wynik = dzielenie(pierwsza,druga);
	}
return wynik;
}



int main()
{
	int n;
	float wynik, pierwsza, druga;
	
	void Wypisuj() {
	printf("Podaj 1-sza liczbe ");
	scanf("%f", &pierwsza);
	printf("Podaj 2-ga liczbe ");
	scanf("%f", &druga);
	}

	
	printf("Wybierz jakie dzialanie chcesz wykonac ..\n");
	printf("1 - dodawanie\n");
	printf("2 - odejmowanie\n");
	printf("3 - mnozenie\n");
	printf("4 - dodawanie\n");
	scanf("%d", &n);
	
	switch(n){
		case '+':{
			Wypisuj();
			wynik = szukaczdzialan('+', pierwsza, druga);
			break;
		}
		case '-':{
			Wypisuj();
			wynik = szukaczdzialan('-', pierwsza, druga);
			break;
		}
		case '*':{
			Wypisuj();
			wynik = szukaczdzialan('*', pierwsza, druga);
			break;
		}
		case '/':{
			Wypisuj();
			wynik = szukaczdzialan('/', pierwsza, druga);
			break;
		}
		default : printf("Error");
		getch();
		return 0;
	
	}
	
	
	printf("%f", wynik);
	getch();	

}




