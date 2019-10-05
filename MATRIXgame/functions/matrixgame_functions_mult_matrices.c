/**
 * \file matrixgame_mult_matrices.c
 * \brief Функция умножения матриц
 */

#include "../headers/matrixgame.h"

/**
 * \def OK
 * \brief Код удачного завершения подпрограммы
 */
#define OK 0
/**
 * \def SIZE_ERROR
 * \brief Код ошибки: Размеры 3 матриц (2 множителей и результата) не корректны
 * для проведения матричного умножения
 */
#define SIZE_ERROR 217
/**
 * \def MATRIX_DATA_ERROR
 * \brief Код ошибки: Указатель на поле с данными указывает на NULL
 */
#define MATRIX_DATA_ERROR 117
/**
 * \def POINTER_ERROR
 * \brief Код ошибки: указатель на матрицу, переданный аргументом, указывает на NULL
 */
#define POINTER_ERROR 170

/**
 * \fn int mult_matrices(const matrix_t *const matrix1, const matrix_t *const matrix2,
 * matrix_t *const res)
 *
 * \param const matrix_t *const matrix1 - Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 * \param const matrix_t *const matrix2 - Особо заданная матрица
 * \param matrix_t *const res - Особо заданная матрица результата
 *
 * \brief Производит перемножение матриц matrix1 и matrix2, результат передаётся в res
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения проверки
 */
int matrixgame_mult_matrices(const matrix_t *const matrix1, const matrix_t *const matrix2,
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
