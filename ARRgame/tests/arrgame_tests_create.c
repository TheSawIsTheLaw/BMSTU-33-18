#include<stdio.h>
#include<stdlib.h>
//#include "../headers/arrgame_headers_create.h"
#define TRUE 1
#define FALSE 0

#define COUNT_NEED_ELEMENT 3

#define NO_CORRECT_SIZE_ARRAY 101
#define MEMORY_ERROR 102

int* create(const int sizeArray)
{
    if (sizeArray <= 0)
        return NULL;
       
    int* pointUserStart;
    int allocatSize = 0;


    pointUserStart = 
        (int*)calloc((sizeArray * 2) + COUNT_NEED_ELEMENT,  sizeof(int));
    
    if (pointUserStart)
    {
        allocatSize = sizeArray * 2;
    }
    else
    {
        puts("Не удалось выделить память.");
    }
        
    
    //array[0] - длинна массива, запрошенного пользователем
    *pointUserStart = sizeArray;
    
    //array[1] - количество аллоцированнх элементов(не считая первых 3х)
    pointUserStart = pointUserStart + 1;
    *pointUserStart = allocatSize;
    
    //array[2] - количество занятых ячеек
    pointUserStart = pointUserStart + 1;
    *pointUserStart = 0;

    pointUserStart = pointUserStart + 3;
    
    return pointUserStart;
}

void Test_create(void)
{
	// Создать массив нулевого размера
	{
		int n = 0;
		printf("Size of arr = 0: ");
		if (create(n) == NULL)
			printf("OK\n");
		else
			printf("FAIL\n");
	}
    // Создать массив отрицательного размера
    {
    	int n = -8;
    	printf("Size of arr < 0: ");
		if (create(n) == NULL)
			printf("OK\n");
		else
			printf("FAIL\n");
    }
    // Создать массив корректного размера
    {
    	int n = 8;
    	printf("Size of arr is correct: ");
		if (create(n) != NULL)
			printf("OK\n");
		else
			printf("FAIL\n");
    }
}

int main(void)
{
	Test_create();
	return 0;
}

