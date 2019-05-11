// N - max str size
#define BSZ '\0'
char *strtok_Simonenko(char *string, const char *delim)
{
    static char *past;
    static char *last;

    if (string == NULL)
    {
    
		char *now = past;
        while (*now != BSZ && now != last)
			now++;							//now we reached lexema
		while (*now == BSZ && now != last)
			now++;
		if (now == last)
			return NULL;
		else
		past = now;
		return now;
	}
    else
    {
        last = string;
		char *before = string;
		int i = 0;
        while (*last != 0)
			last++;
		while (delim[i++])    //OP++ returns its prevous znachenie and then increases operand
		{
			while (*before == delim[i] && before != last)
				before++;
			if (before == last)
				return NULL;
		}
		i = 0;
		char *rightnow = before;
		while (rightnow++ != last)
		{
			while (delim[i++])
				if (*rightnow == delim[i-1])
					*rightnow = BSZ;
			i = 0;
		}      
		past = before;
        return before;     //teper luchshe
    }
	return NULL;
}


int split_Simonenko(const char *string, char matrix[][N], const char symbol)
{ 
    int i = 0;	 //indexer
    int c = 0;   //collumn
    int r = 0;   //row

    while (string[i++])
        if (symbol == string[i-1])
        {
            matrix[r++][c] = BSZ ;
            c = 0;
        }
        else
            matrix[r][c++] = string[i];
    matrix[r][c] = BSZ;
    return ++r;
}
