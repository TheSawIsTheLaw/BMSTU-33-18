#include <stdlib.h>
#define N 3

int stroke_counting(char BF[][N])
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

void make_shot_romanov(char symb, char BF[][N])
{
    int turn_number = stroke_counting(BF);

    if (0 == turn_number)
    {
        BF[N / 2][N / 2] = symb;
    }

    else if (1 == turn_number)
    {
        if (BF[N / 2][N / 2] == ' ')
        {
            BF[N / 2][N / 2] = symb;
        }
        else
        {
            BF[0][0] = symb;
        }
    }

    else
    {
        int i_random = N - 1;
        int j_random = N - 1;

        while (BF[i_random][j_random] != ' ')
        {
            i_random = rand() % N;
            j_random = rand() % N;
        }

        BF[i_random][j_random] = symb;
    }
}
