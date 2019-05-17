// функция возвращает 1 - читерства не было
// функция возвращает 0 - читерство было

#define ZERO 0
#define NO_ERROR 1
#define ERROR 0

int anti_cheat(int n, char before[][DIME], char after[][DIME])
{
    static char old_sym = ' ';
    static char new_sym = ' ';
    int x_cord[DIME * DIME];
    int y_cord[DIME * DIME];
    int n_x_y = 0;
    int cur = 0;
    int N = n;
    int temp = 0;

    // Находим заполненные клетки до последнего хода
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
    
    if (n_x_y == 0)
    {
        old_sym = ' ';
        new_sym = ' ';
    }
    
    // Находим кол-во заполненных клеток после последнего хода, а также проверяем, что новый ход корректен
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
    
    // Проверям, что был сделан только один ход
    if (cur - n_x_y != 1)
        return ERROR;
    
    // Проверяем, что ранее введенные данные не были изменены
    for (int i = ZERO; i < n_x_y; i++)
        if (before[x_cord[i]][y_cord[i]] != after[x_cord[i]][y_cord[i]])
            return ERROR;

    // Проверяем, какой символ был добавлен и сравнение его с предыдущим  
    for (int i = ZERO; i < N; i++)
        for (int j = ZERO; i < N; j++)
        {
            if ((after[i][j] == 'X' || after[i][j] == 'O') && (after[i][j] != before[i][j]))
            {
                old_sym = new_sym;
                new_sym = after[i][j];
                if (new_sym == old_sym)
                    return ERROR;
                else
                    return NO_ERROR;
            }
        }
    
    return NO_ERROR;
}
