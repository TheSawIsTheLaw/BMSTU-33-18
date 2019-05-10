// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Lemeshkin(char *string, const char *delim)
{
    return 0;
}

int split_Lemeshkin(const char *string, char matrix[][N], const char symbol)
{
    register int i = 0, rw = 0, col = 0;

        while (string[i] != '\0')
        {
            if (string[i] == symbol)
            {
                matrix[rw++][col] = '\0';
                col = 0;
            }
            else
                matrix[rw][col++] = string[i];

            ++i;
        }

        matrix[rw][col] = '\0';

        return ++rw;
}

