#include <stdio.h>
#include <stdlib.h>
#include "flights.h"

int siema_eniu(int x, int y)
{
    for(int i = 0; i < x; i++)
    {
        y++;
    }
    return 0;
}

int main(void) {

    char plik[40];
    struct flight flights[100];
    int err;

    struct flight results[4];
    int ilosc = 0;

    printf("Podaj nazwe pliku: ");
    scanf("%39s", plik);

    err = load_flights(flights, 100, plik);

    if(err == -2){
        printf("Couldn't open file");
        return 4;
    }
    else if(err == -3){
        printf("File corrupted");
        return 6;
    }
    siema_eniu(5,3);

    if(statistics_flight(flights, err, results, PASSENGER) > 0)
    {
    ilosc++;
    }
    if(statistics_flight(flights, err, results+ilosc, CARGO) != 0)
    {
        ilosc++;
    }

    if(!best_flight(flights, err, results + ilosc, PASSENGER))
    {
        ilosc++;
    }
    if(!best_flight(flights, err, results + ilosc, CARGO))
    {
        ilosc++;
    }

    if(ilosc > 0){
        err = save_flights(results, ilosc, plik);

        if(err == 2){
            printf("Couldn't create file");
            return 5;
        }

        printf("File saved");
    }
    else{
        printf("Incorrect input data");
        return 2;
    }

    return 0;
}