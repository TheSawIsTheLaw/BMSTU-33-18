#include <stdlib.h>
#include <stdio.h>

#include "../headers/matrixgame_headers_matrix_t.h"
#include "../headers/matrixgame_headers_del_column.h"

#define CORRECT_COLOMN_ERROR  1  /*Некорректное значение столбца для удаления*/
#define REALLOC_ERROR 2  /*Ошибка перевыделения памяти*/
#define SUCCESS 0   /*успех*/

/**
 * \brief Уменьшает размер каждой из строк матрицы на 1
 * \param[in] m - Указатель на структуру, описывающую матрицу
 */
int resize_matrix(matrix_t *const m)
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
 * \brief Удаляет столбец
 * \param[in] m - Указатель на структуру, описывающую матрицу
 * \param[in] column - Номер удаляемого столбца
 * \return Код ошибки
 * \retval SUCCESS Успех, без ошибки
 * \retval REALLOC_ERROR Ошибка перевыделения памяти
  * \retval CORRECT_COLOMN_ERROR Некорректное значение столбца для удаления
 */
int del_column(matrix_t *const m, const int column)
{
    if (column >= m->columns || column < 0)
    {
        return CORRECT_COLOMN_ERROR;
    }
    int** p = m->matrix;

    for(int i = 0; i < m->rows; i++)
    {
        for (int j = column; j < m->columns - 1; ++j)
            *(*(p + i) + j) = *(*(p + i) + j + 1);
    }
    return resize_matrix(m);
}