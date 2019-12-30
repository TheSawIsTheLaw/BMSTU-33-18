#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/ui.h"
#include "../include/create_main_page.h"
#include "../include/create_service_page.h"
#include "../include/create_chat_page.h"
#include "../include/create_account_page.h"

#define WND_WIDTH 1025
#define WND_HEIGHT 725

// Окна
uiWindow *wndMain;

// Tab
uiTab *mainTab;

// Entry
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

    bxMain = uiNewHorizontalBox();
    uiBoxSetPadded(bxMain, 1);
    uiWindowSetChild(wndMain, uiControl(bxMain));

    mainTab = uiNewTab();
    uiBoxAppend(bxMain, uiControl(mainTab), 1);
    createMainPage(mainTab);
    createServicePage(mainTab, wndMain);
    createChatPage(mainTab);
    createAccountPage(mainTab);


    uiControlShow(uiControl(wndMain));
    uiMain();
    return EXIT_SUCCESS;
}
