#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ui.h"
#include "../include/create_main_page.h"
#include "../include/uiNewFindEntry.h"

static uiEntry *entry;

uiEntry* uiNewFindEntry(void)
{
    entry = uiNewEntry();
}

