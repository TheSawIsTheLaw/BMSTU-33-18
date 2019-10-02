#include "../headers/matrixgame_headers_mult_matrices.h"
#include <stdio.h>
#include <stdlib.h>

#define READ 1
#define ERROR_READ 2
#define OK 0
#define MALLOC_ERROR 3
#define FILE_ERROR 4
#define MATRIX_DATA_FILE "tests/file_with_matrices.txt"
// макроопределения из файла с функцией
#define OK 0 // Код корректного выполнения функции
#define SIZE_ERROR 217 // Размеры 3 матриц (2 множителей и результата) не корректны для проведения матричного умножения
#define MATRIX_DATA_ERROR 117 // Указатель на поле с данными указывает на NULL
#define POINTER_ERROR 170 // Указатель на матрицу, переданный аргументом, указывает на NULL


// Выходные данные:
// 1 == матрицы идентичны
// 0 == матрицы отличаются
int matrix_cmp(const matrix_t *const matrix1, const matrix_t *const matrix2)
{
    if (matrix1->rows != matrix2->rows || matrix2->columns != matrix1->columns)
        return 0;
    for (int i = 0; i < matrix1->rows; i++)
        for (int j = 0; j < matrix1->columns; j++)
            if (*(*(matrix1->matrix + i) + j) != *(*(matrix2->matrix + i) + j))
                return 0;
    return 1;
}

int print_matrix(matrix_t *const matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
            printf("%d   ", matrix->matrix[i][j]);
        puts("\n");
    }
            
}

int create_matrix(matrix_t *const matrix, const int rows, const int columns)
{
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->matrix = (int **) malloc(rows * sizeof(int *));
    if (matrix->matrix == NULL)
        return MALLOC_ERROR;
    for (int i = 0; i < rows; i++)
    {
        matrix->matrix[i] = (int *) malloc(columns * sizeof(int));
        if (matrix->matrix[i] == NULL)
        {
            while (i > 0)
                free(matrix->matrix[--i]);
            free(matrix->matrix);
            return MALLOC_ERROR;
        }
    }
    return OK;
}

int get_matrix_from_file(matrix_t *const matrix, FILE *const f)
{
    for (int i = 0; i < matrix->rows; i++)
        for (int j = 0; j < matrix->columns; j++)
            if (fscanf(f, "%d", &matrix->matrix[i][j]) != READ)
                return ERROR_READ;
    return OK;
}

void delete_matrix(matrix_t *const matrix)
{
    for (int i = 0; i < matrix->rows; i++)
       free(matrix->matrix[i]);
    free(matrix->matrix); 
}

