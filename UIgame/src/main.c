#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/ui.h"

#define WIDTH 900
#define HEIGHT 500

// Окно формы
uiWindow *wndMain;

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

    wndMain = uiNewWindow("OleneffBank", WIDTH, HEIGHT, 0);
    uiWindowSetMargined(wndMain, 1); // 2 параметр -  пкм меню (0, 1)

    uiWindowOnClosing(wndMain, onClosing, NULL);
    uiOnShouldQuit(onShouldQuit, wndMain);

    uiControlShow(uiControl(wndMain));
    uiMain();
    return EXIT_SUCCESS;
}

