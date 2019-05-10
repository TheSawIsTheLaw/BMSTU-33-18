#include <stdlib.h>

int stroke_counting(char BF[][DIME])
{
    int count = 0;

    for (int i = 0; i < DIME; i++)
    {
        for (int j = 0; j < DIME; j++)
        {
            if (BF[i][j] != ' ')
            {
                count++;
            }
        }
    }

    return count;
}

void make_shot_romanov(char symb, char BF[][DIME])
{
    int turn_number = stroke_counting(BF);

    if (0 == turn_number)
    {
        BF[DIME / 2][DIME / 2] = symb;
    }

    else if (1 == turn_number)
    {
        if (BF[DIME / 2][DIME / 2] == ' ')
        {
            BF[DIME / 2][DIME / 2] = symb;
        }
        else
        {
            BF[0][0] = symb;
        }
    }

    else
    {
        int i_random = DIME - 1;
        int j_random = DIME - 1;

        while (BF[i_random][j_random] != ' ')
        {
            i_random = rand() % DIME;
            j_random = rand() % DIME;
        }

        BF[i_random][j_random] = symb;
    }
}
