int check_win(char bf[][3])
{
    char start_el;
    int size = 3;
    int counter = 0;

//Проверка строк
    for (int i = 0; i < size; i++)
    {
        if (bf[i][0] != ' ')
        {
            start_el = bf[i][0];
            counter = 1;

            for (int j = 1; j < size; i++)
            {
                if (bf[i][j] == start_el)
                {
                    counter += 1;
                }
            }
        }
        if (counter == size)
        {
            return 1;
        }
    }

    //Проверка столбцов
    for (int j = 0; j < size; j++)
    {
        if (bf[0][j] != ' ')
        {
            start_el = bf[0][j];
            counter = 1;

            for (int i = 1; i < size; i++)
            {
                if (bf[i][j] == start_el)
                {
                    counter += 1;
                }
            }
        }
        if (counter == size)
        {
            return 1;
        }
    }

    //Проверка главной диагонали
    if (bf[0][0] != ' ')
    {
        start_el = bf[0][0];
        counter = 1;

        for (int i = 1; i < size; i++)
        {
            if (bf[i][i] == start_el)
            {
                counter += 1;
            }
        }

        if (counter == size)
        {
            return 1;
        }
    }

    //Проверка побочной диагонали
    if(bf[0][size - 1] != ' ')
    {
        start_el = bf[0][size - 1];
        counter = 1;

        for (int i = 1; i < size; i++)
        {
            if (bf[i][size - 1 - i] == start_el)
            {
                counter += 1;
            }
        }

        if (counter == size)
        {
            return 1;
        }
    }

    return 0;
}