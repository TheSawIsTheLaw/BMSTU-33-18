// N - максимальная длина строки, она будет объявлена в мейне
static char *p;

char *strtok_Chelyadinov(char *str, const char *delim)
{
    register char *nach = NULL;
    register int i;

    if (str == NULL)
        str = p;

    while (*(str))
    {
        i = 0;
        while (delim[i] && *(str) != delim[i])
            i++;

        if (*(str) != delim[i])
            break;

        str++;
    }

    if (*(str))
    {
        nach = str;

        while (*(str))
        {
            i = 0;
            while (delim[i])
            {
                if (*(str) == delim[i])
                    break;
                i++;
            }
            if (*(str) == delim[i])
                break;

            str++;
        }

        if (*(str))
        {
            *str = '\0';
            str++;
        }
    }

    p = str;
    return nach;
}

int split_Chelyadinov(const char *string, char matrix[][N], const char symbol)
{
    register int i = 0, j = 0, k = 0;
    while (string[k])
    {
        if (string[k] == symbol)
        {
            matrix[++i][j] = '\0';
            j = 0;
        }
        else
            matrix[i][++j] =  string[k];
        ++k;
    }
    matrix[i][j] = '\0';
    return ++i;
}

