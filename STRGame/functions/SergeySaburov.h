// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Saburov(char *string, const char *delim)
{
    return 0;
}

int split_Saburov(const char *string, char matrix[][N], const char symbol)
{
    int i =0;
    int j = 0;
    int ind = 0;
    while (string[ind] != '\0')
    {
        if (string[ind] == symbol)
        {
            matrix[i++][j] = '\0';
            i++;
            j = 0;
        }
        else
        {
            matrix[i][j] = string[ind];
            j ++;
        }
        ind ++;
    }
    matrix[i][j] = '\0';
    return i ++;
}
