#include <stdio.h>
#include <stdlib.h>

int add(const int *first, const int *second, int* result);
int subtract(const int *first, const int *second, int* result);
int multiply(const int *first, const int *second, int* result);
int divide(const int *first, const int *second, float* result);

int main()
{
    int i, n,suma,minus,mnoz;
    float podziel;
    
    printf("Podaj pierwsza liczbe\n");
    scanf("%d", &i);
    printf("Podaj druga liczbe\n");
    scanf("%d", &n);

    
    add(&i, &n, &suma);
    subtract(&i, &n, &minus);
    multiply(&i, &n, &mnoz);
    divide(&i, &n, &podziel);

    printf("%d\n", suma);
    printf("%d\n", minus);
    printf("%d\n", mnoz);
    if(n == 0) printf("Error");
    else printf("%f\n", podziel);
         
    return 0;
}

int add(const int *first, const int *second, int* result)
    {
        if(first == NULL || second == NULL || result == NULL) return 1; 
        {
            *result = (*first)+(*second);
            return 1;
        }
    }
int subtract(const int *first, const int *second, int* result)
    {
        if(first == NULL || second == NULL || result == NULL) return 1; 
        {
            *result = (*first)-(*second);
            return 1;
        }
    }
int multiply(const int *first, const int *second, int* result)
    {
        if(first == NULL || second == NULL || result == NULL) return 1;
        {
            *result = (*first)*(*second);
            return 1;
        }
    }
int divide(const int *first, const int *second, float* result)
    {
        if(first == NULL || second == NULL || result == NULL || *second == 0) return 1;
        {
            *result = (float)(*first)/(*second);
            return 1;
        }
    }

