//
// Created by Patryk on 2019-05-30.
//

#ifndef COLOR_H
#define COLOR_H



struct color_t
{
    union
    {
        unsigned int value;

        struct{
            unsigned char r;
            unsigned char g;
            unsigned char b;
            unsigned char a;
        };
    };

    enum colors
    {
        RED = 1,
        GREEN,
        BLUE,
        YELLOW,
        UNKNOWN
    } color;

};
#endif //INC_5_8_COLOR_H