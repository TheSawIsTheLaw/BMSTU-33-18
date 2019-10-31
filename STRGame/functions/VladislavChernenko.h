void memmove_Chernenko(char *dst,
    const char *beg, const char *const end)
{
    beg++;
    
    while (beg != end)
    {
        *dst = *beg;
        beg++;
        dst++;
    }

    *dst = 0;
}

char *find_end_Chernenko(const char *string)
{
    while (*string != 0)
        string++;

    return (char *)string;
}

#define BELONGS 1
#define DOES_NOT_BELONG 0

int belongs(const char *const ichar, const char* set)
{
    while (*set != 0)
    {
        if (*ichar == *set)
            return BELONGS;
        set += 1;
    }

    return DOES_NOT_BELONG;
}

char *strtok_Chernenko(char *istr, const char *delim)
{
    static char *last_token = NULL;
    static char *string_end = NULL;
    
    if (istr != NULL)
    {
        last_token = NULL;
        string_end = NULL;
            
        char *current = istr;
        char *left    = istr;

        string_end = find_end_Chernenko(istr);
        
        while (belongs(left, delim) && left != string_end)
            left++;
        if (left == string_end)
            return NULL;
        
        current = left;
        while (current != string_end)
        {
            if (belongs(current, delim))
                *current = 0;
            current++;
        }

        last_token = left;
        return last_token;
    }
    else
    {
        if (string_end == NULL)
            return NULL;
        if (last_token == NULL)
            return NULL;
        
        char *cur_token = last_token;

        while (*cur_token != 0 && cur_token != string_end)
            cur_token++;
        while (*cur_token == 0 && cur_token != string_end)
            cur_token++;

        if (cur_token == string_end)
            return NULL;

        last_token = cur_token;
        return last_token;
    }
}

int split_Chernenko(const char *string, char matrix[][N], const char symbol)
{
    char *last = (char *)string - 1;
    char *curr = (char *)string;

    int count = 0;

    while (*last != 0 || count == 0)
    {
        if (*curr == symbol || *curr == 0)
        {
            memmove_Chernenko(matrix[count], last, curr);
            last = curr;
            count += 1;
        }

        curr++;
    }

    return count;
}

