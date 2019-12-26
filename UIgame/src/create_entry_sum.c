#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ui.h"
#include "../include/create_main_page.h"
#include "../include/create_entry_sum.h"

uiEntry *entrySum;

static void create_entry_sum(void)
{
    entrySum = uiNewEntry();
    uiBoxAppend(bxMain, uiControl(entrySum),0);
    uiEntrySetText(entrySum, "Sum");
    return;
}