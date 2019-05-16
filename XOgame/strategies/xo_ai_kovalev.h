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
    int dig_power = 3;
    for (int i = 0; i < DIME - 3; i++)
        dig_power = (dig_power * 3 + 2) * 3 + 2;

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

                int new_d = 0;
                if (conter == 0)
                {
                    new_d = 1;
                    for (int wei = 1; wei < en_conter; wei++)
                    {
                        new_d = (new_d * 3 + 2) * 3 + 2;
                    }
                }

                if (en_conter == 0)
                {
                    new_d = 5;
                    for (int wei = 1; wei < conter; wei++)
                    {
                        new_d = (new_d * 3 + 2) * 3 + 2;
                    }
                }
                danger+=new_d;

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
                new_d = 0;
                if (conter == 0)
                {
                    new_d = 1;
                    for (int wei = 1; wei < en_conter; wei++)
                    {
                        new_d = (new_d * 3 + 2) * 3 + 2;
                    }
                }

                if (en_conter == 0)
                {
                    new_d = 5;
                    for (int wei = 1; wei < conter; wei++)
                    {
                        new_d = (new_d * 3 + 2) * 3 + 2;
                    }
                }
                danger+=new_d;


                if(i == j)
                {
                    danger+=dig_power;
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
                    new_d = 0;
                    if (conter == 0)
                    {
                        new_d = 1;
                        for (int wei = 1; wei < en_conter; wei++)
                        {
                            new_d = (new_d * 3 + 2) * 3 + 2;
                        }
                    }

                    if (en_conter == 0)
                    {
                        new_d = 5;
                        for (int wei = 1; wei < conter; wei++)
                        {
                            new_d = (new_d * 3 + 2) * 3 + 2;
                        }
                    }
                    danger+=new_d;
                }

                if(i + j == DIME -1)
                {
                    danger+=dig_power;
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
                    new_d = 0;
                    if (conter == 0)
                    {
                        new_d = 1;
                        for (int wei = 1; wei < en_conter; wei++)
                        {
                            new_d = (new_d * 3 + 2) * 3 + 2;
                        }
                    }

                    if (en_conter == 0)
                    {
                        new_d = 5;
                        for (int wei = 1; wei < conter; wei++)
                        {
                            new_d = (new_d * 3 + 2) * 3 + 2;
                        }
                    }
                    danger+=new_d;
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
    en_conter = 0;
    conter = 0;
    int i_en = 0;
    int j_en = 0;
    for (int i = 0; i < DIME; i++)
        for(int j = 0; j < DIME; j++)
        {
            if (BF[i][j] == symb)
                conter++;
            if (BF[i][j] == en_symb)
            {
                en_conter++;
                i_en = i;
                j_en = j;
            }
        }

    if (en_conter == 1 && conter == 0 && DIME == 3)
    {
        if (i_en == 0 && j_en == 0)
            BF[0][1] = symb;

        else if (i_en == DIME - 1 && j_en == 0)
            BF[DIME - 1][1] = symb;

        else if (i_en == 0 && j_en == DIME - 1)
            BF[1][DIME - 1] = symb;

        else if (i_en == DIME - 1 && j_en == DIME - 1)
            BF[DIME - 2][DIME - 1] = symb;

        else
            BF[res_i][res_j] = symb;

    }
    else
    {
        en_conter = 0;
        for (int i = 0; i < DIME - 2; i++)
        {
            if (BF[DIME - 1][i] == en_symb)
                en_conter++;
            if (BF[DIME - 1 - i][i] == en_symb)
                en_conter++;
            if (BF[DIME - 1][i] == symb)
                conter++;
            if (BF[DIME - 1 - i][i] == symb)
                conter++;
        }

        if (en_conter == 0 && danger < 750 && conter != 0 && DIME > 4)
        {
            int postavil = 0;
            for (int i = DIME / 2; i < DIME; i++)
            {
                if (BF[DIME - 1 - i][i] == ' ')
                {
                    BF[DIME - 1 - i][i] = symb;
                    postavil = 1;
                    break;
                }
                if (BF[DIME - 1][i] == ' ')
                {
                    BF[DIME - 1][i] = symb;
                    postavil = 1;
                    break;
                }
            }
            if (!postavil)
                BF[res_i][res_j] = symb;

        }
        else
        {
            BF[res_i][res_j] = symb;
        }

    }
}