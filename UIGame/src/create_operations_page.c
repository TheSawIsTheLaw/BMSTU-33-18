#include "../include/create_operations_page.h"

uiGroup *group;
uiEntry *entrySum, *entryCardNum, *entryTelNum;
uiButton *send_button;
uiBox *hbox, *vbox;
uiWindow *operationWnd;
uiLabel *labelExp;

char curBalance[50] = { 0 };

int onClosing(uiWindow *w, void *data) {
    uiControlDestroy(uiControl(w));
    return EXIT_ONE;
}

// Вынужденное закрытие окна
int onShouldQuit(void *data) {
    uiControlDestroy(uiControl(operationWnd));
    return EXIT_TWO;
}

// Переправление в проверяющую функцию
void getInfo()
{
    int check = 0;

    check = check_entrys(operationWnd, uiEntryText(entrySum), uiEntryText(entryCardNum), curBalance);
    if (!check)
    {
        onClosing(operationWnd, operationWnd);
    }
}

void createOperationsPage(char *const balance) 
{
    // настройки окна
    operationWnd = uiNewWindow("OleneffBank: Операции с картами", 500, 500, 0);
    uiWindowSetMargined(operationWnd, 0);
    uiWindowOnClosing(operationWnd, onClosing, NULL);
    uiOnShouldQuit(onShouldQuit, operationWnd);
    uiControlShow(uiControl(operationWnd));

    strcpy(curBalance, balance);

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
    send_button = create_button_send();

    // создаем бокс для хранения виджитов
    vbox = uiNewVerticalBox();
    uiBoxSetPadded(vbox, 1);

    // добавляем виджеты в бокс
    uiBoxAppend(vbox, uiControl(labelExp), 0);
    uiBoxAppend(vbox, uiControl(entryTelNum), 0);
    uiBoxAppend(vbox, uiControl(entrySum), 0);
    uiBoxAppend(vbox, uiControl(entryCardNum), 0);
    uiBoxAppend(vbox, uiControl(send_button), 0);
    uiButtonOnClicked(send_button, getInfo, send_button);

    // добавляем бокс в группу
    uiGroupSetChild(group, uiControl(vbox));

    // отображаем бокс с группой
    uiControl(hbox);
}
