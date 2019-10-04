#include <stdio.h>
#include <stdlib.h>

#include "../headers/matrixgame_headers_input_matrix.h"
#include "../headers/matrixgame_headers_matrix_t.h"

#define ROW_ERROR 1
#define COLUMN_ERROR 2
#define POINT_ERROR 3
#define OK 0

#define ZERO 0
#define ALL_PASSED 0
#define FAILED 1
#define FAILED_POINTER 2


int matrixgame_input_matrix_tests(matrix_t *matrix1, matrix_t *matrix2, matrix_t *matrix3)
{
    int error = ZERO;
    
    /*Test 1: incorrect input*/
    if (input_matrix(matrix1) == OK)
        error++;
    
    /*Test 2: incorrect input*/
    if (input_matrix(matrix2) == OK)
        error++;
    
    /*Test 1: NULL pointer*/
    if (input_matrix(matrix3) != POINT_ERROR)
        error++;
    
    if (error)
        return FAILED;
    return ALL_PASSED;
}

int main(int argc, const char * argv[])
{
    matrix_t matrix1;
    matrix1.rows = 0;
    matrix1.columns = 5;
    
    matrix_t matrix2;
    matrix2.rows = 5;
    matrix2.columns = 0;
    
    matrix_t matrix3;
    matrix3.matrix =  NULL;
    
    int test = matrixgame_input_matrix_tests(&matrix1, &matrix2, &matrix3);
    
    if (test == ALL_PASSED)
    {
        puts("All tests passed (success)");
        return ALL_PASSED;
    }
    else
    {
        puts("Not all the tests passed (failure)");
        return FAILED;
    }
}
