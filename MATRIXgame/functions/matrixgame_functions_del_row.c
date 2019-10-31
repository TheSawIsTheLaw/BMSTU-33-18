/**
 * \file matrixgame_functions_del_row.c
 * \brief Функция, удаляющая строку матрицы
 */
#include <stdlib.h>

#include "../headers/matrixgame.h"

/**
 * \def INDEX_OUT_OF_RANGE_ERROR
 * \brief Код ошибки: в функцию была передана некорректная размерность массива
 */
#define INDEX_OUT_OF_RANGE_ERROR 318
/**
 * \def FALSE_POINTER_ERROR
 * \brief Код ошибки: в качестве указателя на структуру передан нулевой указатель
 */
#define FALSE_POINTER_ERROR 319
/**
 * \def REALLOC_ERROR
 * \brief Код ошибки: память не была выделена
 */
#define REALLOC_ERROR 320
/**
 * \def OK
 * \brief Код удачного завершения подпрограммы или программы
 */
#define OK 0

/*
Deletes chosen row. First row has number 1.

Input data:
* matrix_t *matrix - matrix struct where need to delete row.
* const int index_row - index of row to be deleted.

Output data:
* Return code - INDEX_OUT_OF_RANGE_ERROR or
FALSE_POINTER_ERROR or REALLOC_ERROR.
*/

/**
 * \fn static int matr_realloc(matrix_t *matrix)
 *
 * \param matrix_t *matrix - Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 *
 * \brief Функция, уменьшающая память под матрицей
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения
 */
static int matr_realloc(matrix_t *matrix)
{
    int **tmp = realloc(matrix->matrix, sizeof(int*) * matrix->rows);
    if (!tmp)
        return REALLOC_ERROR;
    matrix->matrix = (int**)tmp;
    tmp = NULL;
    return OK;
}

/**
 * \fn static void remove_matrix(matrix_t *matrix, const int i_row)
 *
 * \param matrix_t *matrix - Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 * \param const int i_row - Номер удаляемой строки
 *
 * \brief Функция, производящая сдвиг по строкам в матрице
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения
 */
static void remove_matrix(matrix_t *matrix, const int i_row)
{
    for (int i = i_row; i < matrix->rows - 1; i++)
    {
        *(matrix->matrix + i) = *(matrix->matrix + i + 1);
    }
}

/**
 * \fn int matrigame_del_row(matrix_t *edit_matrix, const int index_row)
 *
 * \param matrix_t *edit_matrix - Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 * \param const int index_row - номер удаляемой строки
 *
 * \brief Функция, инициализирующая матрицу
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения
 */
int matrigame_del_row(matrix_t *edit_matrix, const int index_row)
{
    if (edit_matrix->rows - 1 < index_row || index_row < 0)
        return INDEX_OUT_OF_RANGE_ERROR;

    for (int row = 0; row < edit_matrix->rows; ++row)
    {
        if (!(*(edit_matrix->matrix + row)))
        {
            return FALSE_POINTER_ERROR;
        }
    }

    *(edit_matrix->matrix + index_row) -= 3;
    free(*(edit_matrix->matrix + index_row));
    remove_matrix(edit_matrix, index_row);

    edit_matrix->rows -= 1;

    int error = matr_realloc(edit_matrix);
    if (error)
        return REALLOC_ERROR;

    return OK;
}
