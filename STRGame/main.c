/* Файл main.c - не трогать, если хотите что-то протестировать
   клоньте себе на компьютер и тестируйте */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

#define COUNT_TESTS 20
#define COUNT_SEPS 5
#define GHZ 3300000000 // нужно менять, если у вас другая частота
#define N 32000
#define K 100
#define MEMBERS 26
#define OK 0
#define ERROR 1

#include "functions/AlisSukocheva.h" // SPLIT - 1, STRTOK - 0
#include "functions/AnastasiiaNamestnik.h" // SPLIT - 1, STRTOK - 1 (???)
#include "functions/ArtemSarkisov.h" // SPLIT - 1, STRTOK - 1 
#include "functions/BogdanLemeshkin.h" // SPLIT - 1, STRTOK - 0
#include "functions/DmitryKovalev.h" // SPLIT 1, STRTOK - 0
#include "functions/DmitryYakuba.h" // SPLIT - 1, STRTOK - 1
#include "functions/EmilSimonenko.h" // SPLIT - 1, STRTOK - 1 (???)
#include "functions/IlyaChelyadinov.h" // SPLIT - 1, STRTOK - 0
#include "functions/KarimAkhmetov.h" // SPLIT - 1, STRTOK - 0
#include "functions/LyubovProkhorova.h" // SPLIT - 1, STRTOK - 1 (???)
#include "functions/MikhailNitenko.h" // SPLIT - 1, STRTOK - 1
#include "functions/NadezhdaAksenova.h" // ????????????
#include "functions/NikitaBurtelov.h" // ??????????????
#include "functions/PavelPerestoronin.h" // SPLIT - 1, STRTOK - 1 
#include "functions/PavelToporkov.h" // SPLIT - 1, STRTOK - 1
#include "functions/SergeyKononenko.h" // SPLIT - 1, STRTOK - 1 (0)
#include "functions/SergeyMinenko.h" /// ??????????????
#include "functions/SergeySaburov.h" // SPLIT - 1, STRTOK - 1 (???)
#include "functions/SergeySverdlov.h" // SPLIT - 1, STRTOK - 1 (0)
#include "functions/VladKrivozubov.h" // SPLIT - 1, STRTOK - 1
#include "functions/VladislavChernenko.h" // SPLIT - 1, STRTOK - 1
#include "functions/VladislavGurishev.h" // ???????????
#include "functions/YefimSokolov.h" // SPLIT 1, STRTOK - 1 (0)
#include "functions/AlexeyRomanov.h" // SPLIT - 1, STRTOK - 0
#include "functions/AndrewOlyunin.h" // SPLIT - 1, STRTOK - 0
#include "functions/GeorgeAleksandrovich.h" // SPLIT - 1, STRTOK - 0

#include "TestSystem/STRTOK_TESTS/STRTOK_SETTINGS.h"
#include "TestSystem/SPLIT_TESTS/SPLIT_SETTINGS.h"

// Подсчёт тиков (тактов)
uint64_t tick(void)
{
    uint32_t high, low;
    __asm__ __volatile__ (
        "rdtsc\n"
        "movl %%edx, %0\n"
        "movl %%eax, %1\n"
        : "=r" (high), "=r" (low)
        :: "%rax", "%rbx", "%rcx", "%rdx"
        );

    uint64_t ticks = ((uint64_t)high << 32) | low;

    return ticks;
}

// Очистка матрицы
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

// Очистка массива
void fill_array(char *array)
{
    int i = 0;
    while (i < N)
    {
        array[i] = '\0';
        i++;
    }
}

// Печать матрицы (отладка)
void print_matrix(char matrix[][N], const int matrix_size)
{
    int j = 0;
    for (int i = 0; i < matrix_size; i++)
    {
        while (matrix[i][j])
        {
            putchar(matrix[i][j++]);
        }
    }
}

// Считывание файла
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

// Проверка корректности выполнения функции strtok
int check_strtok(const char *const pch, const char *const pch_std, 
    const char *const TS_arr_strtok, const char *const TS_arr_strtok_std)
{
    if (pch == NULL && pch_std != NULL)
    {
        return ERROR;
    }

    if (*pch == *pch_std && !(strcmp(TS_arr_strtok, TS_arr_strtok_std)))
    {
        return OK;
    }
    
    return ERROR;
}

