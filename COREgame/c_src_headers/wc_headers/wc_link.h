#ifndef WC_LINK_H
#define WC_LINK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>
#include <sys/types.h>
#include <wchar.h>
#include <wctype.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stddef.h>
#include <ctype.h>
#include <sys/stat.h>

#define READ_ERROR ((size_t) -1)

/* Size of atomic reads. */
#define BUFFER_SIZE (16 * 1024)

/* Cumulative number of lines, words, chars and bytes in all files so far.
   max_line_length is the maximum over all files processed so far.*/
static long long total_lines;
static long long total_words;
static long long total_chars;
static long long total_bytes;
static long long max_line_length;

/* Which counts to print. */
static bool print_lines, print_words, print_chars, print_bytes;
static bool print_linelength;

static struct option const longopts[] =
{
    {"bytes", no_argument, NULL, 'c'},
    {"chars", no_argument, NULL, 'm'},
    {"lines", no_argument, NULL, 'l'},
    {"words", no_argument, NULL, 'w'},
    {"max-line-length", no_argument, NULL, 'L'}
};

int wc (int argc, char **argv);
static bool wc_file (char const *file);
static bool do_wc (int fd, char const *file_x, off_t current_pos);
static void write_counts (long long lines, long long words, long long chars,
    long long bytes, long long linelength, const char *file);
static int isnbspace (int c);
int iswnbspace (wint_t wc);
#endif // WC_H
