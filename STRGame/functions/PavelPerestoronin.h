// N - максимальная длина строки, она будет объявлена в мейне
static char *olds;

char *strtok_Perestoronin(char *string, const char *delim)
{
    register int i, j;
    // Считываем строку, если запуск с новой строкой
    if (string)
        olds = string;
    // Если после предыдущей итерации olds указывает на конец строки,
    // то она была полностью обработана (+ Обработка NULL для
    // некорректной строки (нужна ли?))
    if ((olds == NULL) || (*olds == '\0'))
        return NULL;
    // Проходим все разделители в начале слова
    while(olds)
    {
        for (i = 0; delim[i]; i++)
            if (*olds == delim[i])
            {
                olds++;
                break;
            }
        if (!delim[i])
            break;
    }
    if (*olds == '\0')
        return NULL;
    // Находим следующий разделитель (или конец строки)
    i = 0;
    while (olds[i])
    {
        for (j = 0; delim[j]; j++)
            if (olds[i] == delim[j])
                goto last_oper;
        i++;
    }
    last_oper:
        // Если конец строки, то olds указывает на '\0' и в след итерации нас ждет NULL
        if (olds[i] == '\0')
        {
            olds += i;
            return olds - i;
        }
        // Если не конец строки, то ставим нуль-символ и ссылаем olds на след элемент
        olds[i] = '\0';
        olds += i + 1;
        return olds - i - 1;
}

int split_Perestoronin(const char *string, char matrix[][N], const char symbol)
{
    register int i = 0, j = 0, k = 0;
    while (string[k] != '\0')
    {
        if (string[k] == symbol)
        {
            matrix[i++][j] = '\0';
            j = 0;
        }
        else
            matrix[i][j++] = string[k];
        k++;
    }
    matrix[i][j] = '\0';
    return ++i;
}
