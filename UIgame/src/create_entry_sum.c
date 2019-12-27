#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ui.h"
#include "../include/create_main_page.h"
#include "../include/create_entry_sum.h"

uiEntry *entrySum;

uiEntry* create_entry_sum(void)
{
    entrySum = uiNewEntry();
    uiEntrySetText(entrySum, "Сумма");
    return entrySum;
}