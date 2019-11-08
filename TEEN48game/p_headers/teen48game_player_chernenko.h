#ifndef _PLAYER_CHERNENKO_
#define _PLAYER_CHERNENKO_

#ifdef LOCAL_BUILD
#include "../../ARRgame/headers/arrgame.h"
#include "../../MATRIXgame/headers/matrixgame.h"
#else
#include <arrgame.h>
#include <matrixgame.h>
#endif

#ifdef VERBOSE
#define dbg(...) printf(__VA_ARGS__)
#else
#define dbg(...) /* */
#endif

#define UNUSED(x) (void)(x)

#define ILLEGAL_MOVE_SCR -10000
#define WIN_MOVE_SCR 10000

#define NOERR 0
#define MEMDEAD -1
#define BROKEN_LEAF -2
#define DEEP_ADD_FAILED -3
#define DEEPEN_FAILED -4

#define EVEN 0
#define UNEVEN 1

#define ILLEGAL 0
#define CORRECT 1

#define IS_LEAF 1
#define IS_NOT_LEAF 0

#define UP 'u'
#define DOWN 'd'
#define LEFT 'l'
#define RIGHT 'r'
#define DEAD_MOVE -1

#define EMPTY_WEIGHT 2.7
#define MAX_WEIGHT 1
#define SM_WEIGHT -0.1
#define MONO_WEIGHT 1
#define DEPTH_WEIGHT 0.1

#define MAX_DEPTH 5

/* quad tree  */
typedef struct {
    double score;
    matrix_t field;
} gtdata;

typedef struct game_tree_node {
    struct game_tree_node *up;
    struct game_tree_node *right;
    struct game_tree_node *down;
    struct game_tree_node *left;
    gtdata data;
} gtnode;

typedef struct game_tree {
    gtnode *root;
    size_t depth;
} gtree;

typedef int (*step_func)(matrix_t *const matrix, const char direction);
typedef void (*walk_func)(gtnode *node, size_t depth);

extern int super_errno;

char teen48game_player_chernenko(matrix_t *matrix, step_func i_step_func);
void print_matrix(matrix_t *matrix, size_t depth);
#endif
