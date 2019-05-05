/* Файл main.c - не трогать, если хотите что-то протестировать
   клоньте себе на компьютер и тестируйте */

#include <stdio.h>
#include <stdint.h>

#define COUNT_TESTS 20
#define GHZ 3300000000
#define K 100
#define N 32000
#define MEMBERS 24
#define OK 0
#define ERROR 1

#include "functions/AlisSukocheva.h"
#include "functions/AnastasiiaNamestnik.h" // SPLIT - 0, STRTOK - 1
#include "functions/ArtemSarkisov.h" // SPLIT - 1, STRTOK - 1
#include "functions/BogdanLemeshkin.h"
#include "functions/DmitryKovalev.h"
#include "functions/DmitryYakuba.h" // SPLIT - 1, STRTOK - 1
#include "functions/EmilSimonenko.h"
#include "functions/IlyaChelyadinov.h"
#include "functions/KarimAkhmetov.h"
#include "functions/LyubovProkhorova.h"
#include "functions/MikhailNitenko.h" // SPLIT - 1, STRTOK - 0
#include "functions/NadezhdaAksenova.h"
#include "functions/NikitaBurtelov.h" 
#include "functions/PavelPerestoronin.h" // SPLIT - 1, STRTOK - 1
#include "functions/PavelToporkov.h" // SPLIT - 1, STRTOK - 1
#include "functions/SergeyKononenko.h" // SPLIT - 1, STRTOK - 1
#include "functions/SergeyMinenko.h" 
#include "functions/SergeySaburov.h" // SPLIT - 1, STRTOK - 1
#include "functions/SergeySverdlov.h" // SPLIT - 1, STRTOK - 0
#include "functions/VladKrivozubov.h" // SPLIT - 1, STRTOK - 1
#include "functions/VladislavChernenko.h" // SPLIT - 1, STRTOK - 1
#include "functions/VladislavGurishev.h"
#include "functions/YefimSokolov.h" // SPLIT 1, STRTOK - 0
#include "functions/AlexeyRomanov.h" // SPLIT - 1, STRTOK - 0

#include "TestSystem/STRTOK_TESTS/STRTOK_SETTINGS.h"
#include "TestSystem/SPLIT_TESTS/SPLIT_SETTINGS.h"

// супер крутая ассемблерная вставка (UPDATE)
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
        array[i] = '\0';
        i++;
    }
}

// Эта функция нужна для отладки
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

// soon
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

int print_results(char *array_names, int index, const int complete_split, 
        const int complete_strtok, const uint64_t time_ticks)
{   
    puts("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    index = print_name(array_names, index);
    if (COUNT_TESTS == complete_split) printf(" ✅✅✅✅✅");
    printf("\nTime running: %.10lf", (double)time_ticks / GHZ);
    printf("\nSplit tests %d / %d\nStrtok tests %d / %d (TESTS FOR STRTOK NOT WORKING!)\n", 
            complete_split, COUNT_TESTS, complete_strtok, COUNT_TESTS);
    
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
        uint64_t time_ticks = 0;

        for (int j = 0; j < COUNT_TESTS; j++)
        {
            FILE *split_test = fopen(SPLIT_TESTS_ADDRESS[j], "r");
            FILE *strtok_test = fopen(STRTOK_TESTS_ADDRESS[j], "r");
            readfile(split_test, TS_arr_split);
            readfile(strtok_test, TS_arr_strtok);

            uint64_t start_time = tick();
            const int size = split[i](TS_arr_split, test_matrix, SPLIT_SEPARATORS[j]);
            char *pch = strtok[i](TS_arr_strtok, &SPLIT_SEPARATORS[j]);
            while (pch != NULL) pch = strtok[i](NULL, &SPLIT_SEPARATORS[j]); // скоро будут отдельные тесты для strtok
            uint64_t end_time = tick();
            time_ticks += (end_time - start_time);

            if (!check_split(TS_arr_split, test_matrix, size, SPLIT_SEPARATORS[j]) && size == SPLIT_CORRECT_SIZE[j]) ++complete_split;
            fill_matrix(test_matrix, size);
            fill_array(TS_arr_split);
            fill_array(TS_arr_strtok);
        }

        index = print_results(array_names, index, complete_split, complete_strtok, time_ticks);
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

