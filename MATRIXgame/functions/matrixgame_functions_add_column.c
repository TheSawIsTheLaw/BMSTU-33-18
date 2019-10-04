#include <stdlib.h>


#include "../headers/matrixgame_headers_add_column.h"
#include "../headers/matrixgame_headers_matrix_t.h"

#define OK 0
#define ERR 111

#define SOME_ARE_NULL 507
#define MAIN_POINTER_NULL 411
#define SERVICE_INFO 3
/**
* \brief  ,  realloc
* \param[in] matrix -   ,
*/
static int free_matr(matrix_t *to_free)
{
    int ec = OK;
    if (to_free->matrix)
    {
        for (int i = 0; i < to_free->rows; i++)
        {
            if (*(to_free->matrix + i))
            {
                *(to_free->matrix + i) -= SERVICE_INFO;
                free(*(to_free->matrix + i));
                *(to_free->matrix + i) = NULL;
            }
            else
            {
                ec = SOME_ARE_NULL;
            }
        }

        free(to_free->matrix);
        to_free->rows = 0;
        to_free->columns = 0;
        to_free->matrix = NULL;
    }
    else
    {
        ec = MAIN_POINTER_NULL;
    }

    return ec;
}

/**
* \brief
* \param[in] matrix -   ,
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
* \brief
* \details
*
* \param[in] matrix -   ,
* \param[in] vect -
* \return
* \retval OK
* \retval ERR
*/
/*
  -
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
