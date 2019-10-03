#include <stdio.h>
#include <stdlib.h>

#include "../headers/leftappend.h"
//#include "arrgame_functions_create.c"


#define FALSE_SIZE -111

static int wident_array(int *array, const int new_size)
{
    int *new_array = (int *) realloc(array, (new_size + 3) * sizeof(int));
    if (new_array)
    {
        array = new_array;
        new_array = NULL;
    }
    else
        return FALSE_SIZE;
    
    return new_size;
}

static void add_by_pos(int *array, const int size, const int element, int *const index)
{
    for (int *i = array + size ; i >= index; i--)
        *(i + 1) = *i;
    
    (*(array - 1))++;

    *array = element;
}

int *leftappend(int *array, int element)
{
    int real_size = *(array - 2); 
    int cur_size = *(array - 1);
    int temp_size = 0;

    if (cur_size == (real_size))
    {
        temp_size = wident_array(array - 3, (real_size * 2 + 3));

        if (temp_size < 0)
        {
            puts("Не удалось добавить элемент!");
            return NULL;
        }
        else
            real_size = temp_size;
    }

    add_by_pos(array, cur_size, element, array);
    cur_size++;
    if (cur_size > *(array - 3))
        *(array - 3) = cur_size;
    
    *(array - 2) = real_size;
    
    return array;
}


/*int main(void)
{
    int *array = create(100);
    
    printf("%d %d %d\n\n", *(array - 1), *(array - 2), *(array - 3));
    
    for (int i = 0; i < 100; i++)
    {
        *(array - 1) += 1;
        array[i] = i * 2;
    }
    
    for (int i = 0; i < 100; i++)
        printf("\n %d) %d \n", i, array[i]);
    array = leftappend(array, 67);
    array = leftappend(array, 67);
    array = leftappend(array, 67);
    array = leftappend(array, 67);
    array = leftappend(array, 67);
    printf("\n %d \n", *array);
    
    printf("%d %d %d\n\n", *(array - 1), *(array - 2), *(array - 3));
    
    for (int i = 0; i <= 100; i++)
        printf("\n %d) %d \n", i, array[i]);
    
    
    
    return 0;
}*/

