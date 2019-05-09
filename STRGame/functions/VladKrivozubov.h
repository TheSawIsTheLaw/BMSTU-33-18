// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Krivozubov(char *string, const char *delim)
{
    static char *index, *start;
    register int j = 0;
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
        if (*index == '\0')
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
        while (*string)
        {
            j = 0;
            while (delim[j])
            {
                if (delim[j] == *string)
                {
                    string++;
                    break;
                }
                j++;
            }
            if (!delim[j])
                break;
        }
        index = string;
        start = string;
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
