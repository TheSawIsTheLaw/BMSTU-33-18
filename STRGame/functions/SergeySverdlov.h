// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Sverdlov(char *string, const char *delim)
{
    register int i = 0, j = 0;
    static char *nach;
    if (string != NULL)
    {
        nach = string;
        while (string[i])
        {
            while (delim[j])
            {
                if (string[i] == delim[j])
                {
                    string[i] = '\0';
                    break;
                }
                j ++;
            }
            i ++;
        }
        return nach;
    }
    else
    {
        while (*nach)
        {
            while (delim[j])
            {
                if (*nach == delim[j])
                {
                    string[i] = '\0';
                    return ++nach;
                }
                j ++;
            }
            nach ++;
        }
        return NULL;
    }
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
