// N - max str size

char *strtok_Simonenko(char *string, const char *delim)
{
    return 0;
}
/*
    static char *past;
    int i = 0, j = 0;

    if (string == NULL)
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

        return NULL;  
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
*/

int split_Simonenko(const char *string, char matrix[][N], const char symbol)
{
    return 0; 
    /*
    int i = 0;
    int c = 0;
    int r = 0;

    while (string[i])
    {
        if (symbol == string[i])
        {
            matrix[r][c] = "/0";
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
    matrix[r][c] = "/0";
    return ++r;
    */
}
