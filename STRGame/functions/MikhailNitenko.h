static char *lastik;

char *strtok_Nitenko(char *string, const char *delim)
{
    register char *start = NULL;
    register int i;

    if (string == NULL) 
        string = lastik;
	
    while (*(string))
    {
        i = 0;
        while (delim[i] && *(string) != delim[i])
            i++;
        
        if (*(string) != delim[i])
            break;
        
        string++;
    }

    if (*(string))
    {
        start = string;
		
        while (*(string))
        {
            i = 0;
            while (delim[i])
            {
                if (*(string) == delim[i])
                    break;
                i++;
            }
            if (*(string) == delim[i])
                break;
            
            string++;
        }
		
        if (*(string))
        {
            *string = '\0';
            string++;
        }
    }

    lastik = string;
    return start;
}

int split_Nitenko(const char *string, char matrix[][N], const char symbol)
{
    register int i = 0, j = 0;
    while (*(string))
    {
        if (*(string) == symbol)
        {
           matrix[i++][j] = '\0';
           j = 0;
        }
        else
            matrix[i][j++] = *(string);   
        ++string;
    }
    matrix[i][j] = '\0';
    return ++i;
}

