// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Krivozubov(char *string, const char *delim)
{
    static char *index;
    register int i = 0, j = 0;
    if (string == NULL)
    {
        if (*index == '\0')
            return NULL;
        else
        {
            string = index;
            while (string[i])
            {
                j = 0;
                while (delim[j])
                {
                    if (string[i] == delim[j])
                        break;
                    index = &string[i + 1];
                    j = 0;
                    while(*index)
                    {
                        j = 0;
                        while (delim[j])
                        {
                            if (*index == delim[j])
                            {
                                *index = '\0';
                                break;
                            }
                            j++;
                        }
                        if (*index == '\0')
                        {
                            index++;
                            break;
                        }
                        else
                            index++;
                    }
                    return &string[i];
                    j++;
                }
                i++;
            }
            return NULL;
        }

    }
    else
    {
        i = 0; j = 0;
        while (string[i] != '\0')
        {
            j = 0;
            while (delim[j])
            {
                if (string[i] == delim[j])
                    break;
                index = &string[i + 1];
                j = 0;
                while(*index)
                {
                    j = 0;
                    while (delim[j])
                    {
                        if (*index == delim[j])
                        {
                            *index = '\0';
                            break;
                        }
                        j++;
                    }
                    if (*index == '\0')
                    {
                        index++;
                        break;
                    }
                    else
                        index++;
                }
                return &string[i];
                j++;
            }
            i++;
        }
        return NULL;
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

