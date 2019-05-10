/* Функция makeshot от Якуба */
/* Более сложный простейший бот с проверкой на наличие в ячейке значения */

#include <stdlib.h>
#include <time.h>

void make_shot_yakuba_harder(char type, int x, char field[][x], int y)
{
    int i, j, k = 0;
    srand(time(NULL));
    i = (rand() % x);
    j = (rand() % y);
    while (field[i][j] != ' ')
    {
        k += 1;
        srand(time(NULL));
        i = (0 + rand() % x);
        j = (0 + rand() % y);
        if (k == 666)
            break;
    }
    if (k == 666)
    {
        for (int q = 0; q < x; q++)
        {
            for (int w = 0; w < y; w++)
                if (field[q][w] == ' ')
                {
                    field[q][w] = type;
                    k = 665;
                    break;
                }
            if (k == 665)
                break;
        }
    }
    else
        field[i][j] = type;
}
