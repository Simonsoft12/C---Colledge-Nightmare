#include <stdio.h>
#include <stdlib.h>

struct bits_t
{
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
};

union bit_set
{
    unsigned int a;

    struct slowo_t
    {
        unsigned short s1;
        unsigned short s2;
    }slowo;

    struct char_t
    {
        unsigned char b1;
        unsigned char b2;
        unsigned char b3;
        unsigned char b4;
    }fbajt;

    struct bits_t bity[4];

};


int main() {
    union bit_set bytes;

    printf("Podaj liczbe: ");
    unsigned int number = 0;
    int res = scanf("%u", &number);
    if(res != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    bytes.a = number;
    printf("%u\n", bytes.a);
    printf("%u %u\n", bytes.slowo.s1, bytes.slowo.s2);
    printf("%u %u %u %u\n", bytes.fbajt.b1, bytes.fbajt.b2, bytes.fbajt.b3, bytes.fbajt.b4);
    for(int i = 0; i<4 ; i++)
    {
        printf("%u%u%u%u%u%u%u%u ", (bytes.bity+i)->b7, (bytes.bity+i)->b6, (bytes.bity+i)->b5, (bytes.bity+i)->b4,
               (bytes.bity+i)->b3, (bytes.bity+i)->b2, (bytes.bity+i)->b1, (bytes.bity+i)->b0);
    }

    return 0;
}