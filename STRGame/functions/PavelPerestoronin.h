// N - максимальная длина строки, она будет объявлена в мейне
static char *olds;

char *strtok_Perestoronin(char *string, const char *delim)
{
    if (string == NULL)
    {
        for (; *olds; olds++)
            for (int i = 0; delim[i]; i++)
                if (*olds == delim[i])
                {
                    *olds = '\0';
                    return ++olds;
                }
        return NULL;
    }
    else
    {
        register int i, j;
        while (!(*string))
        {
            for (j = 0; delim[j]; j++)
                if (*string == delim[j])
                {
                    string++;
                    break;
                }
            if (!delim[j])
                break;
            }
        olds = string;
        for (i = 0; string[i]; i++)
            for (j = 0; delim[j]; j++)
                if (string[i] == delim[j])
                {
                    string[i] = '\0';
                    break; 
                }
        return olds;
    }

}

int split_Perestoronin(const char *string, char matrix[][N], const char symbol)
{
    register int i = 0, j = 0, k = 0;
    while (string[k] != '\0')
    {
        if (string[k] == symbol)
        {
            matrix[i++][j] = '\0';
            j = 0;
        }
        else
            matrix[i][j++] = string[k];
        k++;
    }
    matrix[i][j] = '\0';
    return ++i;
}
