#include <stdlib.h>
#define N 3

int stroke_counting(int BF[][N])
{
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (BF[i][j] != ' ')
            {
                count++;
            }
        }
    }

    return count;
}

void make_shot_romanov(char symb, int BF[][N])
{
    int turn_number = stroke_counting(BF);

    if (turn_number == 0)
    {
        BF[1][1] = symb;
    }

    else if (turn_number == 1)
    {
        if (BF[1][1] == ' ')
        {
            BF[1][1] = symb;
        }
        else
        {
            BF[0][0] = symb;
        }
    }

    else
    {
        int i_random = 2;
        int j_random = 2;

        while (BF[i_random][j_random] != ' ')
        {
            i_random = rand() % 3;
            j_random = rand() % 3;
        }

        BF[i_random][j_random] = symb;
    }
}

