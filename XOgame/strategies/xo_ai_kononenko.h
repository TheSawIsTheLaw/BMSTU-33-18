#define GOOD 1
#define BAD 0

int check_row_sk(char symb, char BF[][DIME])
{
    for (int i = 0; i < DIME; i++)
        for (int j = 0; j < DIME; j++)
            if (BF[i][j] == ' ')
            {
                BF[i][j] = symb;
                return GOOD;
            }
    return BAD;
}

int check_col_sk(char symb, char BF[][DIME])
{
    for (int j = 0; j < DIME; j++)
        for (int i = 0; i < DIME; i++)
            if (BF[i][j] == ' ')
            {
                BF[i][j] = symb;
                return GOOD;
            }
    return BAD;
}

int check_side_diag_sk(char symb, char BF[][DIME])
{
    for (int i = 1; i <= DIME; i++)
        if (BF[i - 1][DIME - i] == ' ')
        {
            BF[i - 1][DIME - i] = symb;
            return GOOD;
        }
    return BAD;
}

int check_main_diag_sk(char symb, char BF[][DIME])
{
    for (int i = 0; i < DIME; i++)
        if (BF[i][i] == ' ')
        {
            BF[i][i] = symb;
            return GOOD;
        }
    return BAD;
}

void make_shot_kononenko(char symb, char BF[][DIME])
{
    if (check_main_diag_sk(symb, BF))
        return;
    if (check_side_diag_sk(symb, BF))
        return;
    if (check_col_sk(symb, BF))
        return;
    if (check_row_sk(symb, BF))
        return;
}
