 //Функция для подсчета количества вхождений элемента в массив


//#include "../headers/arrgame_headers_count.h"
#include <stdio.h>
#define ERROR_LENGTH 2
#define INITIAL 0
#define CONSTANT 1

int count(const int x, int const* start, int const* end)
{
    int count_element = INITIAL;
    
    if (start >= end)
        return ERROR_LENGTH;
    
    while (start <= end)
        if (*start++ == x)
            count_element++;
   
    return count_element;
}
