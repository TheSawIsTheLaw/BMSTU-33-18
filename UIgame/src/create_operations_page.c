#include "../include/create_operations_page.h"

int onClosing1(uiWindow *w, void *data)
{
    uiControlDestroy(uiControl(w));
    return 0;
}

// Вынужденное закрытие окна
int onShouldQuit1(void *data)
{
    uiControlDestroy(uiControl(data));
    return 1;
}

void createOperationsPage(uiWindow *operationWnd)
{
    operationWnd = uiNewWindow("OleneffBank: Account", 400, 400, 0);
    uiWindowSetMargined(operationWnd, 0);
    uiWindowOnClosing(operationWnd, onClosing1, NULL);
    uiOnShouldQuit(onShouldQuit1, operationWnd);
    uiControlShow(uiControl(operationWnd));
}

