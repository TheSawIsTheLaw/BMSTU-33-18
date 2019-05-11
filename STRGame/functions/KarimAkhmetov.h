unsigned short mystrlen(char *str) {
    for (int i = 0;; i++) if (str[i] == '\0') return i;
}

int mystrspn(const char *str1, const char *str2) {
    int i, k, counter = 0;
    for (i = 0; str1[i] != '\0'; i++) {
        if (counter != i) break;
        for (k = 0; str1[k] != '\0'; k++) {
            if (str1[i] == str2[k])
                counter++;
        }
    }
    return counter;
}

char *strtok_Akhmetov(char *string, const char *delim) {
    static char *temp;
    static int size;
    int i;
    if (string != NULL) {
        temp = string;
        size = mystrlen(string);
    } else if (size > 0) {
        temp++;
        size--;
        string = temp;
    } else { string = NULL; }
    while (*temp) {
        i = mystrspn(temp, delim);
        while (i > 1) {
            *temp = '\0';
            temp++;
            size--;
            i--;
        }
        if (1 == i) {
            *temp = '\0';
            if (size > 1) {
                temp--;
                size++;
            }
            temp++;
            size--;
        }
    }
    return string;
}

int split_Akhmetov(const char *string, char matrix[][N], const char symbol) {
    int column = 0;
    int row = 0;
    int index = 0;
    while (string[index] != '\0') {
        if (string[index] == symbol) {
            matrix[row++][column] = '\0';
            column = 0;
        } else {
            matrix[row][column++] = string[index];
        }

        index++;
    }
    matrix[row][column] = '\0';
    row++;
    return row;
}
