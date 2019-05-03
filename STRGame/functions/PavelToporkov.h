// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Toporkov(char *string, const char *delim)
{
    return 0;
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

