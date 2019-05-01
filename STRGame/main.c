/* Файл main.c - не трогать, если хотите что-то протестировать
   клоньте себе на компьютер и тестируйте */

#include <stdio.h>
#include <time.h>

#define COUNT_TESTS 20
#define K 100
#define N 1000
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
#include "TestSystem/SPLIT_TESTS/SPLIT_TESTS_ADDRESS.h"
#include "SPLIT_FUNC_NAMES.h"
#include "STRTOK_FUNC_NAMES.h"

void fill_matrix(char matrix[][N], const int matrix_size)
{
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = ' ';
        }
    }
}

/*
void print_matrix(char matrix[][N], const int matrix_size)
{
    for (int i = 0; i < matrix_size; i++)
        puts(matrix[i]);
}
*/

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

int check_strtok()
{
    return OK;
}

int check_split(const char *const array_split, char matrix[][N], const int matrix_size, const char symb)
{
    int k = 0;
    for (int i = 0; i < matrix_size; i++)
    {
        char check_lexem[N]; int j = 0;
        while (array_split[k] != symb)
        {
            check_lexem[j] = array_split[k];
            k++;
            j++;
        }
        int m = 0;
        k++; j = 0; 
        puts(check_lexem);
        puts(matrix[i]);
        while (matrix[i][j])
        {
            if (matrix[i][j] != check_lexem[m])
                return ERROR;
            j++;
            m++;
        }
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

int print_results(time_t start, time_t end, char *array_names, int index, const int split_code, const int strtok_code)
{   
    index = print_name(array_names, index);
    /* develop 
     printf("\nStrtok() tacts: %ld\nSplit() tacts: %ld\nTotal tacts: %ld", 
         (start_split - start_strtok), (end_all - start_split), (end_all - start_strtok)); */
    split_code == OK ? puts("\nSplit tests is OK.") : puts("\nSplit tests is NOT OK.");
    strtok_code == OK ? puts("Strtok tests is OK") : puts("Strtok test is NOT OK.");

    return index;
}

int test_system(char *array_names, char test_matrix[][N])
{
    int index = 0;
    for (int i = 0; i < MEMBERS; i++)
    {
        const int split_code = 1;
        const int strtok_code = 1;
        time_t start = clock();
        for (int j = 0; j < COUNT_TESTS; j++)
        {
            FILE *split_test = fopen(SPLIT_TESTS_ADDRESS[j], "r");
            FILE *strtok_test = fopen(STRTOK_TESTS_ADDRESS[j], "r");
            //const int split_code = check_split();
            //const int strtok_code = check_strtok(); // will work soon
            fclose(split_test);
            fclose(strtok_test);
        }
        time_t end = clock();
        index = print_results(start, end, array_names, index, split_code, strtok_code);
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

