#include <stdlib.h>

#include "../headers/arrgame.h"

int arrgame_clean(int *p_beg, int *p_end)
{
	int *buf = p_beg;

	while (p_beg != p_end)
	{
		*p_beg = 0;
		p_beg++;
	}

	free(buf);

	return 0;
}
