#include "../include/create_chat_page.h"

static uiBox *chtBox;
static uiEntry *chtEntry;

static void on_anime_press(uiButton *but, void *data)
{
    (void)but;
    (void)data;
    
    uiBox *newBox = uiNewHorizontalBox();
    uiLabel *newLabel = uiNewLabel(uiEntryText(chtEntry));

    uiBoxSetPadded(newBox, 1);

    uiBoxAppend(newBox, uiControl(newLabel), 1);
    uiBoxAppend(chtBox, uiControl(newBox), 0);
}

void createChatPage(uiTab *parentTab)
{
    uiBox *verBox = uiNewVerticalBox();
    uiBox *conBox = uiNewHorizontalBox();
    chtBox = uiNewVerticalBox();

    uiBoxSetPadded(verBox, 1);
    uiBoxSetPadded(conBox, 1);
    uiBoxSetPadded(chtBox, 1);

    uiBoxAppend(verBox, uiControl(chtBox), 1);
    uiBoxAppend(verBox, uiControl(conBox), 0);

    uiButton *sndButton = uiNewButton("Send");
    chtEntry = uiNewEntry();

    uiButtonOnClicked(sndButton, on_anime_press, NULL);

    uiBoxAppend(conBox, uiControl(sndButton), 1);
    uiBoxAppend(conBox, uiControl(chtEntry), 1);
    
    uiTabAppend(parentTab, CHAT_TAB_NAME, uiControl(verBox));
}
