// N - максимальная длина строки, она будет объявлена в мейне


char *strtok_Perestoronin(char *string, const char *delim)
{
    return 0;
}

int split_Perestoronin(const char *string, char matrix[][N], const char symbol)
{
	int i = 0, j = 0, k = 0;
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

