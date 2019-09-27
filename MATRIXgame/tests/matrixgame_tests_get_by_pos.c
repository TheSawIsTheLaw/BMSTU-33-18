#include <stdio.h>

#include "../headers/matrixgame_headers_get_by_pos.h"
#include "../headers/matrixgame_headers_create_matrix.h"
#include "../headers/matrixgame_headers_free_matrix.h"

/*
Terminal colored output.
*/
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define DIMENSION_OUT_OF_RANGE_ERROR 218
#define FALSE_POINTER_ERROR 219

#define PASSED 0
#define FAILED 1

/*
Fill matrix with sequence of numbers for 0 to rows * cols - 1.

Input data:
* matrix_t *const to_fill - matrix to be filled.
*/
void fill_matrix(matrix_t *const to_fill)
{
    int filled = 0;

    for (int row = 0; row < to_fill->rows; ++row)
    {
        for (int col = 0; col < to_fill->columns; ++col)
        {
            *(*(to_fill->matrix + row) + col) = filled;
            filled++;
        }
    }
}

/*
Debug output for matrix.

Input data:
* const matrix_t *const to_output - matrix to be outputed.
*/
/*
void output_matrix(const matrix_t *const to_output)
{
    for (int row = 0; row < to_output->rows; ++row)
    {
        for (int col = 0; col < to_output->columns; ++col)
        {
            printf("%8d ", *(*(to_output->matrix + row) + col));
        }
        printf("\n");
    }
}
*/

int matrixgame_get_by_pos_test()
{
    int err_cnt = 0;

    /*
    Test case 0. Normal mode.
    */
    matrix_t test_matrix_0;
    create_matrix(&test_matrix_0, 5, 5);
    fill_matrix(&test_matrix_0);

    if (get_by_pos(&test_matrix_0, 3, 3) != 18)
    {
        printf(ANSI_COLOR_RED "TEST #0 FAILED\n" ANSI_COLOR_RESET);
        err_cnt++;
    }

    else
    {
        printf(ANSI_COLOR_GREEN "TEST #0 PASSED\n" ANSI_COLOR_RESET);
    }

    /*
    Test case 1. Normal mode.
    */
    matrix_t test_matrix_1;
    create_matrix(&test_matrix_1, 5, 5);
    fill_matrix(&test_matrix_1);

    if (get_by_pos(&test_matrix_1, 0, 3) != 3)
    {
        printf(ANSI_COLOR_RED "TEST #1 FAILED\n" ANSI_COLOR_RESET);
        err_cnt++;
    }

    else
    {
        printf(ANSI_COLOR_GREEN "TEST #1 PASSED\n" ANSI_COLOR_RESET);
    }

    /*
    Test case 2. Normal mode.
    */
    free_matrix(&test_matrix_1);

    matrix_t test_matrix_2;
    create_matrix(&test_matrix_2, 5, 5);
    fill_matrix(&test_matrix_2);

    if (get_by_pos(&test_matrix_2, 4, 4) != 24)
    {
        printf(ANSI_COLOR_RED "TEST #2 FAILED\n" ANSI_COLOR_RESET);
        err_cnt++;
    }

    else
    {
        printf(ANSI_COLOR_GREEN "TEST #2 PASSED\n" ANSI_COLOR_RESET);
    }

    free_matrix(&test_matrix_2);

    /*
    Test case 3. Negative rows count.
    */
    matrix_t test_matrix_3;
    create_matrix(&test_matrix_3, 5, 5);
    fill_matrix(&test_matrix_3);

    if (get_by_pos(&test_matrix_3, -1, 1) != DIMENSION_OUT_OF_RANGE_ERROR)
    {
        printf(ANSI_COLOR_RED "TEST #3 FAILED\n" ANSI_COLOR_RESET);
        err_cnt++;
    }

    else
    {
        printf(ANSI_COLOR_GREEN "TEST #3 PASSED\n" ANSI_COLOR_RESET);
    }

    free_matrix(&test_matrix_3);

    /*
    Test case 4. Negative columns count.
    */
    matrix_t test_matrix_4;
    create_matrix(&test_matrix_4, 5, 5);
    fill_matrix(&test_matrix_4);

    if (get_by_pos(&test_matrix_4, 0, -1) != DIMENSION_OUT_OF_RANGE_ERROR)
    {
        printf(ANSI_COLOR_RED "TEST #4 FAILED\n" ANSI_COLOR_RESET);
        err_cnt++;
    }

    else
    {
        printf(ANSI_COLOR_GREEN "TEST #4 PASSED\n" ANSI_COLOR_RESET);
    }

    free_matrix(&test_matrix_4);

    /*
    Test case 5. Rows out of range.
    */
    matrix_t test_matrix_5;
    create_matrix(&test_matrix_5, 5, 5);
    fill_matrix(&test_matrix_5);

    if (get_by_pos(&test_matrix_5, 5, 1) != DIMENSION_OUT_OF_RANGE_ERROR)
    {
        printf(ANSI_COLOR_RED "TEST #5 FAILED\n" ANSI_COLOR_RESET);
        err_cnt++;
    }

    else
    {
        printf(ANSI_COLOR_GREEN "TEST #5 PASSED\n" ANSI_COLOR_RESET);
    }

    free_matrix(&test_matrix_5);

    /*
    Test case 6. Columns out of range.
    */
    matrix_t test_matrix_6;
    create_matrix(&test_matrix_6, 5, 5);
    fill_matrix(&test_matrix_6);

    if (get_by_pos(&test_matrix_6, 1, 5) != DIMENSION_OUT_OF_RANGE_ERROR)
    {
        printf(ANSI_COLOR_RED "TEST #6 FAILED\n" ANSI_COLOR_RESET);
        err_cnt++;
    }

    else
    {
        printf(ANSI_COLOR_GREEN "TEST #6 PASSED\n" ANSI_COLOR_RESET);
    }

    /*
    Test case 7. NULL pointer execution.
    */
    matrix_t test_matrix_7;
    create_matrix(&test_matrix_7, 5, 5);
    fill_matrix(&test_matrix_7);
    test_matrix_7.matrix = NULL;

    if (get_by_pos(&test_matrix_7, 0, 1) != FALSE_POINTER_ERROR)
    {
        printf(ANSI_COLOR_RED "TEST #7 FAILED\n" ANSI_COLOR_RESET);
        err_cnt++;
    }

    else
    {
        printf(ANSI_COLOR_GREEN "TEST #7 PASSED\n" ANSI_COLOR_RESET);
    }

    free_matrix(&test_matrix_7);

    if (err_cnt)
    {
        return FAILED;
    }

    return PASSED;
}

int main()
{
    if (matrixgame_get_by_pos_test() != PASSED)
    {
        return FAILED;
    }

    return PASSED;
}
