#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ui.h"
#include "../include/checkEntryCard.h"


int checkEntryCard(const char *string)
{
    int count = 0;
    while (*string != '\0')
    {
        if (*string < 48 || *string > 57)
        {
            return 1;
        }
        count++;
        *string++;
    }
    if (count == 13 || count == 16 || count == 19)
    {
        return 0;
    }
    return 1;
}