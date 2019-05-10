int anti_cheat(int n, char before[][DIME], char after[][DIME])
{
    int x_cord[DIME * DIME];
    int y_cord[DIME * DIME];
    int n_x_y = 0;
    int cur = 0;
    int N = n;
    
    // находим заполненные клетки до последнего хода
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (before[i][j] == 'X' || before[i][j] == 'O')
            {
                x_cord[n_x_y] = i;
                y_cord[n_x_y] = j;
                n_x_y++;
            }
    }
    
    // находим кол-во заполненных клеток после последнего хода, а также проверяем, что новый ход корректен
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (after[i][j] == 'X' || after[i][j] == 'O')
                cur++;
            if (after[i][j] != 'X' && after[i][j] != 'O' && after[i][j] != ' ')
                return 1;
        }
    }
    
    // проверям, что был сделан только один ход
    if (cur - n_x_y != 1)
        return 1;
    
    // проверяем, что ранне введенные данные не были изменены
    for (int i = 0; i < n_x_y; i++)
        if (before[x_cord[i]][y_cord[i]] != after[x_cord[i]][y_cord[i]])
            return 1;
    return 0;
}
