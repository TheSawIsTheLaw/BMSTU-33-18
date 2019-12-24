#include "../include/create_account_page.h"

void createAccountPage(uiTab *mainTab)
{
    uiBox *accountPage = uiNewVerticalBox();
    uiTabAppend(mainTab, "Информация об аккаунте", uiControl(accountPage));
}

