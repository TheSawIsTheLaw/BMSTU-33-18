// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Chelyadinov(char *string, const char *delim)
{
    return 0;
}

int split_Chelyadinov(const char *string, char matrix[][N], const char symbol)
{
    register int i = 0, j = 0, k = 0;
    while (string[k])
    {
        if (string[k] == symbol)
        {
            matrix[i][++j] = '\0';
            j = 0;
        }
        else
            matrix[i][++j] =  string[k];
        ++k;
    }
    matrix[i][j] = "\0";
    return ++i;
}

