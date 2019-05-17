// функция возвращает 1 - читерства не было
// функция возвращает 0 - читерство было

#define ZERO 0
#define NO_ERROR 1
#define ERROR 0

int anti_cheat(int n, char before[][DIME], char after[][DIME])
{
    int x_cord[DIME * DIME];
    int y_cord[DIME * DIME];
    int n_x_y = ZERO;
    int cur = ZERO;
    int N = n;
    
    // находим заполненные клетки до последнего хода
    for (int i = ZERO; i < N; i++)
    {
        for (int j = ZERO; j < N; j++)
            if (before[i][j] == 'X' || before[i][j] == 'O')
            {
                x_cord[n_x_y] = i;
                y_cord[n_x_y] = j;
                n_x_y++;
            }
    }
    
    // находим кол-во заполненных клеток после последнего хода, а также проверяем, что новый ход корректен
    for (int i = ZERO; i < N; i++)
    {
        for (int j = ZERO; j < N; j++)
        {
            if (after[i][j] == 'X' || after[i][j] == 'O')
                cur++;
            if (after[i][j] != 'X' && after[i][j] != 'O' && after[i][j] != ' ')
                return ERROR;
        }
    }
    
    // проверям, что был сделан только один ход
    if (cur - n_x_y != 1)
        return ERROR;
    
    // проверяем, что ранне введенные данные не были изменены
    for (int i = ZERO; i < n_x_y; i++)
        if (before[x_cord[i]][y_cord[i]] != after[x_cord[i]][y_cord[i]])
            return ERROR;
    return NO_ERROR;
}
