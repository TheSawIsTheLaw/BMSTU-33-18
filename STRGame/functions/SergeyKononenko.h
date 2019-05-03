// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Kononenko(char *string, const char *delim)
{
    return 0;
}

int split_Kononenko(const char *string, char matrix[][N], const char symbol)
{
    register int row = 0, col = 0, k = 0;

    while (string[k])
    {
        if (string[k] == symbol)
        {
            matrix[row++][col] = '\0';
            col = 0;
        }
        else
        {
            matrix[row][col++] = string[k];
        }
        k++;
    }
    matrix[row][col] = '\0';
    return ++row;
}

