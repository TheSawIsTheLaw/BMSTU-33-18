// N - максимальная длина строки, будет объявлен в мейне

char *strtok_Sukocheva(char *string, const char *delim)
{
    return 0;
}

int split_Sukocheva(const char *string, char matrix[][N], const char symbol)
{
    register int i = 0, j = 0;   
    while (*(string))
    {
        if (*(string) == symbol)
        {
            matrix[i++][j] = '\0';
            j = 0;
        }
        else
            matrix[i][j++] = *(string);
        ++string;
    }
    matrix[i][j] = '\0';
    return ++i;
}

