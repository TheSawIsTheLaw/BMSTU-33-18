#ifndef __TTY_LINK_H__
#define __TTY_LINK_H__

#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>

#define TTY_STDIN_NOTTY 1
#define TTY_FAILURE     2
#define EXIT_SUCCESS    0


#define PROGRAM_NAME "tty"

static bool silent;

static struct option const longopts[] =
{
  {"silent", no_argument, NULL, 's'},
  {"quiet", no_argument, NULL, 's'},
  {NULL, 0, NULL, 0}
};

static void usage();

int tty(int argc, char **argv);

#endif // __TTY_LINK_H__
