#include <stdio.h>
#include<conio.h>
/*

Zadanie 2.
Napisz prosty kalkulator, który pobiera od u¿ytkownika dwie liczby (dowolny typ) i rodzaj operacji (np. dodawanie), okreœlony zaproponowanym typem enum. Napisz funkcjê, która na podstawie typu operacji zwraca wskaŸnik do funkcji wykonuj¹cej tê operacjê. Nastêpnie wywo³aj tê funkcjê (przez jej wskaŸnik), a wynik wyœwietl. 
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

switch (c)   /// dzia³anie 
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

