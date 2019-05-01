/* Файл main.c - не трогать, если хотите что-то протестировать
   клоньте себе на компьютер и тестируйте */

#include <stdio.h>
#include <time.h>

#define COUNT_TESTS 20
#define K 100
#define N 1400
#define MEMBERS 24
#define OK 0
#define ERROR 1

#include "functions/AlisSukocheva.h"
#include "functions/AnastasiiaNamestnik.h"
#include "functions/ArtemSarkisov.h"
#include "functions/BogdanLemeshkin.h"
#include "functions/DmitryKovalev.h"
#include "functions/DmitryYakuba.h"
#include "functions/EmilSimonenko.h"
#include "functions/IlyaChelyadinov.h"
#include "functions/KarimAkhmetov.h"
#include "functions/LyubovProkhorova.h"
#include "functions/MikhailNitenko.h"
#include "functions/NadezhdaAksenova.h"
#include "functions/NikitaBurtelov.h" 
#include "functions/PavelPerestoronin.h" // SPLIT - 1, STRTOK - 0
#include "functions/PavelToporkov.h"
#include "functions/SergeyKononenko.h"
#include "functions/SergeyMinenko.h"
#include "functions/SergeySaburov.h"
#include "functions/SergeySverdlov.h"
#include "functions/VladKrivozubov.h"
#include "functions/VladislavChernenko.h"
#include "functions/VladislavGurishev.h"
#include "functions/YefimSokolov.h"
#include "functions/AlexeyRomanov.h"

#include "TestSystem/STRTOK_TESTS/STRTOK_TESTS_ADDRESS.h"
#include "TestSystem/SPLIT_TESTS/SEPARATORS_SPLIT.h"
#include "TestSystem/SPLIT_TESTS/SPLIT_TESTS_ADDRESS.h"
#include "SPLIT_FUNC_NAMES.h"
#include "STRTOK_FUNC_NAMES.h"

void fill_matrix(char matrix[][N], const int matrix_size)
{
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = '\0';
        }
    }
}

void fill_array(char *array)
{
    int i = 0;
    while (array[i])
    {
        array[i] = ' ';
        i++;
    }
}

// Эта функция нужна для отладки
void print_matrix(char matrix[][N], const int matrix_size)
{
    for (int i = 0; i < matrix_size; i++)
        puts(matrix[i]);
}


void readfile(FILE *file, char *array)
{
    int i = 0;
    while (!feof(file))
    {
        fscanf(file, "%c", &array[i]);
        i++;
    }
    fclose(file);
}
//soon
int check_strtok()
{
    return OK;
}

int check_split(const char *const TS_arr_split, char matrix[][N], const int matrix_size, const char sep)
{
    int k = 0;
    for (int i = 0; i < matrix_size; i++)
    {
        int j = 0;
        while (matrix[i][j])
        {
            if (matrix[i][j] != TS_arr_split[k]) return ERROR;
            k++;
            j++;
        }
        k++;
    }
    return OK;
}

int print_name(char *array, int index)
{
    while (array[index] != ':')
    {
        printf("%c", array[index]);
        index++;
    }
    return ++index;
}

int print_results(time_t start, time_t end, char *array_names, int index, const int complete_split, const int complete_strtok)
{   
    puts("\n----------------------");
    index = print_name(array_names, index);
    /* develop 
     printf("\nStrtok() tacts: %ld\nSplit() tacts: %ld\nTotal tacts: %ld", 
         (start_split - start_strtok), (end_all - start_split), (end_all - start_strtok)); */
    printf("\nSplit tests %d / %d\nStrtok tests %d / %d\n", complete_split, COUNT_TESTS, complete_strtok, COUNT_TESTS);
    return index;
}

void test_system(char *array_names, char test_matrix[][N])
{
    int index = 0;
    char TS_arr_split[N];
    char TS_arr_strtok[N];

    for (int i = 0; i < MEMBERS; i++)
    {
        int complete_split = 0;
        int complete_strtok = 0;
        time_t start = clock();
        for (int j = 0; j < COUNT_TESTS; j++)
        {
            FILE *split_test = fopen(SPLIT_TESTS_ADDRESS[j], "r");
            FILE *strtok_test = fopen(STRTOK_TESTS_ADDRESS[j], "r");
            readfile(split_test, TS_arr_split);
            readfile(strtok_test, TS_arr_strtok);

            const int size = split[i](TS_arr_split, test_matrix, SPLIT_SEPARATORS[j]);
            if (!size) complete_split--; // так нужно пока никто (почти) не написал свои функции
            if (!check_split(TS_arr_split, test_matrix, size, SPLIT_SEPARATORS[j])) ++complete_split;

            fill_array(TS_arr_split);
            fill_array(TS_arr_strtok);
        }
        time_t end = clock();
        index = print_results(start, end, array_names, index, complete_split, complete_strtok);
    }
}

int main(void)
{   
    setbuf(stdout, NULL);
    FILE *names = fopen("TestSystem/NAMES.txt", "r");
    char test_matrix[N][N];
    char array_names[N];
    readfile(names, array_names);
    test_system(array_names, test_matrix);

    return OK;
}

