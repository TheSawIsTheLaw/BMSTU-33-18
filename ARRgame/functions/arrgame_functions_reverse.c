/*
 Функция, которая "переворачивает" массив
 Передается отрезок, концы которого являются валидными указателями
 */

#include <stdio.h>
#include "../headers/arrgame_functions_reverse.h"
#define ZERO 0
#define SUCCESS 0
#define ERROR 1
#define MIN_LENGTH 1
#define TWO 2

void change(int *first, int *second) //Принимает указатели на два числа в массиве, которые необходимо поменять местами
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

int reverse(int *head, int *tail) //Принимает указатели на интервал, который необходимо перевернуть
{
    long long int len = tail - head;
    
    if (len < MIN_LENGTH)
        return ERROR;
    
    for (int i = ZERO; i < len / TWO; i++)
        change(head++, tail--);
    
    return SUCCESS;
}
