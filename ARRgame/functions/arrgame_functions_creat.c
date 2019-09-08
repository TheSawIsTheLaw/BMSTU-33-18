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
    
    int realSize = 0;
    int* pointUserStart;   
    pointUserStart = 
        (int*)calloc((sizeArray + COUNT_NEED_ELEMENT), sizeof(int));
    
    if (pointUserStart)
    {
        int *newPointSize = realloc(pointUserStart, 
                (sizeArray * 2 + COUNT_NEED_ELEMENT));
        if (newPointSize)
        {
            realSize = sizeArray * 2; 
            pointUserStart = newPointSize;
            newPointSize = NULL;
        }
        else
            realSize = sizeArray;
    }
    else
    {
        puts("Не удалось выделить память!!!");
        //return MEMORY_ERROR;
    }
    
    //array[0]
    // размер массива
    *pointUserStart = sizeArray; 
    
    //array[1]
    // количество аллоцированных элементов (не учитывая первые три)
    pointUserStart += 1;
    *pointUserStart = realSize;
    
    //array[2]
    // фактическая занятость массива
    pointUserStart += 1;
    *pointUserStart = 0;
    return pointUserStart;
}

/*
int main()
{
    int* p = creat(10);
    return 0;
}*/

