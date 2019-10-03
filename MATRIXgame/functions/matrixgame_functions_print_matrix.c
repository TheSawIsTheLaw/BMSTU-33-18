/**
 * \file matrixgame_functions_print_matrix.c
 * \brief Функция, выводящая матрицу в файл
 */

#include <stdio.h>
#include <stdlib.h>
#include "../headers/matrixgame_headers_print_matrix.h"
#include "../headers/matrixgame_headers_matrix_t.h"

/**
 * \def ERROR
 * \brief Код ошибки: в функцию передана некорректная матрица
 */
#define ERROR -1
/**
 * \def SUCCESS
 * \brief Код удачного завершения подпрограммы или программы
 */
#define SUCCESS 0

/**
 * \fn int append_row(matrix_t *const matrix)
 *
 * \param const matrix_t *const matrix Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 * \param FILE *file Десриптор файла вывода
 *
 * \brief Выводит матрицу в файл
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения
 */
int print_matrix(const matrix_t *const matrix, FILE *file)
{
    if (matrix -> rows <= 0)
        return ERROR;

    if (matrix -> columns <= 0)
        return ERROR;

    for (int i = 0; i < matrix -> rows; i++)
    {
        for (int j = 0; j < matrix -> columns; j++)
            fprintf(file, "%d ",  matrix -> matrix[i][j]);
        fprintf(file, "\n");
    }
    return SUCCESS;
}
