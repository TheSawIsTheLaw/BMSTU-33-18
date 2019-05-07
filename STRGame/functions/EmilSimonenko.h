// N - max str size
#define BSZ '\0'
char *strtok_Simonenko(char *string, const char *delim)
{
    static char *past;
    int i = 0, j = 0;

    if (string == 0)
    {
        while (*past)
        {
            while (delim[i])
            {
                if (*past == delim[i])
                {
                    *past = '\0';
                    return ++past;
                }

                i++;
            }

            past++;
        }

        return 0;  
    }

    else
    {
        past = string;
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

        return past;     //teper luchshe
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
            matrix[r][c] = BSZ ;
            c = 0;
            ++r;
        }
        else
        {
            matrix[r][c] = string[i];
            ++c;
        }
        ++i;
    }
    matrix[r][c] = BSZ ;
    return ++r;
}
