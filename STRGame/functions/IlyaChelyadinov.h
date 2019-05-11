// N - максимальная длина строки, она будет объявлена в мейне

int my_strspn(const char *str1,const char *str2){ 
    int i,k,counter=0; 
    for(i=0;str1[i]!='\0';i++){ 
        if(counter != i) 
            break; 
        for(k=0;str1[k]!='\0';k++){ 
            if(str1[i]==str2[k]) 
            counter++; 
        } 
    } 
    return counter; 
}
unsigned short mystrlen(char *str) {
    for (int i = 0;; i++) 
        if (str[i] == '\0') 
            return i;
}


char *strtok_Chelyadinov(char *str, const char *delim)
{
    static char *next;
    static int size;
    int i;
    if (str != NULL)
    {
        next = str;
        size = strlen(str);
    }
    else if (size > 0)
    {
        ++next;
        size--;
        str = next;
    }
    else
    {
        str = NULL
    }
    while (*next)
    {
        i = my_strspn(next, delim);
        while (i>1)
        {
            *next = '\0';
            ++next;
            size--;
            i--;
        }
        if (i == 1)
        {
            *next = '\0';
            if (size > 1)
            {
                next--;
                ++size;
            }
        }
        ++next;
        size--;
    }
    return str;
}

int split_Chelyadinov(const char *string, char matrix[][N], const char symbol)
{
    register int i = 0, j = 0, k = 0;
    while (string[k])
    {
        if (string[k] == symbol)
        {
            matrix[++i][j] = '\0';
            j = 0;
        }
        else
            matrix[i][++j] =  string[k];
        ++k;
    }
    matrix[i][j] = '\0';
    return ++i;
}

