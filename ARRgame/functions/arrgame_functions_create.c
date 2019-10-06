#include <stdio.h>
#include <stdlib.h>

#include "../headers/arrgame.h"

#define COUNT_NEED_ELEMENT 3

#define NO_CORRECT_SIZE_ARRAY 101
#define MEMORY_ERROR 102

int *arrgame_create(const int sizeArray)
{
    if (sizeArray <= 0)
        return NULL;

    int* pointUserStart;
    int allocatSize = 0;


    pointUserStart =
        (int*)calloc((sizeArray) + COUNT_NEED_ELEMENT,  sizeof(int));

    if (pointUserStart)
    {
        allocatSize = sizeArray;
    }
    else
    {
        puts("Не удалось выделить память.");
        return NULL;
    }


    //array[0] - длинна массива, запрошенного пользователем
    *pointUserStart = sizeArray;

    //array[1] - количество аллоцированнх элементов(не считая первых 3х)
    pointUserStart = pointUserStart + 1;
    *pointUserStart = allocatSize;

    //array[2] - количество занятых ячеек
    pointUserStart = pointUserStart + 1;
    *pointUserStart = 0;

    pointUserStart = pointUserStart + 1;

    return pointUserStart;
}
