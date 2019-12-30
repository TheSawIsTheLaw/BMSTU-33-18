#include "../include/create_entry_telnum.h"

uiEntry *entry_tel_num;

uiEntry *create_entry_telnum()
{
    entry_tel_num = uiNewEntry();
    uiEntrySetText(entry_tel_num, "Номер телефона\n");

    return entry_tel_num;
}

