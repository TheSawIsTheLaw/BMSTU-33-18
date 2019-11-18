#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#include "../p_headers/teen48game_player_chernenko.h"

int super_errno = NOERR;
step_func dub_step = NULL;

void no_walk(gtnode *node, size_t depth)
{
    UNUSED(node);
    UNUSED(depth);
}

void init_node(gtnode *node)
{
    node->up = NULL;
    node->right = NULL;
    node->down = NULL;
    node->left = NULL;
    node->data.score = 0;
    node->data.field.rows = 0;
    node->data.field.columns = 0;
    node->data.field.matrix = NULL;
}

static void copy_matrix(matrix_t *dst, matrix_t *src)
{
    for (int j = 0; j < src->rows; j++)
        for (int i = 0; i < src->columns; i++)
            dst->matrix[j][i] = src->matrix[j][i];

    dst->columns = src->columns;
    dst->rows = src->rows;
}

gtnode *gt_create_node(const int field_rows, const int field_cols)
{
    gtnode *new_node;

    void *temp;
    temp = malloc(sizeof(gtnode));
    
    if (temp == NULL) {
        dbg("fail at gt_create_node allocating node of size %zu\n", sizeof(gtnode));
        super_errno = MEMDEAD;
        return NULL;
    }

    init_node(temp);
    new_node = temp;

    int rc;
    rc = matrixgame_create_matrix(&new_node->data.field,
                                  field_rows, field_cols);
    if (rc) {
        dbg("Failed to create matrix in gt_create_node, %ul rows %ul cols\n",
            field_rows, field_cols);
        super_errno = MEMDEAD;
        return NULL;
    }

    return new_node;
}

gtnode *gt_node_from_field(matrix_t ifield)
{
    gtnode *new_node;

    if (!(new_node = gt_create_node(ifield.rows, ifield.columns)))
        return NULL;
    
    copy_matrix(&new_node->data.field, &ifield);
    
    return new_node;
}

gtnode *gt_node_from_parent(gtnode *parent)
{
    gtnode *new_node;

    if (!(new_node = gt_create_node(parent->data.field.rows,
                                    parent->data.field.columns)))
        return NULL;

    copy_matrix(&new_node->data.field, &parent->data.field);
    
    return new_node;
}

gtree gt_create_tree(matrix_t root_field)
{
    gtree out;

    out.depth = 0;

    gtnode *temp = gt_node_from_field(root_field);
    if (!temp)
    {
        dbg("Failed to create a new node in gt_create tree\n");
        return out;
    }
    
    out.root = temp;
    out.depth = 1;

    return out;
}

int is_leaf(gtnode *sample)
{
    if (sample->up == NULL &&   /* check if node is a leaf */
        sample->right == NULL &&
        sample->down == NULL &&
        sample->left == NULL)
        return IS_LEAF;
    else if (sample->up == NULL || /* check if node is broken */
             sample->right == NULL ||
             sample->down == NULL ||
             sample->left == NULL)
    {
        dbg("broken node at %p\n up is %p right is %p down is %p left is %p",
            (void*)sample, (void*)sample->up, (void*)sample->right, (void*)sample->down, (void*)sample->left);
        super_errno = BROKEN_LEAF;
        return IS_LEAF;
    }
    else return IS_NOT_LEAF;
}

#define SHIFT 8
void print_matrix(matrix_t *to_print, size_t depth)
{
    for (int j = 0; j < to_print->rows; j++)
    {
        for (size_t space = 0; space < depth*SHIFT; space++)
            printf(" ");
        
        for (int i = 0; i < to_print->columns; i++)
            printf("%-4d ", to_print->matrix[j][i]);

        putchar('\n');
    }
}

void print_node(gtnode *node, size_t depth)
{
    for (size_t space = 0; space < depth*SHIFT; space++)
        printf(" ");

    printf("Node at depth %zu\n", depth);

    for (size_t space = 0; space < depth*SHIFT; space++)
        printf(" ");

    printf("Score is %lf\n", node->data.score);
    
    print_matrix(&node->data.field, depth);
}

void walk_every_node(gtnode *start, size_t depth, walk_func descend, walk_func ascend)
{
    descend(start, depth);

    if (!is_leaf(start))
    {
        walk_every_node(start->up, depth + 1, descend, ascend);
        walk_every_node(start->right, depth + 1, descend, ascend);
        walk_every_node(start->down, depth + 1, descend, ascend);
        walk_every_node(start->left, depth + 1, descend, ascend);
    }
    
    ascend(start, depth);
}

void if_bigger_assign(double *cur_max, double sample)
{
    if (sample > *cur_max)
        *cur_max = sample;
}

void max_node(gtnode *node, size_t depth)
{
    UNUSED(depth);

    if (is_leaf(node))
        return;
    
    double score = 0;

    if_bigger_assign(&score, node->up->data.score);
    if_bigger_assign(&score, node->right->data.score);
    if_bigger_assign(&score, node->down->data.score);
    if_bigger_assign(&score, node->left->data.score);

    node->data.score += score;
}

