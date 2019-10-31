char *strtok_Aleksandrovich(char *string, const char *delim)
{
	return 0;
}

int split_Aleksandrovich(const char *string, char w_matrix[][N], const char symbol)
{
	register int i = 0, j = 0, k = 0;
	while(string[k])
	{
		if(string[k] == symbol)
		{

			w_matrix[i++][j] = '\0';
			j = 0;
		}
		else
		{
			w_matrix[i][j++] = string[k];
		}
		k++;
	}
	w_matrix[i][j] = '\0';
	return ++i;
}
