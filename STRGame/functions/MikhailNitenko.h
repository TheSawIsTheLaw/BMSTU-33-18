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
    register int n = 0, i = 0, j = 0;
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

