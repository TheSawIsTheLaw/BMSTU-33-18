#include "../headers/matrixgame_headers_matrix_t.h"
#include "../headers/matrixgame_headers_add_column.h"
//#include "../headers/matrixgame_headers_create_matrix.h"

#define PASS 0
#define FAIL 1

/*
функция черненко copy-paste
*/

#include "../../ARRgame/functions/arrgame_functions_create.c"

typedef int mtype;

#define MEM_ALLOC_FAILURE -101  
#define SERVICE_DATA_OFFSET -3  
#define SUCCESS 0               

static void clean_up_row_pointers(mtype *const * start, mtype *const *const end)
{
    for (; start < end; start++)
        free((*start) + SERVICE_DATA_OFFSET);
}

static int create_matrix(matrix_t *const matrix, const int rows, const int columns)
{
    void *temp = malloc(sizeof(mtype*) * rows);
    if (!temp)
        return MEM_ALLOC_FAILURE;

    matrix->matrix = (mtype**)temp;

    mtype *const *const end = matrix->matrix + rows;
    for (mtype** cur = matrix->matrix; cur < end; cur++)
    {
        temp = create(columns);
        if (!temp)
        {
            clean_up_row_pointers(matrix->matrix, cur);
            free(matrix->matrix);
            return MEM_ALLOC_FAILURE;
        }
        
        *cur = (mtype*)temp;
    }

    matrix->columns = columns;
    matrix->rows = rows;

    return SUCCESS;
}

/*
конец функции влада
*/

static void free_matrix(matrix_t *const matrix)
{
    int i = 0;
    while (i < matrix -> rows)
    {
        free((matrix->matrix)[i]);
        i ++;
    }
}




//c<10
int test_common(int r, int c)
{
    matrix_t test_matrix;
    if (create_matrix(&test_matrix, r, c))
        return FAIL;
    //нецелесообразно проверки для динамики вектора писать
    //а еще в функции нет проверки валидности vect 
    //и да, класс ошибки вылета create matrix такой же.
    //лень - двигатель прогресса, sry
    int col[10] = {1,2,3,4,5,6,7,8,9,0};
    if (add_column(&test_matrix, col))
    {
		free_matrix(&test_matrix);
        return FAIL;
    }
    if (test_matrix.columns == (c+1))
    {
        free_matrix(&test_matrix);
        return PASS;
    }
    else 
    {
        free_matrix(&test_matrix);
        return FAIL;
    }
}


int test_nonexist_matrix(void)
{
	matrix_t test_matrix;
    if (create_matrix(&test_matrix, 5, 5))
        return FAIL;
    int col[10] = {1,2,3,4,5,6,7,8,9,0};
    test_matrix.rows = -12; 
    if (add_column(&test_matrix, col))
        return PASS;
    return FAIL;
}


/*
учитывая архитектуру функции, очень сложно найти такой размер матрицы,
который позволит realloc вернуть 0 при добавлении столбца,
такой тест слишком зависит от мащины. идея - добавить столбец,
если матрица состоит из 1 очень длинного столбца, но тогда
ЭТОТ столбец должен уместится в памяти, а реаллок ДВУХ таких
столбцов - нет. подобрать такую длинну столбца я не смог.

int test_add_mem_fail(void)
{
    matrix_t test_matrix;
    if (create_matrix(&test_matrix, 5, 5))
        return FAIL;
    int col[10] = {1,2,3,4,5,6,7,8,9,0};
    test_matrix.rows = -1; 
    if (add_column(&test_matrix, col))
        return PASS;
    return FAIL;
}
*/
#define TEST_COUNT 2

int matrixgame_add_column_test(void)
{
    int err_count = 0;
    err_count += test_common(5,7);
    err_count += test_nonexist_matrix();

    if (err_count)
    {
        printf("%d failed tests out of %d\n", err_count, TEST_COUNT);
        return FAIL;
    }
    
    return PASS;
}

int main(void)
{
    if (matrixgame_add_column_test() != PASS)
        return FAIL;
    return PASS;
}
