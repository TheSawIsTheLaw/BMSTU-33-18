// N - максимальная длина строки, она будет объявлена в мейне
#include <string.h>
int strlen_Saburov (char *string)
{
    int i = 0;
    while (string[i] != '\0')
            i++;
    return i;
}
char *strtok_Saburov(char *string, const char *delim)
{
    static char *late_s;
    static int size;

    int i;

    if(string != NULL)
    {
        late_s = string;
        size = strlen_Saburov(string);
    }

    else if(size > 0)
    {
        late_s++;
        size--;
        string = late_s;
    }

    else
    {
        string = NULL;
    }

    while(*late_s)
    {
        i = strspn(late_s, delim);
        while(i > 1)
        {
            *late_s = '\0';
            late_s++;
            size--;
            i--;
        }
        if(1 == i)
        {
            *late_s = '\0';
            if(size > 1)
            {
                late_s--;
                size++;
            }
        }
        late_s++;
        size--;
    }
    return string;
}
int split_Saburov(const char *string, char matrix[][N], const char symbol)
{
    int i =0;
    int j = 0;
    int ind = 0;
    while (string[ind])
    {
        if (string[ind] == symbol)
        {
            matrix[i++][j] = '\0';
            j = 0;
        }
        else
        {
            matrix[i][j] = string[ind];
            j++;
        }
        ind ++;
    }
    matrix[i][j] = '\0';
    i++;
    return i;
}
