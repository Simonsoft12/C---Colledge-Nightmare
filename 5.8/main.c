#include <stdio.h>
#include <math.h>
#include "color.h"


int load_colors_t(const char *filename, struct color_t* p, int N)
{
    if(p == NULL || N<=0 || filename == NULL)
    {
        return -1;
    }

    FILE *file = fopen(filename, "rt");
    if(file == NULL)
    {
        return -2;
    }

    int i = 0;
    int cl;
    for(; i < N; i++)
    {
        int res = fscanf(file, "%u %d", &((p+i)->value) , &cl);
        (p+i)->color = cl;
        if(res != 2 && res != EOF)
        {
            fclose(file);
            return -3;
        }
        if(feof(file)) break;
    }
    fclose(file);
    return i;
}

float distance(const struct color_t* p1, const struct color_t* p2, int *err_code)
{
    if(p1 == NULL || p2 == NULL)
    {
        if(err_code != NULL) *err_code=1;
        return -1;
    }
    float result;
    result = sqrt((p1->r - p2->r)*(p1->r - p2->r)
            + (p1->g - p2->g)*(p1->g - p2->g)
            + (p1->b-p2->b)*(p1->b-p2->b));

    if(err_code != NULL) *err_code=0;
    return result;
}

enum colors find_nearest_neighbour(const struct color_t* database, int size,
                                   const struct color_t* unknown, int *err_code)
{
    if(database == NULL || size <= 0 || unknown == NULL)
    {
        if(err_code != NULL) *err_code=1;
        return UNKNOWN;
    }
    int err = 0;
    float result = distance(unknown, database, &err);
    enum colors save_type = database->color;
    int check = 0;
    for(int i = 1 ; i < size ; i++)
    {

        float result_temp = distance(unknown, (database + i), &err);
//        if(err == 1)
//        {
//            if(err_code != NULL) *err_code=2;
//            return UNKNOWN;
//
//        }
        if(result_temp == result && (database+i)->color != save_type)
        {
            check++;
        }
        if(result_temp < result)
        {
            check = 0;
            result = result_temp;
            save_type = (database+i)->color;
        }
    }
    if(check != 0)
    {
        if(err_code != NULL)
        {
            *err_code=2;
        }
        return UNKNOWN;
    }

    if(save_type == 1)
    {
        if(err_code != NULL) *err_code=0;
        return RED;
    }
    else if(save_type == 2)
    {
        if(err_code != NULL) *err_code=0;
        return GREEN;
    }
    else if(save_type == 3)
    {
        if(err_code != NULL) *err_code=0;
        return BLUE;
    }
    else if(save_type == 4)
    {
        if(err_code != NULL) *err_code=0;
        return YELLOW;
    }
    else
    {
        if(err_code != NULL) *err_code=2;
        return UNKNOWN;
    }
}

int main() {
    char file[31];
    int err_code = 0;
    struct color_t colors[100];
    struct color_t *wsk = colors;
    printf("Enter file name:\n");
    scanf("%30[^\n]s", file);
    while(getchar()!='\n');
    int col_cnt = load_colors_t(file, wsk, 100);
    if(col_cnt == -1)
    {
        printf("Couldn't open file");
        return 4;
    }

    if(col_cnt == -2)
    {
        printf("Couldn't open file");
        return 4;
    }

    if(col_cnt == -3)
    {
        printf("File corrupted");
        return 6;
    }

    while(1)
    {
        struct color_t color;
        printf("Enter a color as four values (R, G, B, A):");
//        res = scanf("%hhu", &color.r);
//        if(res != 1)
//        {
//            printf("Incorrect input");
//            break;
//        }
//
//        res = scanf("%hhu", &color.g);
//        if(res != 1)
//        {
//            printf("Incorrect input");
//            break;
//        }
//
//        res = scanf("%hhu", &color.b);
//        if(res != 1)
//        {
//            printf("Incorrect input");
//            break;
//        }
//
//        res = scanf("%hhu", &color.a);
//        if(res != 1)
//        {
//            printf("Incorrect input");
//            break;
//        }
        int res = scanf("%hhu %hhu %hhu %hhu", &color.r, &color.g, &color.b, &color.a);
        if(res != 4)
        {
            printf("Incorrect input\n");
            break;
        }
        enum colors type;
        type = find_nearest_neighbour(wsk, col_cnt, &color, &err_code);

        if(type == RED)
        {
            printf("RED\n");
        }

        if(type == GREEN)
        {
            printf("GREEN\n");
        }

        if(type == BLUE)
        {
            printf("BLUE\n");
        }

        if(type == YELLOW)
        {
            printf("YELLOW\n");
        }

        if(type == UNKNOWN)
        {
            printf("UNKNOWN\n");
        }
    }
    return 0;
}