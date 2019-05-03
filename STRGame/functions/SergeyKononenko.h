// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Kononenko(char *string, const char *delim)
{
    static char *prev;
    register int i = 0, j = 0;

    if (string == NULL)
    {
        while (*prev)
        {
            while (delim[i])
            {
                if (*prev == delim[i])
                {
                    *prev = '\0';
                    return ++prev;
                }

                i++;
            }

            prev++;
        }

        return NULL;
    }

    else
    {
        prev = string;
        while (string[i])
        {
            while (delim[j])
            {
                if (string[i] == delim[j])
                {
                    string[i] = '\0';
                    break;
                }

                j++;
            }

            i++;
        }

        return prev;
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