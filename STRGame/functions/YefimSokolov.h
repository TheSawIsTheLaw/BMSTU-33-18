// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Sokolov(char *string, const char *delim)
{
    return 0;
}

int split_Sokolov(const char *string, char matrix[][N], const char symbol)
{
    register int row, col;
    register index = 0;

    while (string[index])
    {
        if (string[index] != symbol)
            matrix[row][col++] = string[index];
        else
        {
            matrix[row++][col] = '\0';
            col = 0;
        }
        index++;
    }
    matrix[row][col] = '\0';
    return ++row;
}
