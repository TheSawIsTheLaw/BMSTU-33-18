// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Sokolov(char *string, const char *delim)
{
    register int i;
    static char *begin, *index;

    if (string != NULL)
    {
        begin = string;
        while (*begin)
        {
            i = 0;
            while (delim[i])
            {
                if (delim[i] == *begin)
                {
                    begin++;
                    break;
                }
                i++;
            }
            if (!delim[i])
                break;
        }
        index = begin;
        while (*begin)
        {
            i = 0;
            while (delim[i])
            {
                if (delim[i] == *begin)
                {
                    *begin = '\0';
                    break;
                }
                i++;
            }
            begin++;
            if (delim[i])
                break;
        }
        if (*begin == '\0')
            return string;
        return index;
    }    
    else
    {
        while (*begin)
        {
            i = 0;
            while (delim[j])
            {
                if (*begin == delim[i])
                {
                    begin++;
                    break;
                }
                i++;          
            }
            if (!delim[i])
                break;
        }
        if (*begin == '\0')
            return NULL;
        else
        {   
            index = begin;
            while (*begin)
            {
                i = 0;
                while (delim[i])
                {
                    if (delim[i] == *begin)
                    {
                        *begin = '\0';
                        break;
                    }
                    i++;
                }
                begin++;
                if (delim[i])
                    break;
            }
            return index;
        }
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
