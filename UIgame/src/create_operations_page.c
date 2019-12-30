#include "../include/create_operations_page.h"

uiGroup *group;
uiEntry *entrySum, *entryCardNum, *entryTelNum;
uiBox *hbox, *vbox;
uiWindow *operationWnd;
uiLabel *labelExp;

int onClosing(uiWindow *w, void *data)
{
    uiControlDestroy(uiControl(w));
    return 0;
}

// Вынужденное закрытие окна
int onShouldQuit(void *data)
{
    uiControlDestroy(uiControl(data));
    return 1;
}

void createOperationsPage(char *const balanse)
{
    // настройки окна
    operationWnd = uiNewWindow("OleneffBank: Операции с картами", 500, 500, 0);
    uiWindowSetMargined(operationWnd, 0);
    uiWindowOnClosing(operationWnd, onClosing, NULL);
    uiOnShouldQuit(onShouldQuit, operationWnd);
    uiControlShow(uiControl(operationWnd));

    // создание группы
    group = uiNewGroup("");
	uiGroupSetMargined(group, 20);

    // создаем бокс для хранении групы
    hbox = uiNewHorizontalBox();
	uiBoxSetPadded(hbox, 1);
    uiWindowSetChild(operationWnd, uiControl(hbox));
    uiBoxAppend(hbox, uiControl(group), 1);

    // создание label
    labelExp = create_label_MExpencces();

    // создание entry
    entrySum = create_entry_sum();
    entryCardNum = create_entry_cardnum();
    entryTelNum = create_entry_telnum();

    // создаем бокс для хранения виджитов 
    vbox = uiNewVerticalBox();
	uiBoxSetPadded(vbox, 1);

    // добавляем виджеты в бокс
    uiBoxAppend(vbox, uiControl(labelExp), 0);
    uiBoxAppend(vbox, uiControl(entryTelNum), 0);
    uiBoxAppend(vbox, uiControl(entrySum), 0);
    uiBoxAppend(vbox, uiControl(entryCardNum), 0);

    // добавляем бокс в группу
	uiGroupSetChild(group, uiControl(vbox));

    // отображаем бокс с группой
    uiControl(hbox);
}

