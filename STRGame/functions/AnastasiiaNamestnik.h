// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Namestnik(char *string, const char *delim)
{
    static char *initial;
    register int i = 0, j = 0;
    
    if (string != NULL)
    {
        initial = string;
        while (string[j])
        {
            while (delim[i])
            {
                if (string[j] == delim[i])
                {
                    string[j] = '\0';
                    break;
                }
                i++;
            }
            j++;
        }
        return initial;
    }
    else
    {
        while (*initial)
        {
            while (delim[i])
            {
                if (*initial == delim[i])
                {
                    *initial  = '\0';
                    return ++initial;
                }
                i++;
            }
            initial++;
        }
        return NULL;
    }
}

int split_Namestnik(const char *string, char matrix[][N], const char symbol)
{
    return 0;
}

