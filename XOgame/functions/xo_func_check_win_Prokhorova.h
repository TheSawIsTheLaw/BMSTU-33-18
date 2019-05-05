#define WIN 1
#define NOT_WIN 0

int check_win(char bf[][DIME])
{
    char start_el;
    int counter;

//Проверка строк
    for (int i = 0; i < DIME; i++)
    {
        if (bf[i][0] != ' ')
        {
            start_el = bf[i][0];
            counter = 1;

            for (int j = 1; j < DIME; i++)
            {
                if (bf[i][j] == start_el)
                {
                    counter += 1;
                }
            }
        }
        if (counter == DIME)
        {
            return WIN;
        }
    }

    //Проверка столбцов
    for (int j = 0; j < DIME; j++)
    {
        if (bf[0][j] != ' ')
        {
            start_el = bf[0][j];
            counter = 1;

            for (int i = 1; i < DIME; i++)
            {
                if (bf[i][j] == start_el)
                {
                    counter += 1;
                }
            }
        }
        if (counter == DIME)
        {
            return WIN;
        }
    }

    //Проверка главной диагонали
    if (bf[0][0] != ' ')
    {
        start_el = bf[0][0];
        counter = 1;

        for (int i = 1; i < DIME; i++)
        {
            if (bf[i][i] == start_el)
            {
                counter += 1;
            }
        }

        if (counter == DIME)
        {
            return WIN;
        }
    }

    //Проверка побочной диагонали
    if(bf[0][DIME - 1] != ' ')
    {
        start_el = bf[0][DIME - 1];
        counter = 1;

        for (int i = 1; i < DIME; i++)
        {
            if (bf[i][DIME - 1 - i] == start_el)
            {
                counter += 1;
            }
        }

        if (counter == DIME)
        {
            return WIN;
        }
    }

    return NOT_WIN;
}