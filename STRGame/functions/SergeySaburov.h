// N - максимальная длина строки, она будет объявлена в мейне
static char *late_s;

char *strtok_Saburov(char *string, const char *delim)
{
    register int i = 0;
	register int j = 0;
	if (string == NULL)
    {
    	while (*late_s)
    	{
    		while (delim[i])
    		{
    			if (*late_s == delim[i])
                {
                    *late_s = '\0';
                     return ++late_s;
                }
    			i++;
    		}
    		late_s++;
    	}
    	return NULL;
    }
    else
    {
    	late_s = string;
    	while (string[i])
    	{
    		while (delim[j])
    		{
                if(string[i] == delim[j])
                {
                    string[i] = '\0';
                    break;
                }
    			j++;
    		}
    		i++;
    	}
    	return late_s;
    }
}

int split_Saburov(const char *string, char matrix[][N], const char symbol)
{
    int i =0;
    int j = 0;
    int ind = 0;
    while (string[ind])
    {
        if (string[ind] == symbol)
        {
            matrix[i++][j] = '\0';
            j = 0;
        }
        else
        {
            matrix[i][j] = string[ind];
            j++;
        }
        ind ++;
    }
    matrix[i][j] = '\0';
    i++;
    return i;
}
