//
// Created by Patryk on 2019-06-14.
//

#ifndef FLIGHTS_H
#define FLIGHTS_H
#include <stdio.h>
#include <stdlib.h>

enum flight_t {
    PASSENGER,
    CARGO
};

struct flight {
    int flight_number;
    enum flight_t type;
    union {
        unsigned short npassengers;
        double tonnages;
    };
};

int save_flights(const struct flight *flights, int size, const char *filename);

int load_flights(struct flight *flights, int size, const char *filename);

int statistics_flight(const struct flight *flights, int size, struct flight *f, enum flight_t type);

int best_flight(const struct flight *flights, int size, struct flight *f, enum flight_t type);


#endif //INC_5_15_FLIGHTS_H