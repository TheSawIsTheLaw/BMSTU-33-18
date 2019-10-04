#include "../headers/matrixgame_headers_matrix_t.h"
#include "../headers/matrixgame_headers_create_matrix.h"
#include "../headers/matrixgame_headers_transpose.h"

#include <stdio.h>
#include <stdlib.h>

#define METADATA_OFFSET -3

#define TEST_FAILED 1
#define TEST_SUCCESS 0

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
    int val = 0;
    for (int j = 0; j < sample->rows; j++)
        for (int i = 0; i < sample->columns; i++)
            sample->matrix[j][i] = val++;
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
        if (!(*(*sample + i) = malloc(sizeof(int) * columns)))
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
    int val = 0;
    for (int j = 0; j < columns; j++)
        for (int i = 0; i < rows; i++)
            sample[i][j] = val++;
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

int reverse_test(const int rows, const int cols)
{
    matrix_t result;
    int rc = create_matrix(&result, rows, cols);
    if (rc)
        return rc;

    int **expected;
    rc = alloc_plain(&expected, cols, rows);
    if (rc)
        return rc;

    write_plain((int **)expected, cols, rows);
    write_all(&result);

    transpose(&result);

    if (compare_matrixes(&result, (int **)expected))
    {
        printf("Failed test on size %d rows %d cols\n", rows, cols);
        printf("expected: \n");
        print_plain((int **)expected, cols, rows);
        printf("result was: \n");
        print_all(&result);

        free_plain(&expected, cols, rows);
        free_all(&result);

        return TEST_FAILED;
    }
    else
    {
        free_plain(&expected, cols, rows);
        free_all(&result);
        return TEST_SUCCESS;
    }
}

#define TEST_COUNT 8

int main(void)
{
    setbuf(stdout, NULL);
    int errc = 0;

    errc += reverse_test(3, 3);
    errc += reverse_test(2, 5);
    errc += reverse_test(6, 4);
    errc += reverse_test(5, 1);
    errc += reverse_test(1, 4);
    errc += reverse_test(1, 1);
    
    int errnumber;
    errnumber = transpose(NULL);
    if (errnumber != 411)
        errc += 1;
        
    matrix_t result;
    int rc = create_matrix(&result, 2, 2);
    if (rc)
        return rc;
    result.rows = -2;
    errnumber = transpose(&result);
        if (errnumber != 217)
        errc += 1;
        
    if (errc)
    {
        printf("%d failed tests out of %d\n", errc, TEST_COUNT);
        return TEST_FAILED;
    }
    else
    {
        printf("successfull");
    }
    

    return NOERR;
}
