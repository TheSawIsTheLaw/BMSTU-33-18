// N - максимальная длина строки, она будет объявлена в мейне

static char *olds;

char *strtok_Perestoronin(char *string, const char *delim)
{
	int i = 0, j = 0;
	if (string == NULL)
    {
    	while (*olds)
    	{
    		while (delim[i])
    		{
    			if (*olds == delim[i])
    			{
    				*olds = '\0';
    				return ++olds;
    			}
    			i++;
    		}
    		olds++;
    	}
    	return NULL;
    }
    else
    {
    	olds = string;
    	while (string[i])
    	{
    		while (delim[j])
    		{
    			if (string[i] == delim[j])
    			{
    				string[i] = '\0';
    				break; 
    			}
    			j++;
    		}
    		i++;
    	}
    	return olds;
    }

}

int split_Perestoronin(const char *string, char matrix[][N], const char symbol)
{
	register int i = 0, j = 0, k = 0;
	while (string[k] != '\0')
	{
		if (string[k] == symbol)
		{
			matrix[i++][j] = '\0';
			j = 0;
		}
		else
			matrix[i][j++] = string[k];
		k++;
	}
    matrix[i][j] = '\0';
    return ++i;
}
