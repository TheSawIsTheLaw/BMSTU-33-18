// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Sverdlov(char *string, const char *delim)
{
    return 0;
}

int split_Sverdlov(const char *string, char matrix[][N], const char symbol)
{
    int i = 0;
    int j = 0;
    while (*string != '\0')
    {
        if (*string == symbol)
        {
            matrix[i++][j] = '\0';
            j = 0;
        }
        else
            matrix[i][j++] = *string;
        string ++;
    }
    matrix[i][j] = '\0';
    i ++;
    return i;
}
