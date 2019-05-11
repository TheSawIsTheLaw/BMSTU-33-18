// N - максимальная длина строки, она будет объявлена в мейне
static char *lasti;

char *strtok_Kovalev(char *str, const char *delim)
{
    register char *start = NULL;
    register int i;

    if (str == NULL)
        str = lasti;

    while (*(str))
    {
        i = 0;
        while (delim[i] && *(str) != delim[i])
            i++;

        if (*(str) != delim[i])
            break;

        str++;
    }

    if (*(str))
    {
        start = str;

        while (*(str))
        {
            i = 0;
            while (delim[i])
            {
                if (*(str) == delim[i])
                    break;
                i++;
            }
            if (*(str) == delim[i])
                break;

            str++;
        }

        if (*(str))
        {
            *str = '\0';
            str++;
        }
    }

    lasti = str;
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

