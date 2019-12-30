#ifndef _CREATE_CHAT_PAGE_H_
#define _CREATE_CHAT_PAGE_H_

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include "ui.h"

#define CHAT_TAB_NAME "Чат"

void createChatPage(uiTab *parentTab);

#endif
