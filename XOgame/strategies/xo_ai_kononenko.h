#include <stdlib.h>

void make_shot_kononenko(const char symb, char BF[][DIME])
{
    int random_coord_x = rand() % DIME;
    int random_coord_y = rand() % DIME;

    while (BF[random_coord_x][random_coord_y] != ' ')
        random_coord_x = rand() % DIME;

    BF[random_coord_x][random_coord_y] = symb;
}