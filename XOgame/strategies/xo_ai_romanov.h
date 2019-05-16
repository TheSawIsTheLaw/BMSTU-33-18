#include <stdlib.h>
#define MOVE 1
#define NO_MOVE 0

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

int move_horizontale(char BF[][DIME], const int i, const char symb)
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
            return MOVE;
        }
    }
    return NO_MOVE;
}

int move_verticale(char BF[][DIME], const int i, const char symb)
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
            return MOVE;
        }
    }
    return NO_MOVE;
}


int move_main_diag(char BF[][DIME], const char symb)
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
            BF[k][k] = MOVE;
            return OK;
        }
    }
    return NO_MOVE;
}

int move_incid_diag(char BF[][DIME], const char symb)
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
            BF[k - 1][DIME -k] = symb;
            return MOVE;
        }
    }
    return NO_MOVE;
}

int lookup_horizontale(char BF[][DIME], const char symb)
{
    for (int i = 0; i < DIME; i++)
    {
        int count = 0;
        for (int j = 0; j < DIME; j++)
        {
            if (BF[i][j] == symb)
            {
                ++count;
            }
        }
        if (DIME - 1 == count)
        {
            const int move = move_horizontale(BF, i, symb);
            if (move)
            {
                return MOVE;
            }
        }
    }
    return NO_MOVE;
}

int lookup_verticale(char BF[][DIME], const char symb)
{
    for (int i = 0; i < DIME; i++)
    {
        int count = 0;
        for (int j = 0; j < DIME; j++)
        {
            if (BF[j][i] == symb)
            {
                ++count;
            }
        }
        if (DIME - 1 == count)
        {
            const int move = move_horizontale(BF, i, symb);
            if (move)
            {
                return MOVE;
            }
        }
    }
    return NO_MOVE;
}


int lookup_main_diag(char BF[][DIME], const char symb)
{
    int count = 0;
    for (int i = 0; i < DIME; i++)
    {
        if (BF[i][i] == symb)
        {
            ++count;
        }
    }
    if (DIME - 1 == count)
    {
        const int move = move_main_diag(BF, symb);
        if (move)
        {
            return MOVE;
        }
    }
    return NO_MOVE;
}


int lookup_incid_diag(char BF[][DIME], const char symb)
{
    int count = 0;
    for (int i = 1; i <= DIME; i++)
    {
        if (BF[i - 1][DIME - i] == symb)
        {
            ++count;
        }
    }
    if (DIME - 1 == count)
    {
        const int move = move_incid_diag(BF, symb);
        if (move)
        {
            return MOVE;
        }
    }
    return NO_MOVE;
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
        char second_symb;
        if (symb == 'X')
        {
            second_symb = 'O';
        }
        else
        {
            second_symb = 'X';
        }
        
        // DEFENCE
        // HORIZONTAL LOOKUP (DEFENCE)
        int move = lookup_horizontale(BF, second_symb);
        if (move)
        {
            return;
        }
        // VERTICAL LOOKUP (DEFENCE)
        move = lookup_verticale(BF, second_symb);
        if (move)
        {
            return;
        }
        // MAIN DIAG LOOKUP (DEFENCE)
        move = lookup_main_diag(BF, second_symb);
        if (move)
        {
            return;
        }
        // INCIDENTAL DIAG LOOKUP (DEFENCE)
        move = lookup_incid_diag(BF, second_symb); 
        if (move)
        {
            return;
        }
        
        // ATTACK RAXES
        // HORIZONTAL LOOKUP (ATTACK)
        move = lookup_horizontale(BF, symb);
        if (move)
        {
            return;
        }
        // VERTICAL LOOKUP (ATTACK)
        move = lookup_verticale(BF, symb);
        if (move)
        {
            return;
        }
        // MAIN DIAG LOOKUP (ATTACK)
        move = lookup_main_diag(BF, symb);
        if (move)
        {
            return;
        }
        // INCIDENTAL DIAG LOOKUP (ATTACK)
        move = lookup_incid_diag(BF, symb); 
        if (move)
        {
            return;
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
