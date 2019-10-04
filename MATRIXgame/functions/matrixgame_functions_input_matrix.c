#include <stdio.h>
#include "../headers/matrixgame.h"

#define ROW_ERROR 1 /*Некорректное значение строк матрицы*/
#define COLUMN_ERROR 2 /*Некорректное значение столбцов матрицы*/
#define POINT_ERROR 3 /*В качестве указателя на структуру передан нулевой указатель*/
#define INPUT_ERROR 4 // xd
#define OK 0 /*Матрица была удачно инициализирована*/

/*
 Функция для инициализации матрицы. Аргументом является указатель на структуру, содержащую данные для матрицы
 */

int matrixgame_input_matrix(matrix_t *matrix)
{
    if (matrix -> matrix == NULL)
        return POINT_ERROR;

    if (matrix -> rows <= 0)
        return ROW_ERROR;

    if (matrix -> columns <= 0)
        return COLUMN_ERROR;

    int i, j;

    for (i = 0; i < matrix -> rows; i++)
        for (j = 0; j < matrix -> columns; j++)
            if (scanf("%d", &matrix -> matrix[i][j]) != 1)
                return INPUT_ERROR;

    return OK;
}
