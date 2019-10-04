#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "../headers/matrixgame_headers_add_column.h"
#include "../headers/matrixgame_headers_matrix_t.h"

#define OK 0
#define ERR 111
/**
* \brief ������������ ������, ���� realloc �� ��������
* \param[in] matrix - ��������� �� ���������, ����������� �������
*/
void free_matr(matrix_t *const matrix)
{
    for (int i = 0; i < matrix -> rows; i ++)
    {
        free(*((matrix->matrix)+ i ));
    }
}
/**
* \brief ���������� ������ ��� �������
* \param[in] matrix - ��������� �� ���������, ����������� �������
*/
int add_mem_for_vect(matrix_t *const matrix)
{
    matrix->matrix = (int**)realloc(matrix->matrix,(matrix->columns + 1) * sizeof(int*));
    if (matrix->matrix == NULL)
    {
            free_matr(matrix);
            return ERR;

    }
    return OK;
}
/**
* \brief ��������� �������
* \details �������� ������ ��� ����������� �������
*
* \param[in] matrix - ��������� �� ���������, ����������� �������
* \param[in] vect - ��������� �� ������� ������� �������
* \return ��� ������
* \retval OK �����
* \retval ERR ������
*/
/*
 ��������� - ���������� ��������� � ������������������ ������� ������ ��������� � ����������� ����� �������
*/
int add_column(matrix_t *const matrix, int vect[])
{
    if (matrix->rows <= 0 || matrix->columns <= 0)
        return ERR;
    if ((add_mem_for_vect(matrix))!= ERR)
    {
        matrix->columns += 1;
        for (int i = 0; i < matrix->rows;  i++)
        {
            *(*((matrix->matrix)+ i ) + matrix->columns - 1) = vect[i];
        }
    }
    else
        return ERR;
    return OK;
}
