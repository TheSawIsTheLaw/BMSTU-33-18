/* Функция makeshot от Якуба */
/* Бот для самых маленьких или тех, кто желает побеждать всегда */

#include <stdlib.h>
#include <time.h>

int make_shot_yakuba(char type, char field[][3])
{
    int i, j;
    srand(time(NULL));
    i = (rand() % 3);
    j = (rand() % 3);
    field[i][j] == type;
    return 0;
}