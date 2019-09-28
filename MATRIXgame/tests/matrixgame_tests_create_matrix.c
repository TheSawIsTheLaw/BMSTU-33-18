#include "../headers/matrixgame_headers_matrix_t.h"
#include "../headers/matrixgame_headers_create_matrix.h"
#include <stdio.h>
#include <stdlib.h>

#define METADATA_OFFSET -3

#define PASSED 0
#define FAILED 1

#define NOERR 0

#define M_EQ 0
#define M_NOT_EQ -1

#define MALLOC_FAILURE -1

void print_all(matrix_t *const sample)
{
    for (int j = 0; j < sample->rows; j++)
    {
        for (int i = 0; i < sample->columns; i++)
            printf("%5d ", sample->matrix[j][i]);

        printf("\n");
    }
}

void write_all(matrix_t *const sample)
{
    for (int j = 0; j < sample->rows; j++)
        for (int i = 0; i < sample->columns; i++)
            sample->matrix[j][i] = (j+1) * (i+2);
}

void print_plain(int *const *const sample,
                 const int rows, const int columns)
{
    for (int j = 0; j < rows; j++)
    {
        for (int i = 0; i < columns; i++)
            printf("%5d ", sample[j][i]);
        printf("\n");
    }
    
}

int alloc_plain(int ***sample,
                 const int rows, const int columns)
{
    (*sample) = malloc(sizeof(int *) * rows);
    if (!(*sample))
        return MALLOC_FAILURE;

    for (int i = 0; i < rows; i++)
        if(!(*(*sample + i) = malloc(sizeof(int) * columns)))
            return MALLOC_FAILURE;

    return NOERR;
}

void free_plain(int ***sample,
                const int rows, const int cols)
{
    for (int j = 0; j < rows; j++)
        free((*sample)[j]);

    free(*sample);
}
            
void write_plain(int *const *const sample,
                 const int rows, const int columns)
{
    for (int j = 0; j < rows; j++)
        for (int i = 0; i < columns; i++)
            sample[j][i] = (j+1) * (i+2);
}

void free_all(matrix_t *const sample)
{
    for (int j = 0; j < sample->rows; j++)
        free(sample->matrix[j] + METADATA_OFFSET);

    free(sample->matrix);
}

int compare_matrixes(const matrix_t *const tested, int **expected)
{
    for (int j = 0; j < tested->rows; j++)
        for (int i = 0; i < tested->columns; i++)
            if (tested->matrix[j][i] != expected[j][i])
                return M_NOT_EQ;

    return M_EQ;
}

int test_create(const int rows, const int cols)
{
    matrix_t result;
    int rc = create_matrix(&result, rows, cols);
    if (rc)
        return rc;

    int **expected;
    rc = alloc_plain(&expected, rows, cols);
    if (rc)
        return rc;

    write_plain((int**)expected, rows, cols);
    write_all(&result);
    
    if (compare_matrixes(&result, (int**)expected))
    {
        printf("Failed test on size %d rows %d cols\n", rows, cols);
        printf("expected: \n");
        print_plain((int**)expected, rows, cols);
        printf("result was: \n");
        print_all(&result);

        free_plain(&expected, rows, cols);
        free_all(&result);
        
        return FAILED;
    }
    else
    {
        free_plain(&expected, rows, cols);
        free_all(&result);
        return PASSED;
    }
}

#define TEST_COUNT 3

int matrixgame_create_matrix_test()
{
    int errc = 0;

    errc += test_create(5, 6);
    errc += test_create(1, 5);
    errc += test_create(4, 1);

    if (errc)
    {
        printf("%d failed tests out of %d\n", errc, TEST_COUNT);
        return FAILED;
    }

    return PASSED;
}

int main(void)
{
    if (matrixgame_create_matrix_test())
        return FAILED;
    
    return PASSED;
}