// Проверка корректности выполнения функции split
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

// Печать имени студента
int print_name(char *array, int index)
{
    while (array[index] != ':')
    {
        printf("%c", array[index]);
        index++;
    }
    return ++index;
}

void print_correctness(const int count_complete)
{
    if (COUNT_TESTS == count_complete)
    {
        printf(" ✅✅✅✅✅");
    }
    else
    {
        printf(" ❌❌❌❌❌");
    }
}

// Печать результата прохождения тестовой системы и времени
int print_results(char *array_names, int index, const int complete_split, 
    const int complete_strtok, const uint64_t ticks_split, const uint64_t ticks_strtok)
{   
    puts("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    index = print_name(array_names, index);
    printf("\nSplit time running: %.10lf\nTicks: %" PRIu64 "", (double)ticks_split / GHZ, ticks_split);
    printf("\nStrtok time running: %.10lf\nTicks: %" PRIu64 "\n", (double)ticks_strtok / GHZ, ticks_strtok);
    printf("Split tests %d / %d", complete_split, COUNT_TESTS);
    print_correctness(complete_split);
    printf("\nStrtok tests %d / %d", complete_strtok, COUNT_TESTS);
    print_correctness(complete_strtok);
    
    return index;
}

void copy_strtok_array(char *strtok1, char *strtok2)
{
    int i = 0;
    while (strtok1[i])
    {
        strtok2[i] = strtok1[i];
        ++i;
    }
    strtok2[i] = '\0';
}

// Функция тестовой системы split и strtok
void test_system(char *array_names, char test_matrix[][N])
{
    int index = 0;
    char TS_arr_split[N] = { 0 };
    char TS_arr_strtok[N] = { 0 };
    char TS_arr_strtok_std[N] = { 0 };

    for (int i = 0; i < MEMBERS; i++)
    {
        int complete_split = 0;
        int complete_strtok = 0;
        uint64_t ticks_strtok = 0;
        uint64_t ticks_split = 0;

        for (int j = 0; j < COUNT_TESTS; j++)
        {
            int strtok_checker = ERROR;
            FILE *split_test = fopen(SPLIT_TESTS_ADDRESS[j], "r");
            FILE *strtok_test = fopen(STRTOK_TESTS_ADDRESS[j], "r");
            readfile(split_test, TS_arr_split);
            readfile(strtok_test, TS_arr_strtok);
            copy_strtok_array(TS_arr_strtok, TS_arr_strtok_std);

            uint64_t start_time = tick();
            const int size = split[i](TS_arr_split, test_matrix, SPLIT_SEPARATORS[j]);
            uint64_t end_time = tick();
            ticks_split += end_time - start_time;

            start_time = tick();
            char *pch = strtok_arr[i](TS_arr_strtok, STRTOK_SEPARATORS);
            end_time = tick();
            char *pch_std = strtok(TS_arr_strtok_std, STRTOK_SEPARATORS);
            ticks_strtok += end_time - start_time;

            while (pch_std != NULL)
            {
                strtok_checker = check_strtok(pch, pch_std, TS_arr_strtok, TS_arr_strtok_std);
                if (strtok_checker)
                {
                    break;
                }
                start_time = tick();
                pch = strtok_arr[i](NULL, STRTOK_SEPARATORS);
                end_time = tick();
                pch_std = strtok(NULL, STRTOK_SEPARATORS);
                ticks_strtok += end_time - start_time;
            }

            if (pch_std == pch && !strtok_checker)
            {
                ++complete_strtok; 
            }
            else
            {
                if (i == 9)
                {
                    printf("%d ", j);
                }
            }

            if (!check_split(TS_arr_split, test_matrix, size, SPLIT_SEPARATORS[j]) && size == SPLIT_CORRECT_SIZE[j])
            {   
                ++complete_split;
            }

            fill_matrix(test_matrix, size);
            fill_array(TS_arr_split);
            fill_array(TS_arr_strtok_std);
            fill_array(TS_arr_strtok);
        }

        index = print_results(array_names, index, complete_split, complete_strtok, ticks_split, ticks_strtok);
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

