#include "../include/create_label_MExpences.h"

#include <time.h>
#include <stdio.h>
#define FORMAT "Траты за %s месяц: %d₽"
#define FAIL "Не удалось посчитать траты за месяц"

static char*
get_labeltext(char* buffer)
{
	char month[3];
	time_t curtime;
	struct tm* tm_inf;
	time(&curtime);
	tm_inf = localtime(&curtime);
	strftime(month, 3, "%m", tm_inf);
	
	int expences = 0;
	int cnt = snprintf(buffer, 99, FORMAT, month, expences);
	if (snprintf(buffer, cnt+1, FORMAT, month, expences) == 0)
		return FAIL;	
	return buffer;
}

uiLabel* LabelMEx;

uiLabel* create_label_MExpencces(void)
{
    char buffer[99];
    LabelMEx = uiNewLabel(get_labeltext(buffer));
    return LabelMEx;
}

