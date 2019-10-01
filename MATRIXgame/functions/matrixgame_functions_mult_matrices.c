#include "../headers/matrixgame_headers_matrix_t.h"
#include "../headers/matrixgame_headers_mult_matrices.h"
#include <stdio.h>

#define OK 0 // Код корректного выполнения функции
#define SIZE_ERROR 217 // Размеры 3 матриц (2 множителей и результата) не корректны для проведения матричного умножения
#define MATRIX_DATA_ERROR 117 // Указатель на поле с данными указывает на NULL
#define POINTER_ERROR 170 // Указатель на матрицу, переданный аргументом, указывает на NULL

int mult_matrices(const matrix_t *const matrix1, const matrix_t *const matrix2,
                  matrix_t *const res)
{
    if (!matrix1 || !matrix2 || !res)
        return POINTER_ERROR;
    if (matrix1->matrix == NULL || matrix2->matrix == NULL || res->matrix == NULL)
        return MATRIX_DATA_ERROR;
    if (matrix1->rows != res->rows || matrix1->columns != matrix2->rows ||
        matrix2->columns != res->columns || matrix1->rows <= 0 || matrix1->columns <= 0 
        || matrix2->columns <= 0)
        return SIZE_ERROR;

    for (int i = 0; i < matrix1->rows; i++)
        for (int j = 0; j < matrix2->columns; j++)
        {
            *(*(res->matrix + i) + j) = 0;
            for (int k = 0; k < matrix1->columns; k++)
                *(*(res->matrix + i) + j) += *(*(matrix1->matrix + i) + k) * *(*(matrix2->matrix + k) + j);
        }
        
    return OK;
}
