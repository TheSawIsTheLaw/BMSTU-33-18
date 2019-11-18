#include "../f_headers/teen48game_check_equal_matrices.h"

#define SIZE_ERROR -1
#define NO 0
#define YES 1

int teen48game_check_equal_matrices(const matrix_t *const matrix1, const matrix_t *const matrix2)
{
    if (matrix1->rows != matrix2->rows || matrix1->columns != matrix2->columns)
        return SIZE_ERROR;
    
    for (int i = 0; i < matrix1->rows; i++)
        for (int j = 0; j < matrix1->columns; j++)
            if (matrix1->matrix[i][j] != matrix2->matrix[i][j])
                return NO;
    return YES;
}
