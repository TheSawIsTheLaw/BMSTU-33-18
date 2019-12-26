#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ui.h"
#include "../include/create_main_page.h"
#include "../include/create_entry_sum.h"

uiEntry *entrySum;

static uiEntry* create_entry_sum(void)
{
    entrySum = uiNewEntry();
    uiEntrySetText(entrySum, "Sum");
    return entrySum;
}