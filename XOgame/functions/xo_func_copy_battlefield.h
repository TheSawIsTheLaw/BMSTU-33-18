void copy_battlefield(char from_field[][DIME], char to_field[][DIME])
{
    int i, j;
    for (i = 0; i < DIME; ++i)
        for (j = 0; j < DIME; ++j)
            to_field[i][j] = from_field[i][j];
}