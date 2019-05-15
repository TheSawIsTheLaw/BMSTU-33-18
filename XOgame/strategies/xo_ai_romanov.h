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
        char second;
        if (symb == 'X')
        {
            second = 'O';
        }
        else
        {
            second = 'X';
        }

        for (int i = 0; i < DIME; i++)
        {
            int count = 0;
            for (int j = 0; j < DIME; j++)
            {
                if (BF[i][j] == second)
                {
                    ++count;
                }
            }
            if (DIME - 1 == count)
            {
                int k = 0;
                int checker = 0;
                while (BF[i][k] != ' ' && k < DIME)
                {
                    ++k;
                    checker = 1;
                }
                if (checker || BF[i][k] == ' ')
                {
                    if (k <= (DIME - 1))
                    {
                        BF[i][k] = symb;
                        return;
                    }
                }
            }
        }

        for (int i = 0; i < DIME; i++)
        {
            int count = 0;
            for (int j = 0; j < DIME; j++)
            {
                if (BF[j][i] == second)
                {
                    ++count;
                }
            }
            if (DIME - 1 == count)
            {
                int k = 0;
                int checker = 0;
                while (BF[k][i] != ' ' && k < DIME)
                {
                    ++k;
                    checker = 1;
                }
                if (checker || BF[k][i] == ' ')
                {
                    if (k <= (DIME - 1))
                    {
                        BF[k][i] = symb;
                        return;
                    }
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < DIME; i++)
        {
            if (BF[i][i] == second)
            {
                ++count;
            }

            if (DIME - 1 == count)
            {
                int k = 0;
                int checker = 0;
                while (BF[k][k] != ' ' && k < DIME)
                {
                    ++k;
                    checker = 1; 
                }
                if (checker || BF[k][k] == ' ')
                {
                    if (k <= (DIME - 1))
                    {
                        BF[k][k] = symb;
                        return;
                    }
                }
            }
        }
        
        count = 0;
        for (int i = 1; i <= DIME; i++)
        {
            if (BF[i - 1][DIME - i] == second)
            {
                ++count;
            }

            if (DIME - 1 == count)
            {
                int k = 1;
                int checker = 0;
                while (BF[k - 1][DIME - k] != ' ' && k <= DIME)
                {
                    ++k;
                    checker = 1;
                }
                if (checker || BF[k - 1][DIME - k] == ' ')
                {
                    if (k <= DIME)
                    {
                        BF[k - 1][DIME - k] = symb;
                        return;
                    }
                }
            }
        }

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
