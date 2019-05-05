// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Sokolov(char *string, const char *delim)
{
    register int i = 0;
    static char *previous;

    if (string != NULL)
    {
        register int j = 0;
        previous = string;
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
        return previous;
    }
    else
    {
        while (*previous)
        {
            while (delim[i])
            {
                if (*previous == delim[i])
                {
                    *previous = '\0';
                    return ++previous;
                }
                i++;
            }
            previous++;
        }
        return NULL;
    }
}

int split_Sokolov(const char *string, char matrix[][N], const char symbol)
{
    register int row = 0, col = 0;
    register int index = 0;

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
