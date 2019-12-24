#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ui.h"
#include "../include/create_acc_wnd.h"

#define WND_WIDTH 1440
#define WND_HEIGHT 1025

// Окна
uiWindow *wndMain;

// Кнопки
uiButton *btnCreateAccount;
uiButton *btnCreateService;
uiButton *btnCreateChat;

// Ентри
uiEntry *entFindMain;

// Группа элементов
uiBox *bxMain;

// Штатное закрытие окна
static int onClosing(uiWindow *w, void *data)
{
    uiControlDestroy(uiControl(wndMain));
    uiQuit();
    return EXIT_SUCCESS;
}

// Вынужденное закрытие окна
static int onShouldQuit(void *data)
{
    uiControlDestroy(uiControl(wndMain));
    return EXIT_FAILURE;
}

int main(void)
{
    uiInitOptions options;
    const char *err;

    memset(&options, 0, sizeof(uiInitOptions));
    err = uiInit(&options);
    if (err != NULL)
    {
        fprintf(stderr, "Error initializing libui: %s", err);
        uiFreeInitError(err);
        return EXIT_FAILURE;
    }

    wndMain = uiNewWindow("OleneffBank", WND_WIDTH, WND_HEIGHT, 0);
    uiWindowSetMargined(wndMain, 1); // 2 параметр -  пкм меню (0, 1)

    uiWindowOnClosing(wndMain, onClosing, NULL);
    uiOnShouldQuit(onShouldQuit, wndMain);

    btnCreateAccount = createAccBtn();

    bxMain = uiNewHorizontalBox();
    uiBoxSetPadded(bxMain, 1);
    uiWindowSetChild(wndMain, uiControl(bxMain));
    /* Добавить вызов ещё 2х кнопок и таблицы */

    uiBoxAppend(bxMain, uiControl(btnCreateAccount), 0);

    uiControlShow(uiControl(wndMain));
    uiMain();
    return EXIT_SUCCESS;
}
