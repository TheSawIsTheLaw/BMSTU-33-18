#include "../include/create_operations_page.h"

void createOperationsPage(uiTab *operationsTab)
{
    uiBox *operationsPage = uiNewVerticalBox();
    uiTabAppend(operationsTab, "Операции с картами", uiControl(operationsPage));
}

