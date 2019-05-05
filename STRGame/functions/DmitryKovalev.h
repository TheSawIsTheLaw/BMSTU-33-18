// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Kovalev(char *string, const char *delim)
{
    return 0;
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

