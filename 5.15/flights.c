#include <stdio.h>
#include "flights.h"
#include "tested_declarations.h"
#include "rdebug.h"

int save_flights(const struct flight *flights, int size, const char *filename)
        {

    if(flights == NULL || size <= 0 || filename == NULL)
        return 1;

    FILE *file = fopen(filename, "wb");

    if(file == NULL)
    {
        return 2;
    }

    fwrite(&size, sizeof(int), 1, file);

    if(!fwrite(flights, sizeof(struct flight), size, file)){
        fclose(file);
        return 3;
    }

    fclose(file);
    return 0;
}

int load_flights(struct flight *flights, int size, const char *filename)
{
    if(flights == NULL || size <= 0 || filename == NULL) return -1;
    FILE *file = fopen(filename, "rb");

    if(file == NULL) return -2;

    int size_from_file = 0;
    int res = fread(&size_from_file, sizeof(int), 1, file);

    if(res != 1)
    {
        fclose(file);
        return -3;
    }

    if(size_from_file <= 0)
    {
        fclose(file);
        return -3;
    }
    if(size<size_from_file)
    {
        size_from_file = size;
    }

    res = fread(flights, sizeof(struct flight), size_from_file, file);
    if(res != size_from_file)
    {
        fclose(file);
        return -3;
    }
    fclose(file);

    return size_from_file;
}

int statistics_flight(const struct flight *flights, int size, struct flight *f, enum flight_t type)
{
    if(flights == NULL || size <= 0 || f == NULL)
    {
        return -1;
    }

    f->type = type;


    if(type == PASSENGER){
        f->npassengers = 0;
    }
    else if(type == CARGO){
        f->tonnages = 0;
    }
    else
    {
        return -1;
    }
    int c = 0;
    for(int i = 0; i < size; i++){

        if((flights+i)->type == type){

            if(type == PASSENGER){

                f->npassengers += (flights+i)->npassengers;
            }
            if(type == CARGO){
                if((flights+i)->tonnages < 0) return -1;
                f->tonnages += (flights+i)->tonnages;
            }
            c++;
        }
    }
    if(c<0)
    {
        return -1;
    }
    f->flight_number = c;

    return f->flight_number;

}

int best_flight(const struct flight *flights, int size, struct flight *f, enum flight_t type) {
    if (flights == NULL || size <= 0 || f == NULL) {
        return 1;
    }

    int c = 0;

    f->type = type;
    f->flight_number = 0;

    if (type == PASSENGER) {
        f->npassengers = 0;
    }
    else if (type == CARGO) {
        f->tonnages = 0;
    }
    else
    {
        return 1;
    }

    for (int i = 0; i < size; i++) {

        if ((flights + i)->type == type) {

            if (type == PASSENGER) {
                if (f->npassengers < (flights + i)->npassengers ||
                    (f->npassengers == (flights + i)->npassengers && f->flight_number < (flights + i)->flight_number)) {
                    *f = *(flights + i);
                }
            }

            if (type == CARGO) {
                if ((flights + i)->tonnages < 0) return 1;
                if (f->tonnages < (flights + i)->tonnages ||
                    (f->tonnages == (flights + i)->tonnages &&
                     f->flight_number < (flights + i)->flight_number
                    )) {
                    *f = *(flights + i);
                }
            }
            c++;
        }

    }
    if(c <= 0)
    {
        return 2;
    }
    return 0;
}