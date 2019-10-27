#ifndef _CREATE_TITANICGAME_H_

#define _CREATE_TITANICGAME_H_

#include "../headers/struct.h"
#include <stdlib.h>

node* сreate(void (*func)(passenger));

// Errors
#define MEM_ALLOC_ERR 500

#endif