void deep_add_all_nodes(gtnode *node, size_t depth)
{
    UNUSED(depth);

    if (!is_leaf(node))
        return;
    
    node->up = gt_node_from_parent(node);
    node->right = gt_node_from_parent(node);
    node->down = gt_node_from_parent(node);
    node->left = gt_node_from_parent(node);

    if (node->up == NULL ||
        node->right == NULL ||
        node->down == NULL ||
        node->left == NULL)
    {
        dbg("Some additions have failed\n");
        super_errno = DEEP_ADD_FAILED;
        return;
    }

    dub_step(&node->up->data.field, UP);
    dub_step(&node->right->data.field, RIGHT);
    dub_step(&node->down->data.field, DOWN);
    dub_step(&node->left->data.field, LEFT);
}

void go_deeper(gtree *tree)
{
    if (tree->root == NULL && tree->depth == 0)
    {
        dbg("No root, can't deepen the tree...\n");
        super_errno = DEEPEN_FAILED;
        return;
    }

    walk_every_node(tree->root, 0, no_walk, deep_add_all_nodes);

    tree->depth += 1;
}


#define IS_OCCUPIED 1
#define IS_NOT_OCCUPIED 0

int get_empty_cells(matrix_t *imatrix)
{
    int count = 0;
    
    for (int j = 0; j < imatrix->rows; j++)
        for (int i = 0; i < imatrix->columns; i++)
            if (imatrix->matrix[j][i] == 0)
                count++;

    return count;
}

int get_max_element(matrix_t *imatrix)
{
    int max = imatrix->matrix[0][0];

    for (int j = 0; j < imatrix->rows; j++)
        for (int i = 0; i < imatrix->columns; i++)
            if (imatrix->matrix[j][i] > max)
                max = imatrix->matrix[j][i];

    return max;
}

static inline float 
fastlog2 (float x)
{
    union { float f; uint32_t i; } vx = { x };
    union { uint32_t i; float f; } mx = { (vx.i & 0x007FFFFF) | 0x3f000000 };
    float y = vx.i;
    y *= 1.1920928955078125e-7f;

    return y - 124.22551499f
        - 1.498030302f * mx.f 
        - 1.72587999f / (0.3520887068f + mx.f);
}

static inline float
fastlog (float x)
{
    return 0.69314718f * fastlog2 (x);
}

static double fabs(double ival)
{
    return ival < (double)0.0 ? -ival : ival;
}

double double_max(double a, double b)
{
    return a > b ? a : b;
}

#define INVALID_INDEX 0
#define VALID_INDEX 1

int is_valid_index(const int j, const int i, matrix_t *const m)
{
    if (j < 0 || j >= m->rows)
        return INVALID_INDEX;
    
    if (i < 0 || i >= m->columns)
        return INVALID_INDEX;

    return VALID_INDEX;
}

double get_sum_neigh_diff(matrix_t *const m)
{
    double sum = 0;

    for (int j = 0; j < m->rows; j++)
    {
        for (int i = 0; i < m->columns; i++)
        {
            if (is_valid_index(j + 1, i, m))
                if (m->matrix[j][i] != 0 && m->matrix[j + 1][i] != 0)
                    sum += fabs(fastlog(m->matrix[j][i])/fastlog(2) -
                                fastlog(m->matrix[j + 1][i])/fastlog(2));
            
            if (is_valid_index(j, i + 1, m))
                if (m->matrix[j][i] != 0 && m->matrix[j][i + 1] != 0)
                    sum += fabs(fastlog(m->matrix[j][i])/fastlog(2) -
                                fastlog(m->matrix[j][i + 1])/fastlog(2));
        }
    }

    return sum;
}

int is_occupied(int val)
{
    return val != 0;
}

double monotonicity(matrix_t *m)
{
    double totals[4] = {0, 0, 0, 0};

    for (int j = 0; j < m->columns; j++)
    {
        for (int i = 0; i < m->rows - 1; i++)
        {
            double curr = 0;
            double next = 0;

            if (m->matrix[i][j] != 0)
                curr = fastlog(m->matrix[i][j])/fastlog(2);
            
            if (m->matrix[i + 1][j] != 0)
                next = fastlog(m->matrix[i + 1][j])/fastlog(2);

            if (curr > next)
                totals[0] += next - curr;
            else if (next > curr)
                totals[1] += curr - next;
        }
    }

    for (int j = 0; j < m->rows; j++)
    {
        for (int i = 0; i < m->columns - 1; i++)
        {
            double curr = 0;
            double next = 0;

            if (m->matrix[j][i] != 0)
                curr = fastlog(m->matrix[j][i])/fastlog(2);

            if (m->matrix[j][i + 1] != 0)
                next = fastlog(m->matrix[j][i +1])/fastlog(2);

            if (curr > next)
                totals[2] += next - curr;
            else if (next > curr)
                totals[3] += curr - next;
        }
    }

    dbg("totals are %lf %lf %lf %lf\n", totals[0], totals[1], totals[2], totals[3]);

    return double_max(totals[0], totals[1]) + double_max(totals[2], totals[3]);
}

