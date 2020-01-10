#include <string.h>

#include "../include/create_chat_page.h"

#define MSG_COUNT 10
#define MSG_LEN 256

static uiBox *chtBox;
static uiBox *msgBoxes[MSG_COUNT] = {0};
static char msgBuffer[MSG_COUNT][MSG_LEN] = {{0}};
int msgCount = 0;
static uiLabel *msgLabels[MSG_COUNT] = {0};

static uiEntry *chtEntry;

#define INVERSE(x) MSG_COUNT - x - 1

void msgMovUp()
{
    for (int i = 0; i < MSG_COUNT; i++)
        memmove(msgBuffer[i], msgBuffer[i + 1], MSG_LEN);
}

void msgRedraw()
{
    for (int i = 0; i < MSG_COUNT; i++)
        uiLabelSetText(msgLabels[i], msgBuffer[i]);
}

void msgAppend(char *msg)
{
    msgMovUp();    

    memmove(msgBuffer[MSG_COUNT - 1], msg, MSG_LEN);
    
    msgRedraw();
}

char *msgCreate(char *sndr, char *txt)
{
    struct passwd *p = getpwuid(getuid());
    time_t now = time(0);
    char *msg = ctime(&now);
    
    strcat(msg, p->pw_name);
    msg[strlen(msg)] = '\n';

    msg = ctime(&now);
    strcat(msg, sndr);
    strcat(msg, txt);

    return msg;
}

static void onSend(uiButton *but, void *data)
{
    (void)but;
    (void)data;
    
    msgAppend(msgCreate("Bot Alexey\n", strcat(uiEntryText(chtEntry), "\n")));
    msgAppend(msgCreate("Bot Anton\n", "MR умер\n"));
}

static void newBoxes(uiGrid *chtGrid)
{
    for (int i = 0; i < MSG_COUNT; i++)
    {
        int left = i % 2 == 0 ? 1 : 0;

        msgBoxes[i] = uiNewHorizontalBox();
        msgLabels[i] = uiNewLabel("");

        uiBoxAppend(msgBoxes[i], uiControl(msgLabels[i]), 1);
        uiGridAppend(chtGrid, uiControl(msgBoxes[i]), left, i, 1, 1,
                     1, uiAlignStart, 1, uiAlignCenter);
    }
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

    uiButton *sndButton = uiNewButton("Отправить");
    chtEntry = uiNewEntry();

    uiButtonOnClicked(sndButton, onSend, NULL);

    uiGrid *newGrid = uiNewGrid();

    newBoxes(newGrid);

    uiBoxAppend(conBox, uiControl(chtEntry), 1);
    uiBoxAppend(conBox, uiControl(sndButton), 1);
    uiBoxAppend(chtBox, uiControl(newGrid), 1);

    uiTabAppend(parentTab, CHAT_TAB_NAME, uiControl(verBox));
}
