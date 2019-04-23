#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TURN_END 1
#define NO_EASY 0
#define NEW_TURN 1
#define GAME_END 1
#define GOOD 1
#define NO_GOOD 0
#define NO_PASSIVE_DEF 0


int defense(char sign, char bf[][3]);

void place_str(char sign, char bf[][3], int index)
{
    for (int j = 0; j < 3; j++)
        if (bf[index][j] == ' ')
            bf[index][j] = sign;
}

void place_col(char sign, char bf[][3], int index)
{
    for (int i = 0; i < 3; i++)
        if (bf[i][index] == ' ')
            bf[i][index] = sign;
}

void place_diag(char sign, char bf[][3])
{
    for (int i = 0; i < 3; i++)
        if (bf[i][i] == ' ')
            bf[i][i] = sign;
}

void place_diag_fake(char sign, char bf[][3])
{
    for (int i = 0; i < 3; i++)
        if (bf[i][2 - i] == ' ')
            bf[i][2 - i] = sign;
}

int easy(char sign, char bf[][3])
{
    char antisign = (sign == 'X') ? 'O' : 'X';
    int home_total = 0;
    int rival_total = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            if (bf[i][j] == sign)
                home_total++;
            else if (bf[i][j] == antisign)
                rival_total++;
        if (home_total == 2 && rival_total == 0)
        {
            place_str(sign, bf, i);
            return NEW_TURN;
        }
        else if (home_total == 0 && rival_total == 2)
        {
            place_str(sign, bf, i);
            return NEW_TURN;
        }
        home_total = 0;
        rival_total = 0;
    }

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
            if (bf[i][j] == sign)
                home_total++;
            else if (bf[i][j] == antisign)
                rival_total++;
        if (home_total == 2 && rival_total == 0)
        {
            place_col(sign, bf, j);
            return NEW_TURN;
        }
        else if (home_total == 0 && rival_total == 2)
        {
            place_col(sign, bf, j);
            return NEW_TURN;
        }
        home_total = 0;
        rival_total = 0;
    }
    
    for (int i = 0; i < 3; i++)
        if (bf[i][i] == sign)
            home_total++;
        else if (bf[i][i] == antisign)
            rival_total++;
    if (home_total == 2 && rival_total == 0)
    {
        place_diag(sign, bf);
        return NEW_TURN;
    }
    else if (home_total == 0 && rival_total == 2)
    {
        place_diag(sign, bf);
        return NEW_TURN;
    }
    home_total = 0;
    rival_total = 0;
        
    for (int i = 0; i < 3; i++)
        if (bf[i][2 - i] == sign)
            home_total++;
        else if (bf[i][2 - i] == antisign)
            rival_total++;
    if (home_total == 2 && rival_total == 0)
    {
        place_diag_fake(sign, bf);
        return NEW_TURN;
    }
    else if (home_total == 0 && rival_total == 2)
    {
        place_diag_fake(sign, bf);
        return NEW_TURN;
    }
    return NO_EASY;
}

int no_x_fence(char bf[][3])
{
    if (bf[0][2] != 'X' && bf[0][0] != 'X' && bf[2][2] != 'X' && bf[2][0] != 'X')
        return GOOD;
    return NO_GOOD;
}

int no_diag_x(char bf[][3])
{
    if (bf[2][2] == ' ')
        return GOOD;
    return NO_GOOD;
}

int diag_on_base(char bf[][3])
{
    if (bf[0][2] == ' ')
    {
        bf[0][2] = 'X';
        return GOOD;
    }
    else if (bf[2][0] == ' ')
    {
        bf[2][0] = 'X';
        return GOOD;
    }
    return NO_GOOD;
}

int do_random_move(char sign, char bf[][3])
{
    int no_empty = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (bf[i][j] == ' ')
                no_empty = 0;
    if (no_empty)
        return GAME_END;
    srand(time(NULL));
    int i = 1;
    int j = 1;
    while (bf[i][j] != ' ')
    {
        i = rand() % 3;
        j = rand() % 3;
    }
    bf[i][j] = sign;
        return NEW_TURN;
               
}

int attack(char bf[][3])
{
    if (easy('X',bf))
        return TURN_END;
    else if (defense('X', bf))
        return TURN_END;
    else if (no_x_fence(bf))
    {
        bf[0][0] = 'X';
        return TURN_END;
    }
    else if (no_diag_x(bf))
    {
        bf[2][2] = 'X';
        return TURN_END;
    }
    else if (diag_on_base(bf))
        return TURN_END;    
    do_random_move('X', bf);
    return TURN_END;   
}

int defense(char sign, char bf[][3])
{
    if (sign == 'O')
    {
        if (easy(sign, bf))
            return TURN_END;
        else
        {
            do_random_move(sign, bf);
            return TURN_END;
        }
    }
    else
        if (easy(sign, bf))
            return TURN_END;
    return NO_PASSIVE_DEF;
}

void make_shot_krivozubov(char sign, char field[][3])
{
    if (sign == 'X')
        attack(field);
    else
        defense('O',field);
}

