#include "../include/create_entry_sum.h"

uiEntry *entry_card_num;

uiEntry *create_entry_cardnum()
{
    entry_card_num = uiNewEntry();
    uiEntrySetText(entry_card_num, "Номер карты");

    return entryCardNum;
}
