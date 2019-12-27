#include "../include/create_operations_page.h"

uiGroup *group;
uiEntry *entryForm;
uiBox *hbox, *vbox;

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
    operationWnd = uiNewWindow("OleneffBank: Operations", 500, 500, 0);
    uiWindowSetMargined(operationWnd, 0);
    uiWindowOnClosing(operationWnd, onClosing1, NULL);
    uiOnShouldQuit(onShouldQuit1, operationWnd);
    uiControlShow(uiControl(operationWnd));

    group = uiNewGroup("Operations");
	uiGroupSetMargined(group, 20);

    hbox = uiNewHorizontalBox();
	uiBoxSetPadded(hbox, 1);
    uiWindowSetChild(operationWnd, uiControl(hbox));
    uiBoxAppend(hbox, uiControl(group), 1);

    entryForm = create_entry_sum();
    uiGroupSetChild(group, uiControl(entryForm));

    vbox = uiNewVerticalBox();
	uiBoxSetPadded(vbox, 1);
	uiGroupSetChild(group, uiControl(vbox));

    uiBoxAppend(vbox, uiControl(entryForm), 0);

    uiControl(hbox);
}

