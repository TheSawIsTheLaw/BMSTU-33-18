// N - максимальная длина строки, она будет объявлена в мейне
static char *olds;

char *strtok_Perestoronin(char *string, const char *delim)
{
    register int i, j;
    if (string)
        olds = string;
    if ((olds == NULL) || (*olds == '\0'))
        return NULL;
    while(olds)
    {
        for (i = 0; delim[i]; i++)
            if (*olds == delim[i])
            {
                olds++;
                break;
            }
        if (!delim[i])
            break;
    }
    if (*olds == '\0')
        return NULL;
/*
    char * start = c;
    while(*c && (strchr(delim,*c)==0)) ++c;
*/
    i = 0;
    while (olds[i])
    {
        for (j = 0; delim[j]; j++)
            if (olds[i] == delim[j])
                goto last_oper;
        i++;
    }
    last_oper:
        if (olds[i] == '\0')
        {
            olds += i;
            return olds - i;
        }
        olds[i] = '\0';
        olds += i + 1;
        return olds - i - 1;
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
