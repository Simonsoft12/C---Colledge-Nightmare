#include <stdio.h>
#include<conio.h>
/*

Zadanie 2.
Napisz prosty kalkulator, kt�ry pobiera od u�ytkownika dwie liczby (dowolny typ) i rodzaj operacji (np. dodawanie), okre�lony zaproponowanym typem enum. Napisz funkcj�, kt�ra na podstawie typu operacji zwraca wska�nik do funkcji wykonuj�cej t� operacj�. Nast�pnie wywo�aj t� funkcj� (przez jej wska�nik), a wynik wy�wietl. 
*/


#include <stdio.h>
#include <stdlib.h>
int main ()
{
   enum znaki_operacji {PLUS, MINUS};
   int a, b, x;
   char c;
       printf("Podaj pierwsza liczbe: \n");            
            scanf("%d", &a);
       printf("Podaj druga liczbe: \n");                 
            scanf("%d", &b);
            getchar();
       printf("Jaka operacje chcesz wykonac (podaj znak): \n");
            scanf("%c", &c);

switch (c)   /// dzia�anie 
{
          case   '+': x=a+b;                                  
                   printf("%d\n", x);
                   break;
          case   '-': x=a-b;                                
                   printf("%d\n", x);
                   break;
          case   '*': x=a*b;
                   printf("%d\n", x);            
                   break;
          case   '/': x=a/b;
                   printf("%d\n", x); 

        if (b==0)  
        {
                 printf ("Error");
                 }
        break;

} 
return 0;
}

