#ifndef __TTY_LINK_H__
#define __TTY_LINK_H__

#include <stdio.h>
#include <getopt.h>

#include <unistd.h>

#define TTY_STDIN_NOTTY 1
#define TTY_FAILURE     2

#define PROGRAM_NAME "tty"

static bool silent;

static struct option const longopts[] =
{
  {"silent", no_argument, NULL, 's'},
  {"quiet", no_argument, NULL, 's'},
  {GETOPT_HELP_OPTION_DECL},
  {GETOPT_VERSION_OPTION_DECL},
  {NULL, 0, NULL, 0}
}

static void usage();

int tty(int argc, char **argv);

#endif // __TTY_LINK_H__
