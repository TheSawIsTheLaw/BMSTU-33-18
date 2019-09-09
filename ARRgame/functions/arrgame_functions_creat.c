#include <stdio.h>
#include <stdlib.h>

#include "../headers/arrgame_headers_creat.h"

#define COUNT_NEED_ELEMENT 3

#define NO_CORRECT_SIZE_ARRAY 101
#define MEMORY_ERROR 102

int* creat(const int sizeArray)
{
    //if (sizeArray < 1)
        //return NO_CORRECT_SIZE_ARRAY;
    
    
       
    int* pointUserStart;
    int allocatSize = 0;


    pointUserStart = 
        (int*)calloc((sizeArray + COUNT_NEED_ELEMENT),  sizeof(int));
    if (pointUserStart)
    {
        int* allocatStart = realloc(pointUserStart,
                (sizeArray * 2 + COUNT_NEED_ELEMENT));
        if (allocatStart)
        {
            pointUserStart = allocatStart;
            allocatStart = NULL;
            allocatSize = sizeArray * 2;
        }
        else
            allocatSize = sizeArray;
    }
    else
    {
        puts("Не удалось выделить память.");
    }
    
    //array[0] - длинна массива, запрошенного пользователем
    *pointUserStart = sizeArray;
    
    //array[1] - количество аллоцированнх элементов(не считая первых 3х)
    pointUserStart++;
    *pointUserStart = allocatSize;
    
    //array[2] - количество занятых ячеек
    pointUserStart++;
    *pointUserStart = 0;

    pointUserStart++;

    return pointUserStart;
}

/*
int main()
{
    int* p = creat(10);
    return 0;
}*/

