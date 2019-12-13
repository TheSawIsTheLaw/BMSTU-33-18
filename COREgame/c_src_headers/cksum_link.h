#ifndef __CKSUM_LINK_H__
#define __CKSUM_LINK_H__

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

uint32_t cksum(FILE *fp, const char *filename);

#endif