#define Z 0
#define IZ '\0'

typedef int I;

char *strtok_Yakuba(char *string, const char *delim)
{
    return 0;
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