#include <stdlib.h>

#include "../headers/matrixgame.h"

#define OK 0
#define ERR 111

#define SOME_ARE_NULL 507
#define MAIN_POINTER_NULL 411
#define SERVICE_INFO 3

static int add_mem_for_vect(matrix_t *const matrix)
{
    matrix->matrix = (int**)realloc(matrix->matrix,(matrix->columns + 1) * sizeof(int*));
    if (matrix->matrix == NULL)
    {

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
int matrixgame_add_column(matrix_t *const matrix, int vect[])
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
