#include <stdio.h>

#include "../headers/matrixgame_headers_create_matrix.h"
#include "../headers/matrixgame_headers_free_matrix.h"
#include "../headers/martixgame_headers_add_row.h"
#include "../headers/matrixgame_headers_matrix_t.h"

#define PASSED    0
#define FAILED    1

#define ZERO      0
#define EQUAL     3
#define NOT_EQUAL 4

// Функция заполняет матрицу нулями
void fill_matrix(matrix_t *const matrix_to_zero)
{
    for (int i = 0; i < matrix_to_zero->rows; i++)
        for (int j = 0; j < matrix_to_zero->columns; j++)
            *(*(matrix_to_zero->matrix + i) + j) = ZERO;
}

// Функция сравнивает матрицы
int matrix_compare(matrix_t *const matrix_1, matrix_t *const matrix_2)
{
    if ((matrix_1->rows != matrix_2->rows) || (matrix_1->columns != matrix_2->columns))
        return NOT_EQUAL;

    for (int i = 0; i < matrix_1->rows; i++)
        for (int j = 0; j < matrix_1->columns; j++)
        {
            if ((*(*(matrix_1->matrix + i) + j)) != (*(*(matrix_2->matrix + i) + j)))
                return NOT_EQUAL;
        }

    return EQUAL;
}

int matrixgame_add_row_test()
{
    int error_counter = ZERO;

    // Test 1
    // Позитивный тест
    // Добавляем строку в начало
    {
        matrix_t matrix_1;
        matrix_t result_matrix_1;

        create_matrix(&matrix_1, 4, 4);
        fill_matrix(&matrix_1);

        create_matrix(&result_matrix_1, 5, 4);
        fill_matrix(&result_matrix_1);

        // добавляем строку в матрицу
        add_row(matrix_1, 0);

        // сравниваем матрицы 
        if (matrix_compare(matrix_1, result_matrix_1) != EQUAL)
            error_counter++;       
    
        free_matrix(&matrix_1);
        free_matrix(&result_matrix_1);
    }

    // Test 2
    // Позитивный тест
    // Добавляем строку в конец
    {
        matrix_t matrix_2;
        matrix_t result_matrix_2;

        create_matrix(&matrix_2, 4, 4);
        fill_matrix(&matrix_2);

        create_matrix(&result_matrix_2, 5, 4);
        fill_matrix(&result_matrix_2);

        add_row(matrix_2, 5);

        if (matrix_compare(matrix_2, result_matrix_2) != EQUAL)
            error_counter++;       
    
        free_matrix(&matrix_2);
        free_matrix(&result_matrix_2);
    }

    // Test 3
    // Позитивный тест
    // Добавляем строку в середину
    {
        matrix_t matrix_3;
        matrix_t result_matrix_3;

        create_matrix(&matrix_3, 4, 4);
        fill_matrix(&matrix_3);

        create_matrix(&result_matrix_3, 5, 4);
        fill_matrix(&result_matrix_3);

        add_row(matrix_3, 3);

        if (matrix_compare(matrix_3, result_matrix_3) != EQUAL)
            error_counter++;       
    
        free_matrix(&matrix_3);
        free_matrix(&result_matrix_3);
    }
    
    // Test 4
    // Негативный тест
    // Некорректный индекс строки
    {
        int test_status = 0;

        matrix_t matrix_4;
        matrix_t result_matrix_4;

        create_matrix(&matrix_4, 4, 4);
        fill_matrix(&matrix_4);

        create_matrix(&result_matrix_4, 5, 4);
        fill_matrix(&result_matrix_4);

        test_status = add_row(matrix_1, -1);

        if (test_status != INDEX_OUT_OF_THE_RANGE)
            error_counter++;       
    
        free_matrix(&matrix_4);
        free_matrix(&result_matrix_4);
    }

    if (error_counter)
        return FAILED;

    return PASSED;
}

int main()
{
    if (matrixgame_add_row_test() == PASSED)
    {
        printf("All tests passed successfully\n");

        return PASSED;
    }
    else
    {
        printf("There is a problem\n");

        return FAILED;
    }
}
