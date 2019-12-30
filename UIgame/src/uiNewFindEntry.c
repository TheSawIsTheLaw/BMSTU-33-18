#include "../include/uiNewFindEntry.h"

uiEntry* uiNewFindEntry(void)
{
    static uiEntry *entry;
    entry =  uiNewSearchEntry();
    return entry;
}

