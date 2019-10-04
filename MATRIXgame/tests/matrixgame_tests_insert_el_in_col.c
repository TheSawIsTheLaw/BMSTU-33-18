#include <stdio.h>
#include <stdlib.h>

#include "../headers/matrixgame_headers_insert_el_in_col.h"
#include "../headers/matrixgame_headers_matrix_t.h"


#define TESTS_AMOUNT 5  // amount of the tests

#define PASSED 0  // test passed
#define FAILED 1  // test failed

#define DIFFERENT 0  // matrices are different
#define SAME 1  // matrices are same

#define ELEMENT 777  // element to insert



void free_matrix(matrix_t *const matrix)
{
    for (int *row = *(matrix->matrix); row < *(matrix->matrix + matrix->rows); row++)
        free(row);

    free(matrix->matrix);
}


// function to compare 2 matrices 
int compare_matrices(const matrix_t matrix_1, const matrix_t matrix_2)
{
    if ((matrix_1.rows == matrix_2.rows) && (matrix_1.columns == matrix_2.columns))
    {
        for (int i = 0; i < matrix_1.rows; i++)
            for (int j = 0; j < matrix_1.columns; j++)
                if (matrix_1.matrix[i][j] != matrix_2.matrix[i][j])
                    return DIFFERENT;
        
        return SAME; 
    }
    
    return DIFFERENT;
}


int negative_indices_testing()
{
    matrix_t test_matrix;
    
    test_matrix.rows = 3;
    test_matrix.columns = 3;
    
    test_matrix.matrix = (int **)calloc(test_matrix.rows, sizeof(int *));
    for (int i = 0; i < test_matrix.rows; i++)
    {
        (test_matrix.matrix)[i] = (int *)calloc(test_matrix.columns, sizeof(int));
        for (int j = 0; j < test_matrix.columns; j++)
            test_matrix.matrix[i][j] = 1;
    }

    int index_row = -5;
    int index_column = 4;
    if (insert_el_in_col(&test_matrix, index_row, index_column, ELEMENT) == PASSED)
        return FAILED;

    index_row = 5;
    index_column = -4;
    if (insert_el_in_col(&test_matrix, index_row, index_column, ELEMENT) == PASSED)
        return FAILED;
    
    index_row = -5;
    index_column = -4;
    if (insert_el_in_col(&test_matrix, index_row, index_column, ELEMENT) == PASSED)
        return FAILED;
    
    free_matrix(&test_matrix);

    return PASSED;
}


int indices_beyond_testing()
{
    matrix_t test_matrix;
    
    test_matrix.rows = 3;
    test_matrix.columns = 3;
    
    test_matrix.matrix = (int **)calloc(test_matrix.rows, sizeof(int *));
    for (int i = 0; i < test_matrix.rows; i++)
    {
        (test_matrix.matrix)[i] = (int *)calloc(test_matrix.columns, sizeof(int));
        for (int j = 0; j < test_matrix.columns; j++)
            test_matrix.matrix[i][j] = 1;
    }

    int index_row = 100;
    int index_column = 2;
    if (insert_el_in_col(&test_matrix, index_row, index_column, ELEMENT) == PASSED)
        return FAILED;
    
    index_row = 2;
    index_column = 100;
    if (insert_el_in_col(&test_matrix, index_row, index_column, ELEMENT) == PASSED)
        return FAILED;
    
    index_row = 100;
    index_column = 100;
    if (insert_el_in_col(&test_matrix, index_row, index_column, ELEMENT) == PASSED)
        return FAILED;
    
    free_matrix(&test_matrix);

    return PASSED;
}


int calloc_reject_testing()
{
    matrix_t matrix;
    matrix.matrix = NULL;
    matrix.rows = 10;
    matrix.columns = -10;  // negative to call CALLOC error

    int index_row = 1;
    int index_column = 1;

    if (insert_el_in_col(&matrix, index_row, index_column, ELEMENT) == PASSED)
        return FAILED;
    
    return PASSED;
}


int insert_in_new_row_testing()
{
    matrix_t test_matrix;
    
    test_matrix.rows = 3;
    test_matrix.columns = 3;
    
    test_matrix.matrix = (int **)calloc(test_matrix.rows, sizeof(int *));
    for (int i = 0; i < test_matrix.rows; i++)
    {
        (test_matrix.matrix)[i] = (int *)calloc(test_matrix.columns, sizeof(int));
        for (int j = 0; j < test_matrix.columns; j++)
            test_matrix.matrix[i][j] = 1;
    }

    matrix_t ideal_matrix;
    
    ideal_matrix.rows = 4;
    ideal_matrix.columns = 3;

    int array[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, ELEMENT, 0};
    ideal_matrix.matrix = (int **)calloc(ideal_matrix.rows, sizeof(int *));
    
    int index = 0;
    for (int i = 0; i < ideal_matrix.rows; i++)
    {
        (ideal_matrix.matrix)[i] = (int *)calloc(ideal_matrix.columns, sizeof(int));
        for (int j = 0; j < ideal_matrix.columns; j++)
            ideal_matrix.matrix[i][j] = array[index++];
    }

    int index_row = 3;
    int index_column = 1;

    int code = insert_el_in_col(&test_matrix, index_row, index_column, ELEMENT);
    if (code == PASSED)
        if (compare_matrices(test_matrix, ideal_matrix) == DIFFERENT)
            code = FAILED;

    free_matrix(&test_matrix);
    free_matrix(&ideal_matrix);

    return code;
}


int trivial_testing()
{
    matrix_t test_matrix;
    
    test_matrix.rows = 3;
    test_matrix.columns = 3;
    
    test_matrix.matrix = (int **)calloc(test_matrix.rows, sizeof(int *));
    for (int i = 0; i < test_matrix.rows; i++)
    {
        (test_matrix.matrix)[i] = (int *)calloc(test_matrix.columns, sizeof(int));
        for (int j = 0; j < test_matrix.columns; j++)
            test_matrix.matrix[i][j] = 1;
    }

    matrix_t ideal_matrix;
    
    ideal_matrix.rows = 4;
    ideal_matrix.columns = 3;

    int array[] = { 1, 1, 1, 1, ELEMENT, 1, 1, 1, 1, 0, 1, 0};
    ideal_matrix.matrix = (int **)calloc(ideal_matrix.rows, sizeof(int *));
    
    int index = 0;
    for (int i = 0; i < ideal_matrix.rows; i++)
    {
        (ideal_matrix.matrix)[i] = (int *)calloc(ideal_matrix.columns, sizeof(int));
        for (int j = 0; j < ideal_matrix.columns; j++)
            ideal_matrix.matrix[i][j] = array[index++];
    }

    int index_row = 1;
    int index_column = 1;

    int code = insert_el_in_col(&test_matrix, index_row, index_column, ELEMENT);
    if (code == PASSED)
        if (compare_matrices(test_matrix, ideal_matrix) == DIFFERENT)
            code = FAILED;

    free_matrix(&test_matrix);
    free_matrix(&ideal_matrix);

    return code;
}


int matrixgame_insert_el_in_col_test()
{
    int code = 0;

    code += negative_indices_testing();
    code += indices_beyond_testing();
    code += calloc_reject_testing();
    code += insert_in_new_row_testing();
    code += trivial_testing();

    printf("%d tests successfully passed out of %d", TESTS_AMOUNT - code, TESTS_AMOUNT);

    return code;
}


int main()
{
    if (matrixgame_insert_el_in_col_test() != PASSED)
    {
        return FAILED;
    }

    return PASSED;
}
