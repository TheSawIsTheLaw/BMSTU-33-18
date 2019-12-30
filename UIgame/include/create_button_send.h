#ifndef _CREATE_BUTTON_SEND_H_
#define _CREATE_BUTTON_SEND_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/checkEntryCard.h"
#include "../include/checkEntrySum.h"

#define YES 0
#define NO 1

#define SUM_ERROR 1
#define CARD_ERROR 2
#define OK 0

uiButton *create_button_send(uiWindow *wnd, uiEntry *entry_sum,
                             uiEntry *entry_cardnum, char *amount);

#endif