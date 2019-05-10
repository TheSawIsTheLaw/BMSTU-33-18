#define OK 1
#define NOT_OK 0

int check_situation(char symb, char BF[][DIME], int *i_to_go, int *j_to_go)
{
    int count_space;
    int count_symbol;
    int i;

    //Проверка строк
    for (i = 0; i < DIME; i++)
    {
        count_space = 0;
        count_symbol = 0;
        for (int j = 0; j < DIME; j++)
        {
            if (BF[i][j] == symb)
            {
                count_symbol += 1;
            }
            if (BF[i][j] == ' ')
            {
                *i_to_go = i;
                *j_to_go = j;
                count_space += 1;
            }
        }
        if (count_space == 1 && count_symbol == (DIME - 1))
        {
            return OK;
        }
    }


    //Проверка столбцов
    for(int j = 0; j < DIME; j++)
    {
        count_space = 0;
        count_symbol = 0;
        for(i = 0; i < DIME; i++)
        {
            if (BF[i][j] == symb)
            {
                count_symbol += 1;
            }
            if (BF[i][j] == ' ')
            {
                count_space += 1;
                *i_to_go = i;
                *j_to_go = j;
            }
        }
        if (count_space == 1 && count_symbol == (DIME - 1))
        {
            return OK;
        }
    }

    //Проверка главной диагонали
    count_space = 0;
    count_symbol = 0;
    i = 0;
    while (i < DIME)
    {
        if (BF[i][i] == symb)
        {
            count_symbol += 1;
        }
        if (BF[i][i] == ' ')
        {
            count_space += 1;
            *i_to_go = i;
            *j_to_go = i;
        }
        i += 1;
    }
    if (count_space == 1 && count_symbol == (DIME - 1))
    {
        return OK;
    }

    //Проверка побочной диагонали
    count_space = 0;
    count_symbol = 0;
    i = 0;
    while (i < DIME)
    {
        if (BF[i][DIME - 1 - i] == symb)
        {
            count_symbol += 1;
        }
        if (BF[i][DIME - 1 - i] == ' ')
        {
            count_space += 1;
            *i_to_go = i;
            *j_to_go = DIME - 1 - i;
        }
        i += 1;
    }
    if (count_space == 1 && count_symbol == (DIME - 1))
    {
        return OK;
    }
    return NOT_OK;
}

void make_shot_prokhorova(char symb, char BF[][DIME])
{
    char antisymb = symb == 'X'? 'O' : 'X';
    int i_to_go;
    int j_to_go;
    int flag = NOT_OK;

    if (check_situation(symb, BF, &i_to_go, &j_to_go))
    {
        BF[i_to_go][j_to_go] = symb;
        return;
    }
    
    if (check_situation(antisymb, BF, &i_to_go, &j_to_go))
    {
        BF[i_to_go][j_to_go] = symb;
        return;
    }

    int i = rand() % DIME;
    int j = rand() % DIME;

    while (BF[i][j] != ' ')
    {
        i = rand() % DIME;
        j = rand() % DIME;
    }

    BF[i][j] = symb;
}
