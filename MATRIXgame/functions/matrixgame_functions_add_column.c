#include <stdio.h>
#include <malloc.h>

//#include "../headers/matrixgame_headers_add_column.h"
//#include "../headers/matrixgame_headers_matrix_t.h"

#define OK 0 // �������
#define ERR 111 // ������ ��������� ������
/*
            ������� free_matr - ����������� ���������� ������ � ������ ������������� ������
            ������� add_mem_for_vect - �������� ������ � ������ ������ ��� ������ ��������
            ������� add_column - ��������� ������������������ ������� � ����� �������:

            int vect[] - ������, ���������� ������������������ ��������, ������� ���������� ��������.
            ��� ��� ������ ��� ������� ������� ��� ��������, �������� ���� �������� ���� ������� � �������.��� ���������� � �����
*/
int free_matr(matrix_t *const matrix)
{
    for (int i = 0; i < matrix -> rows; i ++)
    {
        free((matrix->matrix)[i]);
    }
}
int add_mem_for_vect(matrix_t *const matrix)
{
    for (int i = 0; i < matrix->rows;  i++)
    {
        (matrix->matrix)[i] =  (int*)realloc(((matrix->matrix)[i]), sizeof(int*)* ((matrix->rows)+ 1));
        if ((matrix->matrix)[i] == NULL)
        {
            free_matr(matrix);
            return ERR;
            break;
        }
    }
    return OK;
}
int add_column(matrix_t *const matrix, int vect[])
{
    if (matrix->rows <= 0 || matrix->columns <= 0)
        return ERR;
    if ((add_mem_for_vect(matrix))!= ERR)
    {
        for (int i = 0; i < matrix->rows;  i++)
        {
            *(*((matrix->matrix)+ i ) + matrix->columns) = vect[i];
        }
        matrix->columns += 1;
    }
    else
        return ERR;
    return OK;
}

