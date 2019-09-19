#include <stdio.h>
#include <stdlib.h>

#include "../headers/arrgame_functions_clean.h"

int clean(int *p_beg, int *p_end)
{
	int *buf = p_beg;

	while (p_beg != p_end)
	{
		p_beg = NULL;
		p_beg++;
	}

	free(buf);

	return 0;
}
