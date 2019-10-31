#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MOVE 1
#define NO_MOVE 0
int ret[3];
void first_move (char symb, char BF[][DIME])
{
    if(BF[DIME /2][DIME /2] == ' ')
        BF[DIME /2][DIME /2] = symb;
    else
    {
        BF[0][0] = symb;
    }
}
int * check_cols (char symb, char BF[][DIME])
{
    int i,j,k,q;
    for(i = 0; i < 3; i ++)
    {
        ret[i] = 0;
    }
    for(i = 0; i< DIME; i ++)
    {
        k = 0;
        for(j = 0;  j < DIME; j ++)
        {
            if (BF[j][i] != symb && BF[j][i] != ' ')
            {
                k ++;
            }
        }
        if (k == DIME - 1)
        {
            for(q = 0; q < DIME; q ++)
            {
                if(BF[q][i] == ' ')
                {
                    ret[0] = 1;
                    ret[1] = q;
                    ret[2] = i;
                    break;
                }
            }
        }
    }
    return ret;
}
int * check_rows (char symb, char BF[][DIME])
{
    int i,j,k,q;
    for(i = 0; i < 3; i ++)
    {
        ret[i] = 0;
    }
    for(i = 0; i< DIME; i ++)
    {
        k = 0;
        for(j = 0;  j < DIME; j ++)
        {
            if (BF[i][j] != symb && BF[i][j] != ' ')
            {
                k ++;
            }
        }
        if (k == DIME - 1)
        {
            for(q = 0; q < DIME; q ++)
            {
                if(BF[i][q] == ' ')
                {
                    ret[0] = 1;
                    ret[1] = i;
                    ret[2] = q;
                    break;
                }
            }
        }
    }
    return ret;
}
int *check_main_d (char symb, char BF[][DIME])
{
    int i,j,k,q;
    for(i = 0; i < 3; i ++)
    {
        ret[i] = 0;
    }
    for(i = 0; i< DIME; i ++)
    {
        k = 0;
        if (BF[i][i] != symb && BF[i][i] != ' ')
        {
            k ++;
        }
        if (k == DIME - 1)
        {
            for(q = 0; q < DIME; q ++)
            {
                if(BF[q][q] == ' ')
                {
                    ret[0] = 1;
                    ret[1] = q;
                    ret[2] = q;
                    break;
                }
            }
        }
    }
    return ret;
}
int *check_pob_d (char symb, char BF[][DIME])
{
    int i,j,k,q;
    for(i = 0; i < 3; i ++)
    {
        ret[i] = 0;
    }
    for(i = DIME - 1; i>= 0; i --)
    {
        k = 0;
        if (BF[i][i] != symb && BF[i][i] != ' ')
        {
            k ++;
        }
        if (k == DIME - 1)
        {
            for(q = DIME - 1; q >= 0; q --)
            {
                if(BF[q][q] == ' ')
                {
                    ret[0] = 1;
                    ret[1] = q;
                    ret[2] = q;
                    break;
                }
            }
        }
    }
    return ret;
}
void make_shot_saburov(char symb, char BF[][DIME])
{
    int i,j,flag;
    first_move(symb,BF);
    if(*(check_cols(symb,BF)))
    {
        BF[*(check_cols(symb,BF) + 1)][*(check_cols(symb,BF) + 2)] = symb;
    }
    else if(*(check_rows(symb,BF)))
    {
        BF[*(check_rows(symb,BF) + 1)][*(check_rows(symb,BF) + 2)] = symb;
    }
    else if(*(check_main_d(symb,BF)))
    {
        BF[*(check_main_d(symb,BF) + 1)][*(check_main_d(symb,BF) + 2)] = symb;
    }
    else if(*(check_pob_d(symb,BF)))
    {
        BF[*(check_pob_d(symb,BF) + 1)][*(check_pob_d(symb,BF) + 2)] = symb;
    }
    else
    {
        for(i = 0; i < DIME; i ++)
        {
            flag = 0;
            for(j = 0; j < DIME; j ++)
            {
                if (BF[i][j] == ' ')
                {
                    BF[i][j] = symb;
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                break;
            }

        }
    }
}
