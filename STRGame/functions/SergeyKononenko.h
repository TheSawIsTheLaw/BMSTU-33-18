// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Kononenko(char *string, const char *delim)
{
    static char *prev;
    register int i = 0, j = 0;

    if (string)
        prev = string;


    if ((prev == NULL) || (*prev == '\0'))
        return NULL;

    while(prev)
    {
        for (i = 0; delim[i]; i++)
            if (*prev == delim[i])
            {
                prev++;
                break;
            }
        if (!delim[i])
            break;
    }

    i = 0;
    while (prev[i])
    {
        for (j = 0; delim[j]; j++)
            if (prev[i] == delim[j])
            {
                if (prev[i] == '\0')
                {
                    prev += i;
                    return prev - i;
                }
                prev[i] = '\0';
                prev += i + 1;
                return prev - i - 1;
            }

        i++;
    }
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