void calc_node_score(gtnode *node, size_t depth)
{
    UNUSED(depth);
    
    double result = 0;

    double empty = fastlog(get_empty_cells(&node->data.field)) * EMPTY_WEIGHT;
    double max = fastlog(get_max_element(&node->data.field))/fastlog(2) * MAX_WEIGHT;
    double smooth = get_sum_neigh_diff(&node->data.field) * SM_WEIGHT;
    double mono = monotonicity(&node->data.field) * MONO_WEIGHT;
    
    double depth_pen = -(double)depth * DEPTH_WEIGHT;

    dbg("composing empty %lf max %lf smooth %lf mono %lf \n", empty, max, smooth, mono);

    result = empty + max + smooth + mono + depth_pen;
    
    node->data.score = result;
}

void calc_leaf_score(gtnode *node, size_t depth)
{
    if (is_leaf(node))
        calc_node_score(node, depth);
}

void calc_scores(gtree tree)
{
    walk_every_node(tree.root, 0, calc_node_score, no_walk);
}

#define UPI 0
#define RIGHTI 1
#define DOWNI 2
#define LEFTI 3

int find_max(double *results, const int count)
{
    double max_val = results[0];
    int max = 0;
        
    for (int i = 0; i < count; i++)
        if (results[i] > max_val)
        {
            max = i;
            max_val = results[max];
        }

    return max;
}

int compare_matrixes(matrix_t *const a, matrix_t *const b)
{
    for (int j = 0; j < a->rows; j++)
        for (int i = 0; i < a->columns; i++)
            if (a->matrix[j][i] != b->matrix[j][i])
                return UNEVEN;

    return EVEN;
}

int illegal_move(gtnode *prev, gtnode *next)
{
    if (compare_matrixes(&prev->data.field, &next->data.field))
        return ILLEGAL;

    return CORRECT;
}

char get_final_move(gtree tree)
{
    double results[4];
    int illegals[4] = {0, 0, 0, 0};

    results[UPI] = tree.root->up->data.score;
    results[RIGHTI] = tree.root->right->data.score;
    results[DOWNI] = tree.root->down->data.score;
    results[LEFTI] = tree.root->left->data.score;
    
    if (illegal_move(tree.root, tree.root->up))
        results[UPI] = ILLEGAL_MOVE_SCR, illegals[UPI] = 1;
    
    if (illegal_move(tree.root, tree.root->right))
        results[RIGHTI] = ILLEGAL_MOVE_SCR, illegals[RIGHTI] = 1;
    
    if (illegal_move(tree.root, tree.root->down))
        results[DOWNI] = ILLEGAL_MOVE_SCR, illegals[DOWNI] = 1;
    
    if (illegal_move(tree.root, tree.root->left))
        results[LEFTI] = ILLEGAL_MOVE_SCR, illegals[LEFTI] = 1;

    int maxi = find_max(results, 4);

    switch (maxi) {
        case UPI:
            if (illegals[UPI])
                return DEAD_MOVE;
            return UP;
        case RIGHTI:
            if (illegals[RIGHTI])
                return DEAD_MOVE;
            return RIGHT;
        case DOWNI:
            if (illegals[DOWNI])
                return DEAD_MOVE;
            return DOWN;
        case LEFTI:
            if (illegals[LEFTI])
                return DEAD_MOVE;
            return LEFT;
    }

    return DEAD_MOVE;
}

void kill_matrix(gtnode *node, size_t depth)
{
    UNUSED(depth);
    matrixgame_free_matrix(&node->data.field);
}

void free_all_fields(gtree tree)
{
    walk_every_node(tree.root, 0, kill_matrix, no_walk);
}

void kill_node(gtnode *node, size_t depth)
{
    UNUSED(depth);
    free(node);
}

void free_tree(gtree tree)
{
    free_all_fields(tree);
    walk_every_node(tree.root, 0, no_walk, kill_node);
}

char teen48game_player_chernenko(matrix_t *matrix, int (*to_step)(matrix_t *const matrix, const char direction))
{
    super_errno = NOERR;
    dub_step = to_step;

    gtree working_tree;
    working_tree = gt_create_tree(*matrix);

    dbg("Working tree started\n");
    dbg("working depth is %zu\n", working_tree.depth);

    while (working_tree.depth != MAX_DEPTH) {
        go_deeper(&working_tree);
    }

    calc_scores(working_tree);

    walk_every_node(working_tree.root, 0, no_walk, max_node);
    
    dbg("After calc scores\n");
#ifdef VERBOSE
    walk_every_node(working_tree.root, 0, print_node, no_walk);
#endif

    char final_move = get_final_move(working_tree);

    free_tree(working_tree);

    return final_move;
}
