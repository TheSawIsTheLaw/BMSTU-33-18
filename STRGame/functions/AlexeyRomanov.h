char *strtok_Romanov(char *string, char const *delim)
{
    return 0;
}

int split_Romanov(const char *string, char matrix[][N], const char symbol)
{
    int i = 0, count = 0, j = 0;
    while (string[i])
    {
        (!(string[i] == symbol)) ? matrix[count][j++] = string[i] : (matrix[count++][j] = '\0', j = 0);
        ++i;
    }
    matrix[count][j] = '\0';
    return ++count;
}

