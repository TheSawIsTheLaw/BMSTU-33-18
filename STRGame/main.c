/* Файл main.c - не трогать, если хотите что-то протестировать
   клоньте себе на компьютер и тестируйте */

#include <stdio.h>
#include <time.h>

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

#include "func_pointer_split.h"
#include "func_pointer_strtok.h"

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
        printf("%c", array[i]);
        i++;
    }
    fclose(file);
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

int print_results(time_t start_split, time_t start_strtok, time_t end_all, 
    char *array_names, int index, const int code)
{   
    index = print_name(array_names, index);
    printf("\nStrtok() tacts: %ld\nSplit() tacts: %ld\nTotal tacts: %ld", 
        (start_split - start_strtok), (end_all - start_split), (end_all - start_strtok));
    
    if (code == OK)
        puts("\nSplit test OK");
    else
        puts("\nSplit test NOT OK!");

    return index;
}

void competition(char array_split[N], char array_strtok[N], char matrix_competition[][N], char *array_names)
{
    const char symb = ' ';
    int index = 0;
    for (int i = 0; i < MEMBERS; i++)
    {   
        time_t start_strtok = clock();
        char *pch = strtok[i](array_strtok, &symb);
        while (pch != NULL)
            pch = strtok[i](NULL, &symb);
        time_t start_split = clock();
        int size = split[i](array_split, matrix_competition, symb);
        time_t end_all = clock();
        const int code = check_split(array_split, matrix_competition, size, symb);
        index = print_results(start_split, start_strtok, end_all, array_names, index, code);
    }
}

int main(void)
{   
    setbuf(stdout, NULL);
    char TS_split[K];
    char TS_strtok[K];
    FILE *test_split = fopen("TestSystem/TEST_SPLIT_1.txt", "r");
    FILE *test_strtok = fopen("test_strtok.txt", "r");
    FILE *names = fopen("TestSystem/NAMES.txt", "r");
    char matrix_competition[N][N];
    char array_names[N];
    char array_split[N];
    char array_strtok[N]; 

    readfile(test_strtok, array_strtok);
    readfile(test_split, array_split);
    readfile(names, array_names);
    competition(array_split, array_strtok, matrix_competition, array_names);

    return OK;
}



