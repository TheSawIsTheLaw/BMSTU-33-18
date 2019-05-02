#define Z 0
#define IZ '\0'
#define ONE 1

typedef int I;

char *pre;

char *strtok_Yakuba(char *string, const char *delim)
{
    return 0;
    if (string != NULL)
    {

        I i = Z, q = Z;
        while (string[i])
        {
            while (delim[q])
            {
                if (delim[q] == string[i])
                {
                    string[i] = IZ;
                    pre = &string[i+ONE];
                    return string;
                }
                ++q;
            }
            ++i;
            q = Z;
        }
        return NULL;
    }
    else
    {
        I i = Z, q = Z;
        char* prepr = pre;
        while (pre[i])
        {
            while (delim[q])
            {
                if (delim[q] == pre[i])
                {
                    pre[i] = IZ;
                    pre = &pre[i+ONE];
                    return prepr;
                }
                ++q;
            }
            ++i;
            q = Z;
        }
        prepr = pre;
        pre = NULL;
        return prepr;
    }
}

int split_Yakuba(const char *s, char m[][N], const char sy)
{
    I i = Z;
    I r = Z;
    I c = Z;
    while (s[i])
    {
        if (sy == s[i])
        {
            m[r][c] = IZ;
            ++r;
            c = Z;
        }
        else
        {
            m[r][c] = s[i];
            ++c;
        }
        ++i;
    }
    m[r][c] = IZ;
    return ++r;
}
