#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ui.h"

#define WND_WIDTH 1000
#define WND_HEIGHT 800

// Окна
uiWindow *wndMain;
uiWindow *wndAccount;
uiWindow *wndService;
uiWindow *wndChat;
uiWindow *wndCards;

// Кнопки
uiButton *btnKillAccount;
uiButton *btnKillService;
uiButton *btnKillChat;
uiButton *btnKillCards;
uiButton *btnSendMoney;

// Лейблы
uiLabel *lblChat;

// Ентри
uiEntry *entChat;
uiEntry *entCardInfo;
uiEntry *entFindMain;
uiEntry *entFindService;

// Картинки
uiImage *imgMain;
uiImage *imgAccount;
uiImage *imgService;
uiImage *imgChat;
uiImage *imgCards;

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

//static int account_wnd

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

    uiControlShow(uiControl(wndMain));
    uiMain();
    return EXIT_SUCCESS;
}

