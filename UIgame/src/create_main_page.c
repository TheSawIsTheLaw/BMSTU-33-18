#include "../include/create_main_page.h"

void createMainPage(uiTab *mainTab)
{
	uiBox *mainPage = uiNewVerticalBox();
    uiTabAppend(mainTab, "Главная страница", uiControl(mainPage));
}
