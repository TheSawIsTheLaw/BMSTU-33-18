// N - максимальная длина строки, она будет объявлена в мейне

static char *old_str;

char *strtok_Toporkov(char *string, const char *delim)
{
    register int i = CONST_ZERO;
    register int j = CONST_ZERO;
    if (string != NULL)
    {
        old_str = string;
        while (string[i])
        {
            while (delim[j])
            {
                if (delim[j] == string[i])
                {
                    string[i] = EX;
                    break;
                }
                ++j;
            }
            ++i;
        }
        return old_str;
    }
    else
    {
        while (*old_str)
        {
            while (delim[i])
            {
                if (delim[i] == *old_str)
                {
                    *old_str = EX;
                    ++old_str;
                    return old_str;
                }
                ++i;
            }
            ++old_str;
        }
        return NULL;
    }
}

int split_Toporkov(const char *string, char matrix[][N], const char symbol)
{
    register int i = CONST_ZERO;
    register int rows = CONST_ZERO;
    register int columns = CONST_ZERO;
    
    while (string[i] != EX)
    {
        if (string[i] == symbol)
        {
            matrix[rows++][columns] = EX;
            columns = CONST_ZERO;
        }
        else
            matrix[rows][columns++] = string[i];
        
        ++i;
    }
    
    matrix[rows][columns] = EX;
    
    return ++rows;
}

