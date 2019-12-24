#include "../include/create_acc_wnd.h"
#include "../include/kill_wnd_btn.h"

#define WND_WIDTH 1440
#define WND_HEIGHT 1025

static int onClosing(uiWindow *w, void *data)
{
    uiControlDestroy(uiControl(w));
    return 0;
}

static void createAccWnd(uiButton *bt, void *data)
{
    uiWindow *wndAcc;
	uiBox *bxAcc;
    uiButton *btnKill;

	wndAcc = uiNewWindow("OleneffBank: Account", WND_WIDTH, WND_HEIGHT, 0);
    btnKill = killWndBtn(wndAcc);
	bxAcc = uiNewHorizontalBox();

	uiBoxAppend(bxAcc, uiControl(btnKill), 0);
	uiBoxSetPadded(bxAcc, 0);
	uiWindowSetChild(wndAcc, uiControl(bxAcc));

	uiWindowSetMargined(wndAcc, 0);
    uiWindowOnClosing(wndAcc, onClosing, NULL);
	uiControlShow(uiControl(wndAcc));
}

uiButton *createAccBtn(void)
{
    uiButton *btn = uiNewButton("Аккаунт");
    uiButtonOnClicked(btn, createAccWnd, NULL);

    return btn;
}
