#include "../include/create_chat_page.h"

static uiBox *chtBox;
static uiEntry *chtEntry;

static void onSend(uiButton *but, void *data)
{
    (void)but;
    (void)data;

    struct passwd *p = getpwuid(getuid());
    time_t now = time(0);
    char *msg = ctime(&now);
    strcat(msg, p->pw_name);
    msg[strlen(msg)] = '\n';
    strcat(msg, uiEntryText(chtEntry));

    uiBox *newBox = uiNewHorizontalBox();
    uiLabel *newLabel = uiNewLabel(msg);

    uiBoxSetPadded(newBox, 1);

    uiBoxAppend(newBox, uiControl(newLabel), 1);
    uiBoxAppend(chtBox, uiControl(newBox), 0);

    msg = ctime(&now);
    strcat(msg, "Bot Anton\n");
    strcat(msg, "Извините! Merge request'ы сегодня больше не принимаем!");

    newBox = uiNewHorizontalBox();
    newLabel = uiNewLabel(msg);

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

    uiButtonOnClicked(sndButton, onSend, NULL);

    uiBoxAppend(conBox, uiControl(sndButton), 1);
    uiBoxAppend(conBox, uiControl(chtEntry), 1);

    uiTabAppend(parentTab, CHAT_TAB_NAME, uiControl(verBox));
}
