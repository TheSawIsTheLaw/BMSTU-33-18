#include "../include/create_main_page.h"
#include "../include/create_main_wnd_table.h"

void createMainPage(uiTab *mainTab)
{
    uiTabAppend(mainTab, "Главная страница", createMainWndTable());
}
