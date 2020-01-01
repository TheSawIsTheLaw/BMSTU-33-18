#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ui.h"
#include "../include/checkEntryCard.h"


//    Номера кредитных карт в России, как правило, состоят из 16 цифр, 
//    однако встречаются 13- и 19-значные номера. 
//    19-значные номера обычно присваиваются дополнительным картам,
//    выпущенным в рамках одного клиентского счета,
//    13-значные номера можно увидеть на старых пластиковых картах.


//  Ввод слитный, пробелы не поддерживаются.

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
        string++;
    }

    if (count == 13 || count == 16 || count == 19)
    {
        return 0;
    }
    return 1;
}
