#include "../include/create_label_MExpences.h"

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FORMAT "Траты за %s: %d ₽"
#define FAIL "Не удалось посчитать траты за месяц"

static char*
get_labeltext(char* buffer)
{
	char month_int[3];
    char month[20];

	time_t curtime;
	struct tm* tm_inf;
	time(&curtime);
	tm_inf = localtime(&curtime);
	strftime(month_int, 3, "%m", tm_inf);
	
	int expences = 0;

    switch (atoi(month_int))
    {
        case 1:
            strcpy(month, "Январь");
            break;
        case 2:
            strcpy(month, "Февраль");
            break;
        case 3:
            strcpy(month, "Март");
            break;
        case 4:
            strcpy(month, "Апрель");
            break;
        case 5:
            strcpy(month, "Май");
            break;
        case 6:
            strcpy(month, "Июнь");
            break;
        case 7:
            strcpy(month, "Июль");
            break;
        case 8:
            strcpy(month, "Август");
            break;
        case 9:
            strcpy(month, "Сентябрь");
            break;
        case 10:
            strcpy(month, "Октябрь");
            break;
        case 11:
            strcpy(month, "Ноябрь");
            break;
        case 12:
            strcpy(month, "Декабрь");
            break;
    }

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

