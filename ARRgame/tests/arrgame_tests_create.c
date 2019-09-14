#include<stdio.h>
#include<stdlib.h>
#include "../headers/arrgame_headers_create.h"
#define TRUE 1
#define FALSE 0
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
    	int n = -8;
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

