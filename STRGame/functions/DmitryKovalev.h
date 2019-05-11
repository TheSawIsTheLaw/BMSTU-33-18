// N - максимальная длина строки, она будет объявлена в мейне
static char *lasti;

char *strtok_Kovalev(char *string, const char *delim)
{
    register char *start = NULL;
    register int i;

    if (string == NULL) 
        string = lasti;
	
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

    lasti = string;
    return start;

}

int split_Kovalev(const char *string, char matrix[][N], const char symbol)
{
    register int i = 0, j = 0, n = 0;
	while (string[n] != '\0')
    {
		if (string[n] == symbol)
        {
			matrix[i++][j] = '\0';
			j = 0;
		}
		else
			matrix[i][j++] = string[n];
        n++;
    }
    matrix[i][j] = '\0';
    return ++i;
}