int test_func()
{
    int err_cnt = 0;
    matrix_t test_matrix1;
    matrix_t test_matrix2;
    matrix_t res_test_matrix;
    matrix_t res_matrix;
    FILE *matrix_data;

    matrix_data = fopen(MATRIX_DATA_FILE, "r");
    if (matrix_data == NULL)
        return FILE_ERROR;

    // 1-ый негатив: проверка обработки поступления нулевого указателя в качестве аргумента
    // (так как проверка на каждый аргумент одинакова, можно проверить на одном из трех)
    if (mult_matrices(NULL, &test_matrix2, &res_test_matrix) != POINTER_ERROR)
    {
        puts("Ошибка обработки нулевого указателя в качестве аргумента!");
        err_cnt++;
    }

    if (create_matrix(&test_matrix1, 3, 3) != OK)
        return MALLOC_ERROR;
    if (create_matrix(&test_matrix2, 3, 3) != OK)
        return MALLOC_ERROR;
    if (create_matrix(&res_test_matrix, 3, 3) != OK)
        return MALLOC_ERROR;
    if (create_matrix(&res_matrix, 3, 3) != OK)
        return MALLOC_ERROR;

    {
        // 2-ой негатив: данные одной из матриц указывают на NULL
        int **temp = res_test_matrix.matrix;
        res_test_matrix.matrix = NULL;
        if (mult_matrices(&test_matrix1, &test_matrix2, &res_test_matrix) != MATRIX_DATA_ERROR)
        {
            puts("Ошибка обработки матрицы с указателем на несуществующую память");
            err_cnt++;
        }
        res_test_matrix.matrix = temp;
        res_test_matrix.rows = -2;
        test_matrix1.rows = -2;
        // 3-ий негатив: выполняется правило MxN * NxK = MxK, но M - отрицательный
        if (mult_matrices(&test_matrix1, &test_matrix2, &res_test_matrix) != SIZE_ERROR)
        {
            puts("Не обработана матрица некорректного размера");
            err_cnt++;
        }
        test_matrix1.rows = 3;
        res_test_matrix.rows = 2;
        // 4-ый негатив: не выполняется правило MxN * NxK = MxK
        if (mult_matrices(&test_matrix1, &test_matrix2, &res_test_matrix) != SIZE_ERROR)
        {
            puts("Не обработана матрица некорректного размера");
            err_cnt++;
        }
        res_test_matrix.rows = 3;
    }
    // Позитивы
    // 1 позитив: умножение 2 квадратных матриц
    if (get_matrix_from_file(&test_matrix1, matrix_data) != OK)
        return ERROR_READ;
    if (get_matrix_from_file(&test_matrix2, matrix_data) != OK)
        return ERROR_READ;
    if (get_matrix_from_file(&res_matrix, matrix_data) != OK)
        return ERROR_READ;

    if (mult_matrices(&test_matrix1, &test_matrix2, &res_test_matrix) != OK)
    {
        puts("Корректный тест завершился как некорректный");
        err_cnt++;
    }

    if (matrix_cmp(&res_test_matrix, &res_matrix) != 1)
    {
        puts("Умножение квадратных матриц дало неверный результат");
        err_cnt++;
    }

    delete_matrix(&test_matrix1);
    delete_matrix(&test_matrix2);
    delete_matrix(&res_test_matrix);
    delete_matrix(&res_matrix);

    // 2 позитив: умножение квадратной матрицы на прямоугольную
    if (create_matrix(&test_matrix1, 4, 3) != OK)
        return MALLOC_ERROR;
    if (create_matrix(&test_matrix2, 3, 3) != OK)
        return MALLOC_ERROR;
    if (create_matrix(&res_test_matrix, 4, 3) != OK)
        return MALLOC_ERROR;
    if (create_matrix(&res_matrix, 4, 3) != OK)
        return MALLOC_ERROR;

    if (get_matrix_from_file(&test_matrix1, matrix_data) != OK)
        return ERROR_READ;
    if (get_matrix_from_file(&test_matrix2, matrix_data) != OK)
        return ERROR_READ;
    if (get_matrix_from_file(&res_matrix, matrix_data) != OK)
        return ERROR_READ;

    if (mult_matrices(&test_matrix1, &test_matrix2, &res_test_matrix) != OK)
    {
        puts("Корректный тест завершился как некорректный");
        err_cnt++;
    }

    if (matrix_cmp(&res_test_matrix, &res_matrix) != 1)
    {
        puts("Умножение прямоугольной и квадратной матриц дало неверный результат");
        err_cnt++;
    }

    delete_matrix(&test_matrix1);
    delete_matrix(&test_matrix2);
    delete_matrix(&res_test_matrix);
    delete_matrix(&res_matrix);

    // 3 позитив: умножение 2 прямоугольных матриц
    if (create_matrix(&test_matrix1, 4, 3) != OK)
        return MALLOC_ERROR;
    if (create_matrix(&test_matrix2, 3, 2) != OK)
        return MALLOC_ERROR;
    if (create_matrix(&res_test_matrix, 4, 2) != OK)
        return MALLOC_ERROR;
    if (create_matrix(&res_matrix, 4, 2) != OK)
        return MALLOC_ERROR;

    if (get_matrix_from_file(&test_matrix1, matrix_data) != OK)
        return ERROR_READ;
    if (get_matrix_from_file(&test_matrix2, matrix_data) != OK)
        return ERROR_READ;
    if (get_matrix_from_file(&res_matrix, matrix_data) != OK)
        return ERROR_READ;

    if (mult_matrices(&test_matrix1, &test_matrix2, &res_test_matrix) != OK)
    {
        puts("Корректный тест завершился как некорректный");
        err_cnt++;
    }

    if (matrix_cmp(&res_test_matrix, &res_matrix) != 1)
    {
        puts("Умножение 2 прямоугольных матриц дало неверный результат");
        err_cnt++;
    }

    delete_matrix(&test_matrix1);
    delete_matrix(&test_matrix2);
    delete_matrix(&res_test_matrix);
    delete_matrix(&res_matrix);
    fclose(matrix_data);

    printf("Тестирование закончено. Пройдено %d из 7 тестов!\n", 7 - err_cnt);
    return err_cnt;
}

int main()
{
    int err_count;
    err_count = test_func();
    return err_count;
}
