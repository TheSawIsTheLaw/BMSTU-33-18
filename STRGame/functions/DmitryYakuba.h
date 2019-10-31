#define Z 0
#define IZ '\0'
#define ONE 1

typedef int I;
typedef char C;

C *last = NULL;
C *final = NULL;

char *strtok_Yakuba(C *s, const C *delim)
{
    if (s == NULL)
    {
        C *satan = last;
        while (*satan != IZ && satan != final)
            satan++;
        while (*satan == IZ && satan != final)
            satan++;
        if (satan == final)
            return NULL;
        last = satan;
        return last;
    }
    else
    {
        final = s;
        while (*final != Z)
            ++final;
        C *pre = s;
        C *now = s;
        I q = Z;
        while (delim[q])
        {
            while (pre != final && *pre == delim[q])
                ++pre;
            if (pre == final)
                return NULL;
            ++q;
        }
        q = Z;
        now = pre;
        while (now != final)
        {
            while (delim[q])
            {
                if (*now == delim[q])
                {
                    *now = IZ;
                }
                ++q;
            }
            q = Z;
            ++now;
        }
        last = pre;
        return last;
    }
    return NULL;
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