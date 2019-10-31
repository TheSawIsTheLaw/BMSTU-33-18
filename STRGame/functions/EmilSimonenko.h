// N - max str size
#define BSZ '\0'
char *strtok_Simonenko(char *string, const char *delim)
{
    static char *check;
    int i = 0, j = 0;

    if (string)
        check = string;
	
    if ( (*check == BSZ) || (check == NULL) )
        return NULL;
	
    while(check)
    {
        for (i = 0; delim[i]; ++i)
            if (*check == delim[i])
            {
                ++check;
                break;
            }
        if (!delim[i])
            break;
    }
	
    i = 0;
    while (check[i++])
        for (j = 0; delim[j]; ++j)
            if (check[i] == delim[j])
            {
                if (check[i] == BSZ)
                {
                    check += i;
                    return check - i;
                }
                check[i] = BSZ;
                check += i + 1;
                return check - i - 1;
            }
}


int split_Simonenko(const char *string, char matrix[][N], const char symbol)
{ 
    int i = 0;	 //indexer
    int c = 0;   //collumn
    int r = 0;   //row

    while (string[i])
	{
        if (symbol == string[i])
        {
            matrix[r++][c] = BSZ ;
            c = 0;
        }
        else
            matrix[r][c++] = string[i];
		i++;
	}
    matrix[r][c] = BSZ;
    return ++r;
}
