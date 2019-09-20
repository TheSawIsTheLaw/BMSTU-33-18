#include "../headers/arrgame_headers_clean.h"

#define ZERO  0

void test_clean()
{
	// Test № 1
	//  3 элемента
	{
		int *buf = NULL;
		int *p_beg;
		int *p_end;
		int n = 3;
		buf = malloc(n * sizeof(int));

		p_beg = buf;
		p_end = buf + n;	

		for (int i = 0; i < n; i++)
			buf[i] = i;

		if (clean(p_beg, p_end) == ZERO)
			printf("Test №1: Passed\n");
		else
			printf("Test №1: Failed\n");
	}

	// Test № 2
	// 0 элементов
	{
		int *buf = NULL;
		int *p_beg;
		int *p_end;
		int n = 0;
		buf = malloc(n * sizeof(int));

		p_beg = buf;
		p_end = buf + n;	

		for (int i = 0; i < n; i++)
			buf[i] = i;

		if (clean(p_beg, p_end) == ZERO)
			printf("Test №2: Passed\n");
		else
			printf("Test №2: Failed\n");
	}

	// Test № 3
	// 1 элемент
	{
		int *buf = NULL;
		int *p_beg;
		int *p_end;
		int n = 1; 
		buf = malloc(n * sizeof(int));

		p_beg = buf;
		p_end = buf + n;	

		for (int i = 0; i < n; i++)
			buf[i] = i;

		if (clean(p_beg, p_end) == ZERO)
			printf("Test №3: Passed\n");
		else
			printf("Test №3: Failed\n");
	}

	
	// Test № 4
	// 10 000 элементов
	{
		int *buf = NULL;
		int *p_beg;
		int *p_end;
		int n = 10000;
		buf = malloc(n * sizeof(int));

		p_beg = buf;
		p_end = buf + n;	

		for (int i = 0; i < n; i++)
			buf[i] = i;

		if (clean(p_beg, p_end) == ZERO)
			printf("Test №4: Passed\n");
		else
			printf("Test №4: Failed\n");
	}
	
}

int main()
{
	test_clean();

	return 0;
}
