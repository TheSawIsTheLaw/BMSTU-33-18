#include "../include/kill_wnd_btn.h"

static void killAccWnd(uiButton *b, void *wnd)
{
    uiControlDestroy(uiControl(wnd));
}

uiButton *killWndBtn(uiWindow *wnd)
{
	uiButton *btnKill = uiNewButton("Назад");
    uiButtonOnClicked(btnKill, killAccWnd, wnd);

    return btnKill;
}
