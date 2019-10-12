/**
 * \file matrixgame_functions_del_col.c
 * \brief Функция, удаляющая столбец матрицы
 */

#include <stdlib.h>

#include "../headers/matrixgame.h"

/**
 * \def CORRECT_COLOMN_ERROR
 * \brief Код ошибки: некорректное значение столбца для удаления
 */
#define CORRECT_COLOMN_ERROR  1
/**
 * \def REALLOC_ERROR
 * \brief Код ошибки: перераспределить память не удалось
 */
#define REALLOC_ERROR 2
/**
 * \def NOT_CORRECT_MATRIX
 * \brief Код ошибки: в функцию был передан некорректный указатель на матрицу
 */
#define NOT_CORRECT_MATRIX 3
/**
 * \def NOT_CORRECT_ARRAY
 * \brief Код ошибки: в функцию был передан некорректный указатель на массив
 */
#define NOT_CORRECT_ARRAY 4
/**
 * \def SUCCESS
 * \brief Код удачного завершения подпрограммы или программы
 */
#define SUCCESS 0   /*Успех*/

/**
 * \fn int resize_matrix(matrix_t *const m)
 *
 * \param matrix_t *const m - Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 *
 * \brief Функция, уменьшающая количество столбцов в матрице на единицу
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения
 */
static int resize_matrix(matrix_t *const m)
{
    int** p = m->matrix;
    m->columns--;

    for(int i = 0; i < m->rows; i++)
    {
        int *newp = (int*)realloc(*(p + i), ( m->columns * sizeof(int)));
        if (newp == NULL)
        {
            return REALLOC_ERROR;
        }
        *(p + i) = newp;
        newp = NULL;
    }
    return SUCCESS;
}

/**
 * \fn int del_column(matrix_t *const m, const int column)
 *
 * \param matrix_t *const m - Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 * \param const int column - Номер удаляемого столбца
 *
 * \brief Функция, удаляющая определённый столбец матрицы
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения
 */
int matrixgame_del_column(matrix_t *const m, const int column)
{
    if (column >= m->columns || column < 0)
    {
        return CORRECT_COLOMN_ERROR;
    }

    if (m == NULL)
        return NOT_CORRECT_MATRIX;

    int** p = m->matrix;

    for(int i = 0; i < m->rows; i++)
    {
        if (*(p + i) == NULL)
            return NOT_CORRECT_ARRAY;
    }


    for(int i = 0; i < m->rows; i++)
    {
        for (int j = column; j < m->columns - 1; ++j)
            *(*(p + i) + j) = *(*(p + i) + j + 1);
    }

    return resize_matrix(m);
}
