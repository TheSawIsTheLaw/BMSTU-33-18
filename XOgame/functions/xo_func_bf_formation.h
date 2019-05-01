void bf_formation(int DIME, char mtx[][DIME])
{
    for (int i = 0; i < DIME; i++)
        for (int j = 0; j < DIME; j++)
            mtx[i][j] = ' ';
}