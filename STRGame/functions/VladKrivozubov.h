// N - максимальная длина строки, она будет объявлена в мейне


static char *index, *start;
char *strtok_Krivozubov(char *string, const char *delim)
{
    register int j;
    if (string == NULL)
    {   
        while (*start)
        {
            j = 0;
            while (delim[j])
            {
                if (*start == delim[j])
                {
                    start++;
                    break;
                }
                j++;          
            }
            if (!delim[j])
                break;
        }
        if (*start == '\0')
            return NULL;
        else
        {   
            index = start;
            while (*start)
            {
                j = 0;
                while (delim[j])
                {
                    if (delim[j] == *start)
                    {
                        *start = '\0';
                        break;
                    }
                    j++;
                }
                start++;
                if (delim[j])
                    break;
            }
            return index;
        }
    }
    else
    {
        start = string;
        while (*start)
        {
            j = 0;
            while (delim[j])
            {
                if (delim[j] == *start)
                {
                    start++;
                    break;
                }
                j++;
            }
            if (!delim[j])
                break;
        }
        index = start;
        while (*start)
        {
            j = 0;
            while (delim[j])
            {
                if (delim[j] == *start)
                {
                    *start = '\0';
                    break;
                }
                j++;
            }
            start++;
            if (delim[j])
                break;
        }
        if (*start == '\0')
            return string;
        return index;
    }    
}

int split_Krivozubov(const char *string, char matrix[][N], const char symbol)
{
    register int i = 0, j = 0, current = 0;
    while(string[current])
    {
        if (string[current] != symbol)
            matrix[i][j++] = string[current];
        else
        {
            matrix[i++][j] = '\0';
            j = 0;
        }
        current++;
    }
    matrix[i][j] = '\0';
    return ++i;
}
