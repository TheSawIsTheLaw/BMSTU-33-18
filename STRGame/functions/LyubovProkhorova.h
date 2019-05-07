// N - максимальная длина строки, она будет объявлена в мейне
#define TRUE 1
#define FALSE 0

char *strtok_Prokhorova(char *str, const char *delimiters )
{
    static char* previous;
    int i = 0;
    int j = 0;
    if (str == NULL)
    {
        short is_prev_del = TRUE;
        short is_cur_del = FALSE;
        char* ans = NULL;
        while (previous[i] != '\0')
        {
            is_cur_del = FALSE;
            j = 0;

            while (delimiters[j] != '\0')
            {
                if (previous[i] == delimiters[j])
                {
                    if (!is_prev_del)
                    {
                        previous[i] = '\0';
                        previous = &previous[i] + 1;
                        return ans;
                    }

                    is_cur_del = TRUE;
                    break;
                }
                ++j;
            }

            if (!is_cur_del)
            {
                if (is_prev_del)
                {
                    ans = &previous[i];
                }
                is_prev_del = FALSE;
            }
            ++i;
        }

        return ans;
    }
    else
    {
        char* ans = NULL;
        short is_prev_del = TRUE;
        short is_cur_del = FALSE;
 
        while (str[i] != '\0')
        {
            is_cur_del = FALSE;
            j = 0;
            while (delimiters[j] != '\0')
            {
                if (str[i] == delimiters[j])
                {
                    if (!is_prev_del)
                    {
                        str[i] = '\0';
                        previous = &str[i] + 1;
                        return ans;
                    }

                    is_cur_del = TRUE;
                    break;
                }
                ++j;
            }
            if (!is_cur_del)
            {
                if (is_prev_del)
                {
                    ans = &str[i];
                }
                is_prev_del = 0;
            }
            ++i;
        }
        return ans;
    }
}

int split_Prokhorova(const char *str, char ans[][N], const char delimiter)
{
    int i = 0;
    int count = 0;
    int cur_position = 0;

    while (str[i] != '\0')
    {
        if (str[i] != delimiter)
        {
            ans[count][cur_position++] = str[i];
        }
        else
        {
            ans[count][cur_position] = '\0';
            count++;
            cur_position = 0;
        }
        ++i;
    }
    ans[count][cur_position] = '\0';
    return count + 1;
}