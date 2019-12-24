#ifndef _HOSTNAME_LINK_H_

#define _HOSTNAME_LINK_H_

#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define OK 0
#define ERROR 1

#define WRONG_FORMAT 200
#define NAME_NOT_SET 201
#define NAME_NOT_GET 202
#define EMPTY_HOSTNAME 203

#define MAX_HOSTNAME_LENGTH 30

int _hostname_(const char *const buffer, char *const hostname);

#endif 
