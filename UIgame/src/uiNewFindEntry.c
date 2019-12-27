#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ui.h"
#include "../include/create_main_page.h"
#include "../include/uiNewFindEntry.h"

uiEntry* uiNewFindEntry(void)
{
    static uiEntry *entry;
    entry =  uiNewSearchEntry();
    return entry;
}

