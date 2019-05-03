/*
int strlen(const char *s)
{
    int l = 0;
    while(*l++ != '\0')

    return l;
}
*/
// N - максимальная длина строки, она будет объявлена в мейне
//ты че докопалсо мне там для другова

char *strtok_Nitenko(char *string, const char *delim)
{
    return 0;
}

int split_Nitenko(const char *string, char matrix[][N], const char symbol)
{
    register int i = 0, j = 0;
    while (*(string))
    {
        if (*(string) == symbol)
        {
           matrix[i++][j] = '\0';
           j = 0;
        }
        else
            matrix[i][j++] = *(string);   
        ++string;
    }
    matrix[i][j] = '\0';
    return ++i;
}

