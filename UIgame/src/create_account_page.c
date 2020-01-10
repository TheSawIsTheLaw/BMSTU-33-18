
#include "../include/create_account_page.h"

void createAccountPage(uiTab *mainTab)
{
    uiTabAppend(mainTab, "Информация об аккаунте", createAccTable());
}
