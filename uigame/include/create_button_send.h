#ifndef _CREATE_BUTTON_SEND_H_
#define _CREATE_BUTTON_SEND_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "checkEntryCard.h"
#include "checkEntrySum.h"
#include "enoughMoney.h"


#define YES 0
#define NO 1

#define SUM_ERROR 1
#define CARD_ERROR 2
#define OK 0

uiButton *send_button;

uiButton *create_button_send();

int check_entrys(uiWindow *operationWnd, void *entrySum, void *entryCardNum, char *curBalance);

#endif
