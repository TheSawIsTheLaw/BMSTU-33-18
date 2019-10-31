// N - максимальная длина строки, она будет объявлена в мейне
#define EX '\0'
#define CONST_ZERO 0
#define CONST_ONE 1

char *strtok_Toporkov(char *string, const char *delim)
{
    static char *old_str;
    static int length;
    register int length_cur = CONST_ZERO;
    register int count = CONST_ZERO;
    register int i = CONST_ZERO;
    register int j = CONST_ZERO;
    register int index;
    
    if (string != NULL)
    {
        old_str = string;
        while (string[length_cur] != EX)
            length_cur++;
        length = length_cur;
    }
    
    else if (length > CONST_ZERO)
    {
        length--;
        old_str++;
        string = old_str;
    }
    
    else
        string = NULL;
    
    while (*old_str)
    {
        while (delim[j] != EX)
        {
            if (old_str[i] == delim[j])
            {
                i++;
                j = CONST_ZERO;
            }
            else
                j++;
        }
        
        index = i;
        
        if (count == CONST_ZERO && index > CONST_ZERO)
        {
            while (index > CONST_ONE)
            {
                old_str++;
                string++;
                index--;
                length--;
            }
            
            if (index == CONST_ONE)
            {
                if (length > CONST_ONE)
                {
                    length++;
                    old_str--;
                }
            }
            old_str++;
            string++;
            index--;
            length--;
        }
        
        count++;
        i = CONST_ZERO;
        j = CONST_ZERO;
        
        while (index > CONST_ONE)
        {
            *old_str = EX;
            old_str++;
            index--;
            length--;
        }
        
        if (index == CONST_ONE)
        {
            *old_str = EX;
            if (length > CONST_ONE)
            {
                old_str--;
                length++;
            }
        }
        
        old_str++;
        length--;
    }
    
    return string;
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
