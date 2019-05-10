// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Akhmetov(char *string, const char *delim)
{

    return 0;
}

int split_Akhmetov(const char *string, char matrix[][N], const char symbol)
{
    int column = 0;
    int row = 0;
    int index = 0;
    while (string[index] != '\0')
    {
        if (string[index] == symbol)
        {
            matrix[row++][column] = '\0';
            column = 0;
        }
        else
        {
            matrix[row][column++] = string[index];
        }

        index++;
    }
    matrix[row][column] = '\0';
    row++;
    return row;
}