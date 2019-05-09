int strtok(char *string, const char *delim)
{
	return 0;	
}

int split(const char *string, char word_matrix[][N], const char split_symbol)
{
	register int row = 0, col = 0, k = 0;
	while(string[k])
	{
		if(string[k] == split_symbol)
		{
			word_matrix[row++][col] = '\0';
			col = 0;
		}
		else
		{
			word_matrix[row][col++] = string[k];
		}	
		k++;
	}
	word_matrix[row][col] = '\0';
	return ++row;
}

