#include <stdio.h>
#include <stdlib.h>
#include "../headers/matrixgame_headers_print_matrix.h"
#include "../headers/matrixgame_headers_matrix_t.h"
#define ERROR -1
#define SUCCESS 0

/*
 Функция для печати матрицы, на вход принимает указатель на структуру, которая содержит все данные о матрице. Дальше идет проверка на количество строк и столбцов, их число должно быть натуральным. В случае ошибки возвращает -1 иначе 0.
 */
int print_matrix(const matrix_t *const matrix)
{
    if (matrix -> rows <= 0)
        return ERROR;
    
    if (matrix -> columns <= 0)
        return ERROR;

    for (int i = 0; i < matrix -> rows; i++)
    {
        for (int j = 0; j < matrix -> columns; j++)
            printf("%d ",  matrix -> matrix[i][j]);
        printf("\n");
    }
    return SUCCESS;
}
