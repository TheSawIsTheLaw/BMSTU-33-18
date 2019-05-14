void make_shot_kovalev(char symb, char BF[][DIME])
{
    char en_symb;
    if (symb == 'X')
        en_symb = 'O';
    else
        en_symb = 'X';
    int res_danger = 0;
    int res_i = 0;
    int res_j = 0;
    int to_left;
    int to_right;
    int to_up;
    int to_down;
    int danger;
    int en_conter;
    int conter;
    int space;
    for (int i = 0; i < DIME; i++)
    {
        printf("\n");
        for(int j = 0; j < DIME; j++)
        {
            if (BF[i][j] == ' ')
            {
                danger = 0;
                to_left = j;
                to_right = DIME - 1 - j;
                to_up = i;
                to_down = DIME - 1 - i;

                en_conter = 0;
                conter = 0;
                space = 0;
                for(int z = 1; z <= to_left; z++)
                {
                    if (BF[i][j - z] == symb)
                        conter++;
                    else
                    {
                        if(BF[i][j - z] == en_symb)
                            en_conter++;
                        else
                            space++;
                    }
                }

                for(int z = 1; z <= to_right; z++)
                {
                    if (BF[i][j + z] == symb)
                        conter++;
                    else
                    {
                        if(BF[i][j + z] == en_symb)
                            en_conter++;
                        else
                            space++;
                    }
                }
                if(conter == DIME - 1)
                    danger+=100;

                if (conter == DIME - 2 && space == 1)
                    danger+=6;

                if (en_conter == DIME - 1)
                    danger+=40;

                if (en_conter == DIME - 2 && space == 1)
                    danger+=4;

                en_conter = 0;
                conter = 0;
                space = 0;
                for(int z = 1; z <= to_up; z++)
                {
                    if (BF[i - z][j] == symb)
                        conter++;
                    else
                    {
                        if(BF[i - z][j] == en_symb)
                            en_conter++;
                        else
                            space++;
                    }
                }

                for(int z = 1; z <= to_down; z++)
                {
                    if (BF[i + z][j] == symb)
                        conter++;
                    else
                    {
                        if(BF[i + z][j] == en_symb)
                            en_conter++;
                        else
                            space++;
                    }
                }

                if(conter == DIME - 1)
                    danger+=100;

                if (conter == DIME - 2 && space == 1)
                    danger+=6;

                if (en_conter == DIME - 1)
                    danger+=40;

                if (en_conter == DIME - 2 && space == 1)
                    danger+=4;


                if(i == j)
                {
                    danger+=1;
                    en_conter = 0;
                    conter = 0;
                    space = 0;
                    for(int z = 1; z <= to_left; z++)
                    {
                        if (BF[i - z][j - z] == symb)
                            conter++;
                        else
                        {
                            if(BF[i - z][j - z] == en_symb)
                                en_conter++;
                            else
                                space++;
                        }
                    }

                    for(int z = 1; z <= to_right; z++)
                    {
                        if (BF[i + z][j + z] == symb)
                            conter++;
                        else
                        {
                            if(BF[i + z][j + z] == en_symb)
                                en_conter++;
                            else
                                space++;
                        }
                    }
                    if(conter == DIME - 1)
                        danger+=100;

                    if (conter == DIME - 2 && space == 1)
                        danger+=6;

                    if (en_conter == DIME - 1)
                        danger+=40;

                    if (en_conter == DIME - 2 && space == 1)
                        danger+=4;
                }

                if(i + j == DIME -1)
                {
                    danger+=1;
                    en_conter = 0;
                    conter = 0;
                    space = 0;
                    for(int z = 1; z <= to_left; z++)
                    {
                        if (BF[i + z][j - z] == symb)
                            conter++;
                        else
                        {
                            if(BF[i + z][j - z] == en_symb)
                                en_conter++;
                            else
                                space++;
                        }
                    }

                    for(int z = 1; z <= to_right; z++)
                    {
                        if (BF[i - z][j + z] == symb)
                            conter++;
                        else
                        {
                            if(BF[i - z][j + z] == en_symb)
                                en_conter++;
                            else
                                space++;
                        }
                    }
                    if(conter == DIME - 1)
                        danger+=100;

                    if (conter == DIME - 2 && space == 1)
                        danger+=6;

                    if (en_conter == DIME - 1)
                        danger+=40;

                    if (en_conter == DIME - 2 && space == 1)
                        danger+=4;
                }

                if (danger >= res_danger)
                {
                    res_danger = danger;
                    res_i = i;
                    res_j = j;
                }
            }
        }
    }
    BF[res_i][res_j] = symb;
}