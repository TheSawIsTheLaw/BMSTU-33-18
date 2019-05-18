//Функция, вставляющая элемент в свободную клетку поля
void make_shot_namestnik(char insert, char field[][DIME])
{
    int flag = 0;
    int i, j;
    
    for (i = 0; i < DIME; i++)
    {
        for (j = 0; j < DIME; j++)
            if (field[i][j] == ' ')
            {
                field[i][j] = insert;
                flag = 1;
                break;
            }
        if (flag)
            break;
    }
}
