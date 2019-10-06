#ifndef __MATRIXGAME_HEADERS_MATRIX_T_H__
#define __MATRIXGAME_HEADERS_MATRIX_T_H__

typedef struct 
{
	int rows; // кол-во строк матрицы
	int columns; // кол-во столюцов матрицы
	int **matrix; // массив указателей на каждую
	                     // из строк матрицы
} matrix_t;


#endif
