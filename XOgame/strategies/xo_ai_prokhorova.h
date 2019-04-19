#define OK 1
#define NOT_OK 0


int count_symb(char symb, char BF[][3])
{
    int counter = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if (BF[i][j] == symb)
            {
                counter += 1;
            }
        }
    }
    return counter;
}

int check_situation(char symb, char BF[][3], int *i_to_go, int *j_to_go)
{
    //Проверка строк
    for(int i = 0; i < 3; i++)
    {
        if (BF[i][0] == symb && BF[i][1] == symb && BF[i][2] == ' ')
        {
            *i_to_go = i;
            *j_to_go = 2;
            return OK;
        }

        if (BF[i][0] == symb && BF[i][2] == symb && BF[i][1] == ' ')
        {
            *i_to_go = i;
            *j_to_go = 1;
            return OK;

        }

        if (BF[i][1] == symb && BF[i][2] == symb && BF[i][0] == ' ')
        {
            *i_to_go = i;
            *j_to_go = 0;
            return OK;
        }
    }


    //Проверка столбцов
    for(int j = 0; j < 3; j++)
    {
        if (BF[0][j] == symb && BF[1][j] == symb && BF[2][j] == ' ')
        {
            *i_to_go = 2;
            *j_to_go = 0;
            return OK;
        }

        if (BF[1][j] == symb && BF[2][j] == symb && BF[0][j] == ' ')
        {
            *i_to_go = 0;
            *j_to_go = j;
            return OK;
        }

        if (BF[2][j] == symb && BF[0][j] == symb && BF[1][j] == ' ')
        {
            *i_to_go = 1;
            *j_to_go = j;
            return OK;
        }
    }

    //Проверка главной диагонали
    if (BF[0][0] == symb && BF[1][1] == symb && BF[2][2] == ' ')
    {
        *i_to_go = 2;
        *j_to_go = 2;
        return OK;
    }

    if (BF[0][0] == symb && BF[2][2] == symb && BF[1][1] == ' ')
    {
        *i_to_go = 1;
        *j_to_go = 1;
        return OK;
    }

    if (BF[1][1] == symb && BF[2][2] == symb && BF[0][0] == ' ')
    {
        *i_to_go = 0;
        *j_to_go = 0;
        return OK;
    }

    //Проверка побочной диагонали

    if (BF[0][2] == symb && BF[1][1] == symb && BF[2][0] == ' ')
    {
        *i_to_go = 2;
        *j_to_go = 0;
        return OK;
    }

    if (BF[0][2] == symb && BF[2][0] == symb && BF[1][1] == ' ')
    {
        *i_to_go = 1;
        *j_to_go = 1;
        return OK;
    }

    if (BF[1][1] == symb && BF[2][0] == symb && BF[0][2] == ' ')
    {
        *i_to_go = 0;
        *j_to_go = 2;
        return OK;
    }
    return NOT_OK;

}

void make_shot_prokhorova(char symb, char BF[][3])
{
    char antisymb = symb == 'X'? 'O' : 'X';
    int i_to_go;
    int j_to_go;
    int flag = NOT_OK;

    if (check_situation(symb, BF, &i_to_go, &j_to_go) == OK)
    {
        BF[i_to_go][j_to_go] = symb;
    }
    else
    {
        if (check_situation(antisymb, BF, &i_to_go, &j_to_go) == OK)
        {
            BF[i_to_go][j_to_go] = symb;
        }
        else
        {
            int i = 0;
            int j = 0;
            while (i < 3 && flag == NOT_OK)
            {
                j = 0;
                while(j < 3 && flag == NOT_OK)
                {
                    if (BF[i][j] == ' ')
                    {
                        BF[i][j] = symb;
                        flag = OK;
                    }
                    j += 1;
                }
                i += 1;
            }

        }
    }
}